// Related
#include "esp-gpio.h"
// C standard
// C++ standard
// Library
// Project
#include "biketrics-common.h"

void IRAM_ATTR gpio_isr_handler(void* arg) {
  uint32_t gpio_num = (uint32_t)arg;
  switch(gpio_num) {
  case kFrontWheelSpeedPin:
    break;
  case kRearWheelSpeedPin:
    break;
  default:
    break;
  }
}