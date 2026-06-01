#!/usr/bin/env ruby
# Phase F.0 (issue #23): turn PhaseRingsKit into a mixed ObjC/Swift framework.
#
#  1. Adds Swift build settings to the PhaseRingsKit target (Debug + Release).
#  2. Adds PhaseRings/PRSwiftSmokeTest.swift to the project and the Kit's
#     Sources build phase, in the same group as the other Kit sources.
#
# DEFINES_MODULE is already YES on the Kit, so the mixed-language build emits
# <PhaseRingsKit/PhaseRingsKit-Swift.h> automatically once a .swift file is in
# the Sources phase.
#
# Idempotent. Run from repo root:
#   ruby scripts/enable_swift_in_kit.rb

require 'xcodeproj'

PROJECT_PATH = 'PhaseRings.xcodeproj'
TARGET_NAME  = 'PhaseRingsKit'
SWIFT_FILE   = 'PhaseRings/PRSwiftSmokeTest.swift'
# Anchor: add the new Swift file next to this existing Kit source.
ANCHOR_FILE  = 'InstrumentViewController.m'

project = Xcodeproj::Project.open(PROJECT_PATH)
target  = project.targets.find { |t| t.name == TARGET_NAME }
raise "Target #{TARGET_NAME} not found" unless target

# 1. Swift build settings on every build configuration of the Kit.
target.build_configurations.each do |config|
  s = config.build_settings
  s['SWIFT_VERSION'] = '5.0'
  s['SWIFT_OPTIMIZATION_LEVEL'] = config.name == 'Debug' ? '-Onone' : '-Owholemodule'
  if config.name == 'Debug'
    s['SWIFT_ACTIVE_COMPILATION_CONDITIONS'] = 'DEBUG'
  end
  puts "Set Swift settings on #{TARGET_NAME} (#{config.name})"
end

# 2. Add the Swift file to the project + Kit Sources phase (idempotent).
existing = project.files.find { |f| f.path && f.path.end_with?(File.basename(SWIFT_FILE)) }
if existing
  file_ref = existing
  puts "File ref already present: #{file_ref.path}"
else
  anchor = project.files.find { |f| f.display_name == ANCHOR_FILE }
  group  = anchor ? anchor.parent : project.main_group
  file_ref = group.new_file(SWIFT_FILE)
  puts "Added file ref #{SWIFT_FILE} to group '#{group.display_name}'"
end

unless target.source_build_phase.files_references.include?(file_ref)
  target.add_file_references([file_ref])
  puts "Added #{File.basename(SWIFT_FILE)} to #{TARGET_NAME} Sources phase"
end

project.save
puts "Saved #{PROJECT_PATH}"
