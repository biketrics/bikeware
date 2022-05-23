// Related
#include "wheel-speed-sensor.h"
// C standard
#include <stdio.h>
// C++ standard
// Library
// Project
#include "biketrics-common.h"
#include "pin-to-queue-manager.h"
#include "esp-gpio.h"
#include "biketrics-logger.h"

///
///
///
WheelSpeedSensor::WheelSpeedSensor(Location location)
    : kClassName_("WheelSpeedSensor"), kQueueSize_(10), 
      kDataSize_(sizeof(uint32_t)) {
  uint64_t pinBitMask = 0;

  // Determine pin info based on the sensor's location
  switch(location) {
    case FRONT:
      pin_ = kFrontWheelSpeedPin;
      pinBitMask = 1ULL<<kFrontWheelSpeedPin;
      break;
    case REAR:
      pin_ = kRearWheelSpeedPin;
      pinBitMask = 1ULL<<kRearWheelSpeedPin;
      break;
    default:
      LOGE(kClassName_, ("[%-6s]Invalid location provided\n",
          locationToString(location)));
      return;
  }
  location_ = location;

  // Configure the pin(s)
  gpio_config_t gpioConfig = {};
  gpioConfig.intr_type = GPIO_INTR_POSEDGE;
  gpioConfig.mode = GPIO_MODE_INPUT;
  gpioConfig.pin_bit_mask = pinBitMask;
  gpioConfig.pull_up_en = GPIO_PULLUP_ENABLE;
  logGpioConfig(kClassName_, pin_, gpioConfig);
  gpio_config(&gpioConfig);

  // Create a sensor data queue
  PinToQueueManager* p2qMan = PinToQueueManager::getInstance();
  dataQ_ = p2qMan->createQueue(pin_, kQueueSize_, kDataSize_);
  if(dataQ_ == 0) {
      LOGE(kClassName_, ("[%-6s]Unable to create data queue\n",
          locationToString(location)));
  }
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
  for(;;) {
  }
}