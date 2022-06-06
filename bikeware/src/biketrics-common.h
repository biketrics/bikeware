#ifndef BIKETRICS_COMMON_H_
#define BIKETRICS_COMMON_H_

// Related
// C standard
#include "stdlib.h"
// C++ standard
// Library
#include "driver/gpio.h"
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

/// GPIO Assignments
///     +-------------+
/// RST |             |
/// 3.3 |             |
/// N/C |             |
/// GND |             |
///  26 |             | VBAT
///  25 |             | EN
///  34 |             | VBUS
///  39 |  Adafruit   | 13
///  36 |  Huzzah32   | 12
///   4 |             | 27
///   5 |             | 33
///  18 |             | 15
///  19 |             | 32
///  16 |             | 14
///  17 |             | 22
///  21 |             | 23
///     +-------------+
const gpio_num_t kFrontWheelSpeedGPIO = GPIO_NUM_26;
const gpio_num_t kRearWheelSpeedGPIO  = GPIO_NUM_27;

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

/// Task names
const char* const kFrontWheelSpeedTaskName = "FrontWheelSpeedTask";
const char* const kRearWheelSpeedTaskName = "RearWheelSpeedTask";

#endif // BIKETRICS_COMMON_H_