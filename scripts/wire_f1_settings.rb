#!/usr/bin/env ruby
# Issue #23 Phase F.1: add the settings model / store / composition-factory
# sources to the right targets and expose the Kit headers publicly.
#
#   PhaseRingsKit (framework): PRSettings, PRSettingsStore, PRCompositionFactory,
#                              PRSettingsModel.swift   (+ public headers)
#   PhaseRings    (app):       PRUserDefaultsStore
#
# Also removes the retired Phase F.0 smoke test (PRSwiftSmokeTest.swift).
#
# Idempotent. Run from repo root:
#   ruby scripts/wire_f1_settings.rb

require 'xcodeproj'

PROJECT_PATH = 'PhaseRings.xcodeproj'
project = Xcodeproj::Project.open(PROJECT_PATH)
kit = project.targets.find { |t| t.name == 'PhaseRingsKit' }
app = project.targets.find { |t| t.name == 'PhaseRings' }
raise 'targets not found' unless kit && app

# Group the new sources live in (same as the other instrument controllers).
anchor = project.files.find { |f| f.display_name == 'InstrumentViewController.m' }
group  = anchor ? anchor.parent : project.main_group

def file_ref(project, group, path)
  existing = project.files.find { |f| f.path && f.path.end_with?(File.basename(path)) }
  return existing if existing
  group.new_file(path)
end

def add_source(target, ref)
  unless target.source_build_phase.files_references.include?(ref)
    target.add_file_references([ref])
  end
end

def add_public_header(target, ref)
  bf = target.headers_build_phase.files.find { |f| f.file_ref == ref }
  bf ||= target.headers_build_phase.add_file_reference(ref)
  bf.settings = { 'ATTRIBUTES' => ['Public'] }
end

# --- remove retired smoke test -------------------------------------------------
project.files.select { |f| f.display_name == 'PRSwiftSmokeTest.swift' }.each do |ref|
  project.targets.each do |t|
    t.source_build_phase.files.each { |bf| bf.remove_from_project if bf.file_ref == ref }
  end
  ref.remove_from_project
  puts 'Removed PRSwiftSmokeTest.swift'
end

# --- Kit: public headers -------------------------------------------------------
%w[PhaseRings/PRSettings.h PhaseRings/PRSettingsStore.h PhaseRings/PRCompositionFactory.h].each do |p|
  ref = file_ref(project, group, p)
  add_public_header(kit, ref)
  puts "Kit public header: #{File.basename(p)}"
end

# --- Kit: compiled sources -----------------------------------------------------
%w[PhaseRings/PRSettings.m PhaseRings/PRCompositionFactory.m PhaseRings/PRSettingsModel.swift].each do |p|
  ref = file_ref(project, group, p)
  add_source(kit, ref)
  puts "Kit source: #{File.basename(p)}"
end

# --- App: PRUserDefaultsStore --------------------------------------------------
app_h = file_ref(project, group, 'PhaseRings/PRUserDefaultsStore.h')
app_m = file_ref(project, group, 'PhaseRings/PRUserDefaultsStore.m')
add_source(app, app_m)
puts 'App source: PRUserDefaultsStore.m (+ header ref)'

project.save
puts "Saved #{PROJECT_PATH}"
