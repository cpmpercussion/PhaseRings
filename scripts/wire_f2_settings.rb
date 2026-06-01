#!/usr/bin/env ruby
# Issue #23 Phase F.2: add the shared SwiftUI settings screen sources to the
# PhaseRingsKit framework target.
#
#   PhaseRingsKit: PRSettingsView.swift, PRSettingsHostingController.swift
#
# PRSettingsHostingController is @objc(PRSettingsHostingController), so it
# surfaces in the generated <PhaseRingsKit/PhaseRingsKit-Swift.h> for the ObjC
# hosts; no public ObjC header to expose. PRSettingsView is Swift-only.
#
# Idempotent. Run from repo root:
#   ruby scripts/wire_f2_settings.rb

require 'xcodeproj'

PROJECT_PATH = 'PhaseRings.xcodeproj'
project = Xcodeproj::Project.open(PROJECT_PATH)
kit = project.targets.find { |t| t.name == 'PhaseRingsKit' }
raise 'PhaseRingsKit target not found' unless kit

# Drop the new sources in the same group as the F.1 settings sources.
anchor = project.files.find { |f| f.display_name == 'PRSettingsModel.swift' }
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

%w[PhaseRings/PRSettingsView.swift PhaseRings/PRSettingsHostingController.swift].each do |p|
  ref = file_ref(project, group, p)
  add_source(kit, ref)
  puts "Kit source: #{File.basename(p)}"
end

project.save
puts "Saved #{PROJECT_PATH}"
