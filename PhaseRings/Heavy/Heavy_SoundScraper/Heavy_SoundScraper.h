/** Copyright (c) 2026 Charles Martin. Generated from Pure Data by hvcc (https://github.com/Wasted-Audio/hvcc). */

#ifndef _HEAVY_SOUNDSCRAPER_H_
#define _HEAVY_SOUNDSCRAPER_H_

#include "HvHeavy.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HV_APPLE
#pragma mark - Heavy Context
#endif


typedef enum {
  HV_SOUNDSCRAPER_TABLE__1013_DEFAULT = 0x58D371AD, // 1013_default
  HV_SOUNDSCRAPER_TABLE__1051_DEFAULT = 0x565019FD, // 1051_default
  HV_SOUNDSCRAPER_TABLE__1089_DEFAULT = 0x262582C8, // 1089_default
  HV_SOUNDSCRAPER_TABLE__1127_DEFAULT = 0x161BC6D4, // 1127_default
  HV_SOUNDSCRAPER_TABLE__1674_DEFAULT = 0x93F54B3C, // 1674_default
  HV_SOUNDSCRAPER_TABLE_ALMGLOCKEN = 0x6F52CA74, // almglocken
  HV_SOUNDSCRAPER_TABLE_BOWL = 0x9BCAD111, // bowl
  HV_SOUNDSCRAPER_TABLE_CROTALE = 0x782CD90, // crotale
  HV_SOUNDSCRAPER_TABLE_GONG = 0x53C964B5, // gong
  HV_SOUNDSCRAPER_TABLE_MARIMBA = 0xAC13AE99, // marimba
  HV_SOUNDSCRAPER_TABLE_XYLO = 0x1FD931DF, // xylo
} Hv_SoundScraper_Table;

/**
 * Creates a new patch instance.
 * Sample rate should be positive and in Hertz, e.g. 44100.0.
 */
HeavyContextInterface *hv_SoundScraper_new(double sampleRate);

/**
 * Creates a new patch instance.
 * @param sampleRate  Sample rate should be positive (> 0) and in Hertz, e.g. 48000.0.
 * @param poolKb  Pool size is in kilobytes, and determines the maximum amount of memory
 *   allocated to messages at any time. By default this is 10 KB.
 * @param inQueueKb  The size of the input message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages between calls to
 *   process(). Default is 2 KB.
 * @param outQueueKb  The size of the output message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages to the default sendHook.
 *   See getNextSentMessage() for info on accessing these messages. Default is 0 KB.
 */
HeavyContextInterface *hv_SoundScraper_new_with_options(double sampleRate, int poolKb, int inQueueKb, int outQueueKb);

/**
 * Free the patch instance.
 */
void hv_SoundScraper_free(HeavyContextInterface *instance);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_SOUNDSCRAPER_H_
