// Related
#include "esp-gpio.h"
// C standard
// C++ standard
// Library
// Project
#include "biketrics-common.h"
#include "pin-to-queue-manager.h"
#include "biketrics-logger.h"

///
///
///
void logGpioConfig(const char* classname, uint32_t pin, 
    gpio_config_t& gpioConfig) {
  char* interrupt = 0;
  char* mode = 0;
  char* pullup = 0;
  char* pulldown = 0;

  switch(gpioConfig.intr_type) {
    case GPIO_INTR_DISABLE:
      interrupt = (char*)kInterruptDisable;
      break;
    case GPIO_INTR_POSEDGE:
      interrupt = (char*)kInterruptPosEdge;
      break;
    case GPIO_INTR_NEGEDGE:
      interrupt = (char*)kInterruptNegEdgs;
      break;
    case GPIO_INTR_ANYEDGE:
      interrupt = (char*)kInterruptAnyEdge;
      break;
    case GPIO_INTR_LOW_LEVEL:
      interrupt = (char*)kInterruptLowLevel;
      break;
    case GPIO_INTR_HIGH_LEVEL:
      interrupt = (char*)kInterruptHighLevel;
      break;
    case GPIO_INTR_MAX:
      interrupt = (char*)kMaxStr;
      break;
    default:
      interrupt = (char*)kUnknownStr;
      break;      
  }

  switch(gpioConfig.mode) {
    case GPIO_MODE_DISABLE:
      mode = (char*)kGpioModeDisable;
      break;
    case GPIO_MODE_INPUT:
      mode = (char*)kGpioModeInput;
      break;
    case GPIO_MODE_OUTPUT:
      mode = (char*)kGpioModeOutput;
      break;
    case GPIO_MODE_OUTPUT_OD:
      mode = (char*)kGpioModeOutputOd;
      break;
    case GPIO_MODE_INPUT_OUTPUT_OD:
      mode = (char*)kGpioModeInputOutputOd;
      break;
    case GPIO_MODE_INPUT_OUTPUT:
      mode = (char*)kGpioModeInputOutput;
      break;
    default:
      mode = (char*)kUnknownStr;
      break;
  }

  if(gpioConfig.pull_up_en == GPIO_PULLUP_ENABLE) {
    pullup = (char*)kTrueStr;
  } else {
    pullup = (char*)kFalseStr;
  }

  if(gpioConfig.pull_down_en == GPIO_PULLDOWN_ENABLE) {
    pulldown = (char*)kTrueStr;
  } else {
    pulldown = (char*)kFalseStr;
  }

  LOGI(classname, ("[GpioConfig] pin=%u mode=%s interrupt=%s pullup=%s"
      " pulldown=%s\n", pin, mode, interrupt, pullup, pulldown));
}