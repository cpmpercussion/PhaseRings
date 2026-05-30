require 'xcodeproj'
project = Xcodeproj::Project.open('PhaseRings.xcodeproj')
target  = project.targets.find { |t| t.name == 'PhaseRings' }
raise 'target not found' unless target

# Locate the group that holds HeavyAudioEngine.mm so the new files sit beside it.
existing_ref = project.files.find { |f| f.display_name == 'HeavyAudioEngine.mm' }
raise 'HeavyAudioEngine.mm ref not found' unless existing_ref
group = existing_ref.parent
puts "Parent group: #{group.display_name} (#{group.real_path})"

%w[HeavyCore.h HeavyCore.mm].each do |name|
  if project.files.any? { |f| f.display_name == name }
    puts "#{name} already in project, skipping"
    next
  end
  ref = group.new_reference("PhaseRings/#{name}")
  if name.end_with?('.mm')
    target.source_build_phase.add_file_reference(ref)
    puts "Added #{name} to sources build phase"
  else
    puts "Added #{name} (header)"
  end
end

project.save
puts 'Saved.'
