CFBundleIconFile: A legacy way to specify the app's icon.Use the CFBundleIcons or CFBundleIconFiles instead.


CFBundleIconFiles:This key is supported in iOS 3.2 and later only.


CFBundleIcons:It contains information about all of the icons used by the app. This key allows you to group icons based on their intended usage and specify multiple icon files together with specific keys for modifying the appearance of those icons.

CFBundlePrimaryIcon: In iOS 5.0 and later, this key takes precedence.


Summary:
  The CFBundleIcons key takes precedence over this key in iOS 5.0 and later. This key takes precedence over the CFBundleIconFile key.


CFBundleIcons~ipad

CFBundleIconFiles~ipad



Platform-specific modifiers—Use the modifiers ~iphone or ~ipad to specify images targeting a specific size of device.



CFBundleIcons

CFBundleIcons (Dictionary - iOS, tvOS) contains information about all of the icons used by the app. This key allows you to group icons based on their intended usage and specify multiple icon files together with specific keys for modifying the appearance of those icons. This dictionary can contain the following keys:

CFBundlePrimaryIcon—This key identifies the primary icon for the Home screen and Settings app among others. The value for this key is described in Contents of the CFBundlePrimaryIcon Dictionary Entry.
CFBundleAlternateIcons—This key identifies alternate icons for the Home screen and Settings app among others. The value for this key is described in Contents of the CFBundleAlternateIcons Dictionary Entry.
UINewsstandIcon—This key identifies default icons to use for apps presented from Newsstand. The value for this key is a dictionary whose contents are described in Contents of the UINewsstandIcon Dictionary.
The CFBundleIcons key is supported in iOS 5.0 and later and in tvOS 9.0 and later. In iOS, you can combine this key with the CFBundleIconFiles and CFBundleIconFile keys but in iOS 5.0 and later, this key takes precedence.

