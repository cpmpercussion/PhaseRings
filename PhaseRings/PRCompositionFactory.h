//
//  PRCompositionFactory.h
//  PhaseRingsKit
//
//  Issue #23 (Phase F.1): single source of truth for turning a PRSettings into
//  a GenerativeSetupComposition. Replaces the composition-building switch that
//  used to live inline in ViewController -openComposition, so the app and the
//  AUv3 extension build the identical composition from the same settings.
//

#import <Foundation/Foundation.h>
#import "PRSettings.h"

NS_ASSUME_NONNULL_BEGIN

// Forward-declared so this public framework header stays modular; consumers that
// use the returned object import GenerativeSetupComposition.h themselves.
@class GenerativeSetupComposition;

@interface PRCompositionFactory : NSObject

/// Builds the composition described by `settings`. Compositions 1..4 are fixed
/// presets; composition 0 is the custom composition built from the note/scale
/// fields (offset from BASE_A, matching the legacy app behaviour).
+ (GenerativeSetupComposition *)compositionForSettings:(PRSettings *)settings;

@end

NS_ASSUME_NONNULL_END
