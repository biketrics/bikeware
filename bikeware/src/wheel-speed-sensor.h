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
  WheelSpeedSensor(Location location, uint32_t wheelSize);
  
  ///
  ///
  ///
  ~WheelSpeedSensor();

  ///
  ///
  ///
  char* getTaskName();

  ///
  ///
  ///
  Location getLocation();

  ///
  ///
  ///
  uint32_t getGpio();

  ///
  ///
  ///
  QueueHandle_t getQueue();

  ///
  ///
  ///
  uint32_t getMilesPerRotation();
  
 protected:
 private:
  ///
  ///
  ///
  static void task(void* arg);

  ///
  ///
  ///
  static void IRAM_ATTR wheelSpeedIsr(void* arg);

  /// Class name for printing/logging.
  const char* kClassName_;
  ///
  char* taskName_;
  /// 
  const uint32_t kQueueSize_;
  /// 
  const uint32_t kDataSize_;
  /// Identifies where on the bike the sensor is mounted.
  Location location_;
  /// 
  uint32_t GPIO_;
  /// Queue where new sensor data is placed.
  QueueHandle_t q_;
  /// 
  uint32_t milesPerRotation_;
};

#endif // WHEEL_SPEED_SENSOR_H_