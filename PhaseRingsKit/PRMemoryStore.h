//
//  PRMemoryStore.h
//  PhaseRingsKit
//
//  Issue #23 (Phase F.3): a session-only, in-memory PRSettingsStore. Seeds from
//  +[PRSettings defaultSettings] and holds edits for the lifetime of the
//  instance. Used as InstrumentViewController's default backing store so the
//  shared instrument surface + settings screen work even when a host injects no
//  store — and as the AUv3 host's store until F.4 swaps in a fullState-persisted
//  PRAudioUnitStore.
//

#import <Foundation/Foundation.h>
#import "PRSettingsStore.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRMemoryStore : NSObject <PRSettingsStore>
@end

NS_ASSUME_NONNULL_END
