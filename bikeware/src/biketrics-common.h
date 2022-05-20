#ifndef BIKETRICS_COMMON_H_
#define BIKETRICS_COMMON_H_

// Related
// C standard
// C++ standard
// Library
// Project

/// Define TRUE and FALSE
#define TRUE  1
#define FALSE 0

/// Sensor IDs
const unsigned int kFrontWheelSpeedId = 0;
const unsigned int kRearWheelSpeedId  = 1;

/// Pin Assignments
const unsigned int kFrontWheelSpeedPin = 0;
const unsigned int kRearWheelSpeedPin  = 0;

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