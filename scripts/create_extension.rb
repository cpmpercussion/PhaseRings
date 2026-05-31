#!/usr/bin/env ruby
# Create the PhaseRingsAUv3 app-extension target (the AUv3 plugin), link it
# against PhaseRingsKit, and embed it in the app. The extension's principal
# class is PhaseRingsAUViewController (AUAudioUnitFactory + AUViewController).
# See auv3-plan.md (Phase E).
#
# One-shot: bails if PhaseRingsAUv3 already exists.
#
#   ruby scripts/create_extension.rb

require 'xcodeproj'

PROJECT = 'PhaseRings.xcodeproj'
EXT = 'PhaseRingsAUv3'
APP_BUNDLE_ID = 'au.com.charlesmartin.PhaseRings'
TEAM = 'EDH387FRHA'

project = Xcodeproj::Project.open(PROJECT)
app = project.targets.find { |t| t.name == 'PhaseRings' }
fw  = project.targets.find { |t| t.name == 'PhaseRingsKit' }
raise 'app/framework targets missing' unless app && fw
abort "#{EXT} already exists." if project.targets.any? { |t| t.name == EXT }

ext = project.new_target(:app_extension, EXT, :ios, '14.0')

ext.build_configurations.each do |cfg|
  s = cfg.build_settings
  s['PRODUCT_NAME'] = '$(TARGET_NAME)'
  s['PRODUCT_BUNDLE_IDENTIFIER'] = "#{APP_BUNDLE_ID}.AUv3"
  s['INFOPLIST_FILE'] = "#{EXT}/Info.plist"
  s['GENERATE_INFOPLIST_FILE'] = 'NO'
  s['SKIP_INSTALL'] = 'YES'
  s['TARGETED_DEVICE_FAMILY'] = '1,2'
  s['MARKETING_VERSION'] = '2.0'
  s['CURRENT_PROJECT_VERSION'] = '1'
  s['DEVELOPMENT_TEAM'] = TEAM
  s['CLANG_ENABLE_MODULES'] = 'YES'
  s['LD_RUNPATH_SEARCH_PATHS'] = ['$(inherited)', '@executable_path/Frameworks',
                                  '@executable_path/../../Frameworks']
end

# Group + source/header/plist references.
group = project.main_group.find_subpath(EXT, true)
group.set_source_tree('SOURCE_ROOT')
group.set_path(EXT)
# References are relative to the group (whose path is already EXT) — basenames.
vc_m = group.new_reference('PhaseRingsAUViewController.m')
group.new_reference('PhaseRingsAUViewController.h')
group.new_reference('Info.plist')
ext.source_build_phase.add_file_reference(vc_m)

# Link system frameworks + the shared framework.
ext.add_system_frameworks(%w[CoreAudioKit AudioToolbox AVFoundation UIKit Foundation])
ext.frameworks_build_phase.add_file_reference(fw.product_reference)
ext.add_dependency(fw)

# App depends on + embeds the extension under PlugIns.
app.add_dependency(ext)
embed = app.copy_files_build_phases.find { |ph| ph.symbol_dst_subfolder_spec == :plug_ins }
unless embed
  embed = app.new_copy_files_build_phase('Embed App Extensions')
  embed.symbol_dst_subfolder_spec = :plug_ins
end
bf = embed.add_file_reference(ext.product_reference)
# CodeSignOnCopy is required: exportArchive re-signs the app wrapper with the
# distribution identity and must re-sign the nested .appex too. Without it the
# appex keeps its stale build-time signature and export fails with exit 70.
bf.settings = { 'ATTRIBUTES' => ['CodeSignOnCopy', 'RemoveHeadersOnCopy'] }

project.save
puts "Created #{EXT}, linked PhaseRingsKit, embedded in app."
