#!/usr/bin/env ruby
# Create the PhaseRingsKit embedded framework target and move the
# host-agnostic Heavy DSP core into it, shared by the app (and later the
# AUv3 extension). See auv3-plan.md (Phase A).
#
# Moves into the framework:
#   - HeavyCore.{h,mm}  (HeavyCore.h public; PhaseRingsKit.h umbrella public)
#   - PhaseRings/Heavy/* sources (the 34 Heavy runtime/context .c/.cpp files)
#   - the 6 SoundScraper .wav samples (resources)
# Removes those from the app target so there are no duplicate symbols /
# resources, then links + embeds the framework in the app.
#
# Idempotent-ish: bails if PhaseRingsKit already exists.
#
#   ruby scripts/create_framework.rb

require 'xcodeproj'

PROJECT_PATH = 'PhaseRings.xcodeproj'
APP_NAME = 'PhaseRings'
FW_NAME  = 'PhaseRingsKit'

project = Xcodeproj::Project.open(PROJECT_PATH)
app = project.targets.find { |t| t.name == APP_NAME }
raise "app target #{APP_NAME} not found" unless app

if project.targets.any? { |t| t.name == FW_NAME }
  abort "#{FW_NAME} already exists — nothing to do."
end

# --- 1. Create the framework target -----------------------------------------
fw = project.new_target(:framework, FW_NAME, :ios, '14.0')

fw.build_configurations.each do |c|
  s = c.build_settings
  s['PRODUCT_BUNDLE_IDENTIFIER'] = 'au.com.charlesmartin.PhaseRingsKit'
  # Required for distribution: exportArchive re-signs the embedded framework
  # per-target and can't resolve a signing identity without a team, which fails
  # every export method with exit 70. Match the app/extension team.
  s['DEVELOPMENT_TEAM'] = 'EDH387FRHA'
  s['DEFINES_MODULE'] = 'YES'
  s['DYLIB_INSTALL_NAME_BASE'] = '@rpath'
  s['SKIP_INSTALL'] = 'YES'
  s['GENERATE_INFOPLIST_FILE'] = 'YES'
  s['CURRENT_PROJECT_VERSION'] = '1'
  s['MARKETING_VERSION'] = '2.0'
  s['CLANG_ENABLE_MODULES'] = 'YES'
  # Match the app: shared/ on the header path; the project headermap resolves
  # the per-context Heavy_*.hpp imports.
  s['HEADER_SEARCH_PATHS'] = ['$(inherited)', '$(SRCROOT)/PhaseRings/Heavy/shared']
  s['LD_RUNPATH_SEARCH_PATHS'] = ['$(inherited)', '@executable_path/Frameworks', '@loader_path/Frameworks']
end

# HeavyCore.mm uses AVFoundation (sample decode) + AudioToolbox; autolinking
# doesn't fire for the framework target, so link them explicitly.
fw.add_system_frameworks(%w[AVFoundation AudioToolbox Foundation])

# --- 2. Move file references from app → framework ---------------------------
def move_sources(from_target, to_target, predicate)
  moved = []
  from_target.source_build_phase.files.dup.each do |bf|
    ref = bf.file_ref
    next unless ref && predicate.call(ref)
    bf.remove_from_project
    to_target.source_build_phase.add_file_reference(ref)
    moved << ref.display_name
  end
  moved
end

def move_resources(from_target, to_target, predicate)
  moved = []
  from_target.resources_build_phase.files.dup.each do |bf|
    ref = bf.file_ref
    next unless ref && predicate.call(ref)
    bf.remove_from_project
    to_target.resources_build_phase.add_file_reference(ref)
    moved << ref.display_name
  end
  moved
end

# Heavy runtime/context sources + HeavyCore.mm.
heavy = move_sources(app, fw, ->(ref) {
  path = ref.real_path.to_s
  path.include?('/Heavy/') || ref.display_name == 'HeavyCore.mm'
})
puts "Moved #{heavy.size} sources into #{FW_NAME}."

# The 6 SoundScraper samples.
wavs = move_resources(app, fw, ->(ref) { ref.display_name.end_with?('.wav') })
puts "Moved #{wavs.size} .wav resources into #{FW_NAME}: #{wavs.sort.join(', ')}"

# --- 3. Public headers (HeavyCore.h + umbrella) -----------------------------
def file_ref_by_name(project, name)
  project.files.find { |f| f.display_name == name }
end

heavycore_h = file_ref_by_name(project, 'HeavyCore.h')
raise 'HeavyCore.h ref missing' unless heavycore_h

# Create the umbrella header reference next to HeavyCore.h if absent.
umbrella = file_ref_by_name(project, 'PhaseRingsKit.h')
unless umbrella
  umbrella = heavycore_h.parent.new_reference('PhaseRings/PhaseRingsKit.h')
end

[umbrella, heavycore_h].each do |ref|
  bf = fw.headers_build_phase.add_file_reference(ref)
  bf.settings = { 'ATTRIBUTES' => ['Public'] }
end
puts 'Added HeavyCore.h + PhaseRingsKit.h as public headers.'

# --- 4. Link + embed the framework in the app -------------------------------
app.add_dependency(fw)
app.frameworks_build_phase.add_file_reference(fw.product_reference)

# This project's pods are static, so the app had no LD_RUNPATH and dyld can't
# find an embedded @rpath framework on device ("no LC_RPATH's found"). Add the
# standard app framework search path.
app.build_configurations.each do |c|
  paths = Array(c.build_settings['LD_RUNPATH_SEARCH_PATHS'])
  paths = ['$(inherited)'] if paths.empty?
  paths << '@executable_path/Frameworks' unless paths.include?('@executable_path/Frameworks')
  c.build_settings['LD_RUNPATH_SEARCH_PATHS'] = paths
end

embed = app.copy_files_build_phases.find { |p| p.name == 'Embed Frameworks' }
unless embed
  embed = app.new_copy_files_build_phase('Embed Frameworks')
  embed.symbol_dst_subfolder_spec = :frameworks
end
bf = embed.add_file_reference(fw.product_reference)
bf.settings = { 'ATTRIBUTES' => ['CodeSignOnCopy', 'RemoveHeadersOnCopy'] }
puts 'Linked + embedded framework in app target.'

project.save
puts 'Saved.'
