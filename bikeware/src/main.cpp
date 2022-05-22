// Related
// C standard
#include <stdio.h>
// C++ standard
// Library
// Project
#include "biketrics-common.h"
#include "wheel-speed-sensor.h"
#include "pin-to-queue-manager.h"
#include "biketrics-logger.h"

extern "C" void app_main(void) {
  PRINT(("---------------- biketrics bikeware --------------------\n"));

  PinToQueueManager* p2q = PinToQueueManager::getInstance();
  WheelSpeedSensor* centerWss = new WheelSpeedSensor(CENTER);
  WheelSpeedSensor* frontWss = new WheelSpeedSensor(FRONT);
  WheelSpeedSensor* rearWss = new WheelSpeedSensor(REAR);
  p2q->printMap();
}