//
//  PRUserDefaultsStore.h
//  PhaseRings
//
//  Issue #23 (Phase F.1): standalone-app PRSettingsStore backed by the existing
//  NSUserDefaults keys, 1:1, so current users' settings carry over untouched.
//  Lives in the app target (the AUv3 extension uses its own AU-backed store).
//

#import <Foundation/Foundation.h>
#import <PhaseRingsKit/PRSettingsStore.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRUserDefaultsStore : NSObject <PRSettingsStore>

/// Uses +[NSUserDefaults standardUserDefaults].
- (instancetype)init;
/// Designated initialiser (injectable defaults for testing).
- (instancetype)initWithUserDefaults:(NSUserDefaults *)defaults NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
