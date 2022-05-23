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

/// Common string constants
const char* const kNotApplicableStr = "N/A";
const char* const kUnknownStr       = "UNKNOWN";
const char* const kTrueStr          = "TRUE";
const char* const kFalseStr         = "FALSE";
const char* const kEnableStr        = "ENABLE";
const char* const kDisableStr       = "DISABLE";
const char* const kInputStr         = "INPUT";
const char* const kOutputStr        = "OUTPUT";
const char* const kMaxStr           = "MAX";
const char* const kMinStr           = "MIN";

/// Sensor IDs
const uint32_t kFrontWheelSpeedId = 0;
const uint32_t kRearWheelSpeedId  = 1;

/// Pin Assignments
///     +-------------+
/// RST |             |
/// 3.3 |             |
/// N/C |             |
/// GND |             |
///  26 |             | VBAT
///  25 |   Adafruit  | EN
///  34 |   Huzzah32  | VBUS
///  39 |             | 13
///  36 |    ESP32    | 12
///   4 |             | 27
///   5 |             | 33
///  18 |             | 15
///  19 |             | 32
///  16 |             | 14
///  17 |             | 22
///  21 |             | 23
///     +-------------+
const uint32_t kFrontWheelSpeedPin = 26;
const uint32_t kRearWheelSpeedPin  = 27;

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

///
///
///
const char* locationToString(Location location);

#endif // BIKETRICS_COMMON_H_