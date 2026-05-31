#!/usr/bin/env ruby
# Add HeavyAudioEngine.{h,mm} to the PhaseRings target. Idempotent — re-runs
# do nothing if the files are already wired in.

require 'xcodeproj'

PROJECT_PATH = 'PhaseRings.xcodeproj'
TARGET_NAME  = 'PhaseRings'
FILES = ['HeavyAudioEngine.h', 'HeavyAudioEngine.mm']

project = Xcodeproj::Project.open(PROJECT_PATH)
target  = project.targets.find { |t| t.name == TARGET_NAME }
raise "Target #{TARGET_NAME} not found" unless target

# Drop HeavyAudioEngine next to ViewController in the "controllers" group.
controllers_group = nil
project.main_group.recursive_children_groups.each do |g|
  controllers_group = g if g.display_name == 'controllers'
end
raise "controllers group not found" unless controllers_group

existing_paths = controllers_group.files.map(&:path)

added = 0
FILES.each do |name|
  full_path = "PhaseRings/#{name}"
  next if existing_paths.include?(name) || existing_paths.include?(full_path)
  # Mirror how ViewController.{h,m} are referenced: file path is
  # `PhaseRings/<name>` (resolved from the project root), with the bare name
  # used for display. The "controllers" group's own `path = PhaseRings` is a
  # display vestige; children are resolved against project root.
  ref = controllers_group.new_reference(full_path)
  ref.name = name
  target.add_file_references([ref]) if name.end_with?('.m', '.mm')
  added += 1
end

project.save
puts "wire_heavy_engine: added #{added} file(s) to #{TARGET_NAME}."
