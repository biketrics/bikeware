#ifndef ESP_GPIO_H_
#define ESP_GPIO_H_

// Related
// C standard
// C++ standard
// Library
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
// Project
#include "biketrics-common.h"

/// GPIO mode strings
const char* const kGpioModeDisable       = kDisableStr;
const char* const kGpioModeInput         = kInputStr;
const char* const kGpioModeOutput        = kOutputStr;
const char* const kGpioModeOutputOd      = "OUTPUT_OD";
const char* const kGpioModeInputOutputOd = "INPUT_OUTPUT_OD";
const char* const kGpioModeInputOutput   = "INPUT_OUTPUT";

/// Interrupt types
const char* const kInterruptDisable   = kDisableStr;
const char* const kInterruptPosEdge   = "POS_EDGE";
const char* const kInterruptNegEdgs   = "NEG_EDGE";
const char* const kInterruptAnyEdge   = "ANY_EDGE";
const char* const kInterruptLowLevel  = "LOW_LVL";
const char* const kInterruptHighLevel = "HIGH_LVL";
const char* const kInterruptMax       = kMaxStr;

///
///
///
void logGpioConfig(const char* classname, uint32_t pin, 
    gpio_config_t& gpioConfig);

#endif  // ESP_GPIO_H_