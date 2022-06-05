#ifndef BIKETRICS_CONSTANTS_H_
#define BIKETRICS_CONSTANTS_H_

#include <stdlib.h>

// Distance constants
const uint32_t kFeetPerMile = 5280;
const uint32_t kInchesPerMile = kFeetPerMile * 12;

// Time constants
const uint32_t kMinutesPerHour = 60;
const uint32_t kSecondsPerMinute = 60;
const uint32_t kMillisPerSecond = 1000;
const uint32_t kMillisPerHour = kMinutesPerHour * kSecondsPerMinute * 
    kMillisPerSecond;

#endif // BIKETRICS_CONSTANTS_H_