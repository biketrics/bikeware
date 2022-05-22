#ifndef WHEEL_SPEED_SENSOR_H_
#define WHEEL_SPEED_SENSOR_H_

// Related
// C standard
// C++ standard
// Library
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
// Project
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
  
 protected:
 private:
  ///
  ///
  ///
  static void task(void* arg);

  /// Class name for printing/logging.
  const char* kClassName_;
  /// Class name for printing/logging.
  const uint32_t kQueueSize_;
  /// Class name for printing/logging.
  const uint32_t kDataSize_;
  /// Identifies where on the bike the sensor is mounted.
  Location location_;
  /// Identifies where on the bike the sensor is mounted.
  unsigned int pin_;
  /// Queue where new sensor data is placed.
  QueueHandle_t dataQ_;
};

#endif // WHEEL_SPEED_SENSOR_H_