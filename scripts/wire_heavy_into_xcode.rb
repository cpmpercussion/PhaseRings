#!/usr/bin/env ruby
# Add the Heavy C++ outputs under PhaseRings/Heavy/ to the PhaseRings target.
# Layout produced by scripts/build_hvcc.sh:
#   PhaseRings/Heavy/shared/                 (one copy of the Heavy runtime)
#   PhaseRings/Heavy/Heavy_<Name>/           (Heavy_<Name>.{cpp,h,hpp} only)
#
# Idempotent: any pre-existing Heavy group is removed and rebuilt so adds and
# removes between hvcc runs are picked up automatically. Also adds the
# shared/ directory to HEADER_SEARCH_PATHS so the per-context entry .cpp files
# can resolve `#include "HeavyContext.hpp"` etc.
#
# Run from repo root:
#   ruby scripts/wire_heavy_into_xcode.rb

require 'xcodeproj'
require 'pathname'

PROJECT_PATH = 'PhaseRings.xcodeproj'
TARGET_NAME  = 'PhaseRings'
CONTEXTS = ['Heavy_PhaseRing', 'Heavy_CircleStrings', 'Heavy_SoundScraper']

project = Xcodeproj::Project.open(PROJECT_PATH)
target  = project.targets.find { |t| t.name == TARGET_NAME }
raise "Target #{TARGET_NAME} not found" unless target

# Drop references to .pd patches that were deleted during the hvcc migration
# but are still in the project (the build can't find them otherwise).
stale_pd = ['s_loopsmooth.pd', 's_playolap.pd']
project.files.select { |f| stale_pd.include?(f.display_name) }.each do |ref|
  target.resources_build_phase.files.each do |bf|
    bf.remove_from_project if bf.file_ref == ref
  end
  ref.remove_from_project
end

# Remove any pre-existing Heavy group so reruns produce a clean tree.
existing = project.main_group.children.find { |c| c.is_a?(Xcodeproj::Project::Object::PBXGroup) && c.display_name == 'Heavy' }
if existing
  files = existing.recursive_children_groups.flat_map(&:files) + existing.files
  files.each do |ref|
    target.source_build_phase.files.each do |bf|
      bf.remove_from_project if bf.file_ref == ref
    end
    ref.remove_from_project
  end
  existing.remove_from_project
end

heavy_group = project.main_group.new_group('Heavy', 'PhaseRings/Heavy')

added_sources = 0
added_headers = 0

add_dir = ->(group, dir) do
  Pathname.new(dir).children.sort.each do |path|
    next unless path.file?
    ref = group.new_reference(path.basename.to_s)
    case path.extname
    when '.c', '.cpp'
      target.add_file_references([ref])
      added_sources += 1
    when '.h', '.hpp'
      added_headers += 1
    end
  end
end

shared_group = heavy_group.new_group('shared', 'shared')
add_dir.call(shared_group, 'PhaseRings/Heavy/shared')

CONTEXTS.each do |name|
  ctx_group = heavy_group.new_group(name, name)
  add_dir.call(ctx_group, "PhaseRings/Heavy/#{name}")
end

# Make the shared runtime headers discoverable for the per-context entry .cpp
# files (they #include "HeavyContext.hpp" with no path prefix).
shared_path = '$(SRCROOT)/PhaseRings/Heavy/shared'
target.build_configurations.each do |config|
  paths = Array(config.build_settings['HEADER_SEARCH_PATHS'])
  next if paths.include?(shared_path)
  paths = paths.empty? ? ['$(inherited)'] : paths
  paths << shared_path
  config.build_settings['HEADER_SEARCH_PATHS'] = paths
end

project.save

puts "Wired Heavy sources into #{TARGET_NAME}:"
puts "  source files added to build phase: #{added_sources}"
puts "  header files added (group only):   #{added_headers}"
