Audiobus SDK -- Version 2.1.5 -- Nov 10 2014
============================================

Thanks for downloading the Audiobus distribution!

See http://developer.audiob.us/doc/ for the developer documentation,
and see the Samples folder for a number of sample projects.

If you have any questions, please don't hesitate to join us on 
the developer community forum at http://heroes.audiob.us.

Cheers!

Audiobus Team
http://audiob.us

Changes
=======

2.1.5
-------

 - Added ABAudioUnitFader class, for smooth fade-in/fade-out transitions instead of hard
   clicks when starting or stopping your audio system.
 - Fixed crash on ABAudiobusController dealloc
 - Fixed an issue with the connection panel being blank when changing position soon after
   launch.
 - Added workaround for connection panel 'stripe' on rotation on iOS 8
 - Fixed a sporadic issue with chaining filters
 - Fixed an issue with missing app icons in connection panel prior to launch
 - Added code to handle an iOS Bonjour bug resulting in address resolution failure
 - Fixed sample rate conversion issue

2.1.4
-----

 - Added 'audiobusConnected' and 'interAppAudioConnected' properties to local port classes
 - Added 'interAppAudioConnected' property to ABAudiobusController
 - Added 'memberOfActiveAudiobusSession' property to ABAudiobusController which replaces
   'audiobusAppRunning' property in determining whether an app should remain active in the
   background.
 - Fixed an issue with ABSenderPort when created with user audio unit and connected to self
 - Adjusted buffering in ABSenderPortSend to allow for non-hardware buffer duration
   enqueue lengths
 - Improvements to internal buffering mechanisms
 - Addressed issue when setting a sender or filter port's audioUnit property to NULL
 - Addressed a Bonjour namespace collision issue
 - Adjusted 'connected' state change notification behaviour
 - Tweaked IAA shutdown

2.1.3
-----

 - Fixed connection panel position issues on iOS 8 when built with Xcode 6
 - Fixed issues resuming after audio session interruption
 - Fixed an occasional crash when run from debugger
 - Added support for reporting IAA hosting issues via Audiobus UI
 - Added checking for String-typed "version" AudioComponents field
 - Revised handling for disconnection in sample code
 - Avoid a possible crash when recreating network socket

2.1.2
-----

 - Widen draggable surface area for connection panel drag-in tab
 - Revised muting policy for apps with multiple sender ports
 - Fixed an issue with filters muting when a new, un-launched source is added

2.1.1
-----

 - Fixed an assertion problem during state restoring ("must have completionBlock")
 - Fixed an audio conversion issue with ABReceiverPort with receiveMixedAudio = NO
 - Added some extra Info.plist sanity checks

2.1
---

Major new update, with Inter-App Audio integration, state saving, a new connection panel
design and an easier, cleaner, simpler API.

Check out our [migration guide](http://developer.audiob.us/migrate) for details.
