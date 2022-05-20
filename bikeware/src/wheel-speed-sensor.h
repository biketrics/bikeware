#ifndef WHEEL_SPEED_SENSOR_H_
#define WHEEL_SPEED_SENSOR_H_

#include "biketrics-common.h"

///
///
///
class WheelSpeedSensor {
 public:
  ///
  ///
  ///
  WheelSpeedSensor(Location location);
  
  ///
  ///
  ///
  ~WheelSpeedSensor();

  ///
  ///
  ///
  static void task(void* arg);

 protected:
 private:
  /// Class name for printing/logging.
  static const char* kClassName_;
  /// Identifies where on the bike the sensor is mounted.
  Location location_;
  /// Identifies where on the bike the sensor is mounted.
  unsigned int pin_;
};

#endif // WHEEL_SPEED_SENSOR_H_