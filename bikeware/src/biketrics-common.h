#ifndef BIKETRICS_COMMON_H_
#define BIKETRICS_COMMON_H_

// Related
// C standard
#include "stdlib.h"
// C++ standard
// Library
// Project

/// Define TRUE and FALSE
#define TRUE  1
#define FALSE 0

/// Sensor IDs
const uint32_t kFrontWheelSpeedId = 0;
const uint32_t kRearWheelSpeedId  = 1;

/// Pin Assignments
const uint32_t kFrontWheelSpeedPin = 0;
const uint32_t kRearWheelSpeedPin  = 0;

///
///
///
enum Location {
  FRONT,
  CENTER,
  REAR,
  NOT_APPLICABLE
};

/// Location strings
const char* const kFrontStr = "FRONT";
const char* const kCenterStr = "CENTER";
const char* const kRearStr = "REAR";
const char* const kNotApplicableStr = "N/A";

///
///
///
const char* locationToString(Location location);

#endif // BIKETRICS_COMMON_H_