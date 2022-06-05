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
  WheelSpeedSensor* centerWss = new WheelSpeedSensor(CENTER, 27.5);
  WheelSpeedSensor* frontWss = new WheelSpeedSensor(FRONT, 27.5);
  WheelSpeedSensor* rearWss = new WheelSpeedSensor(REAR, 27.5);
  p2q->printMap();
}