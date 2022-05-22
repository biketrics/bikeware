// Related
#include "wheel-speed-sensor.h"
// C standard
#include <stdio.h>
// C++ standard
// Library
// Project
#include "biketrics-common.h"
#include "pin-to-queue-manager.h"
#include "biketrics-logger.h"

///
///
///
WheelSpeedSensor::WheelSpeedSensor(Location location)
    : kClassName_("WheelSpeedSensor"), kQueueSize_(10), 
      kDataSize_(sizeof(uint32_t)) {
  switch(location) {
    case FRONT:
      pin_ = kFrontWheelSpeedPin;
      break;
    case REAR:
      pin_ = kRearWheelSpeedPin;
      break;
    default:
      LOGE(kClassName_, ("[%-6s]Invalid location provided\n",
          locationToString(location)));
      return;
  }
  location_ = location;

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