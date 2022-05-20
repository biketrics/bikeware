// Related
#include "wheel-speed-sensor.h"
// C standard
#include <stdio.h>
// C++ standard
// Library
// Project
#include "biketrics-common.h"
#include "biketrics-logger.h"

///
const char* WheelSpeedSensor::kClassName_ = "WheelSpeedSensor";

///
///
///
WheelSpeedSensor::WheelSpeedSensor(Location location) {
  switch(location) {
    case FRONT:
      pin_ = kFrontWheelSpeedPin;
      break;
    case REAR:
      pin_ = kRearWheelSpeedPin;
      break;
    default:
      LOG(FATAL, kClassName_, ("[%-6s]:Invalid location provided",
          locationToString(location)));
      return;
  }

  location_ = location;
}

///
///
///
WheelSpeedSensor::~WheelSpeedSensor() {

}

///
///
///
void WheelSpeedSensor::task(void* arg) {

}