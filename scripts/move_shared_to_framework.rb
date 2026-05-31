#!/usr/bin/env ruby
# Move the shared UI/model classes' compilation from the app target into the
# PhaseRingsKit framework, so both the app and the AUv3 extension link one
# copy (ObjC has a flat class namespace — they can't be compiled into two
# binaries). Headers stay project file references; quote-imports keep
# resolving via the project headermap, so no #import changes are needed in the
# app or tests. See auv3-plan.md (Phase F).
#
#   ruby scripts/move_shared_to_framework.rb

require 'xcodeproj'

CLASSES = %w[SingingBowlView NoteColours SingingBowlComposition
             GenerativeSetupComposition SingingBowlSetup ScaleMaker]

project = Xcodeproj::Project.open('PhaseRings.xcodeproj')
app = project.targets.find { |t| t.name == 'PhaseRings' }
fw  = project.targets.find { |t| t.name == 'PhaseRingsKit' }
raise 'targets not found' unless app && fw

moved = []
CLASSES.each do |name|
  ref = project.files.find { |f| f.display_name == "#{name}.m" }
  raise "#{name}.m not found" unless ref
  # already in framework?
  if fw.source_build_phase.files.any? { |bf| bf.file_ref == ref }
    next
  end
  app.source_build_phase.files.dup.each do |bf|
    bf.remove_from_project if bf.file_ref == ref
  end
  fw.source_build_phase.add_file_reference(ref)
  moved << "#{name}.m"
end

# The UI classes need UIKit; the framework only linked audio frameworks so far.
fw.add_system_frameworks(%w[UIKit]) unless fw.frameworks_build_phase.files.any? { |f| f.file_ref&.display_name == 'UIKit.framework' }

project.save
puts "Moved into PhaseRingsKit: #{moved.join(', ')}"
