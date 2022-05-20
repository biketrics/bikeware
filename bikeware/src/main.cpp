// Related
// C standard
#include <stdio.h>
// C++ standard
// Library
// Project
#include "biketrics-common.h"
#include "wheel-speed-sensor.h"
#include "biketrics-logger.h"

extern "C" void app_main(void) {
  PRINT(("---------------- biketrics bikeware --------------------\n"));

  WheelSpeedSensor* wss = new WheelSpeedSensor(CENTER);
}