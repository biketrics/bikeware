#ifndef ESP_GPIO_H_
#define ESP_GPIO_H_

// Related
// C standard
// C++ standard
// Library
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
// Project
#include "biketrics-common.h"

static void IRAM_ATTR gpio_isr_handler(void* arg);

#endif // ESP_GPIO_H_