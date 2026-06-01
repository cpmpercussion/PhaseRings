#!/usr/bin/env ruby
# Issue #23 Phase F.3: add the in-memory settings store to the PhaseRingsKit
# framework target. The expanded InstrumentViewController (setup stepper +
# settings gear, composition driven by PRSettings) is an edit to existing Kit
# sources, so only the new PRMemoryStore needs wiring.
#
#   PhaseRingsKit: PRMemoryStore.{h,m}  (+ public header)
#
# Idempotent. Run from repo root:
#   ruby scripts/wire_f3_instrument.rb

require 'xcodeproj'

PROJECT_PATH = 'PhaseRings.xcodeproj'
project = Xcodeproj::Project.open(PROJECT_PATH)
kit = project.targets.find { |t| t.name == 'PhaseRingsKit' }
raise 'PhaseRingsKit target not found' unless kit

anchor = project.files.find { |f| f.display_name == 'PRUserDefaultsStore.m' } ||
         project.files.find { |f| f.display_name == 'PRSettingsModel.swift' }
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

h = file_ref(project, group, 'PhaseRings/PRMemoryStore.h')
add_public_header(kit, h)
puts 'Kit public header: PRMemoryStore.h'

m = file_ref(project, group, 'PhaseRings/PRMemoryStore.m')
add_source(kit, m)
puts 'Kit source: PRMemoryStore.m'

project.save
puts "Saved #{PROJECT_PATH}"
