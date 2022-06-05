// Related
#include "wheel-speed-sensor.h"
// C standard
#include <stdio.h>
#include <math.h>
// C++ standard
// Library
// Project
#include "biketrics-common.h"
#include "biketrics-constants.h"
#include "pin-to-queue-manager.h"
#include "esp-gpio.h"
#include "biketrics-logger.h"

///
///
///
WheelSpeedSensor::WheelSpeedSensor(Location location, uint32_t wheelDiameter)
    : kClassName_("WheelSpeedSensor"), taskName_(0), kQueueSize_(10), 
      kDataSize_(sizeof(uint32_t)), location_(NOT_APPLICABLE), pin_(0), 
      dataQ_(0) {
  uint64_t pinBitMask = 0;

  // Set pin-specific parameters
  switch(location) {
    case FRONT:
      taskName_ = (char*)kFrontWheelSpeedTaskName;
      pin_ = kFrontWheelSpeedPin;
      pinBitMask = 1ULL<<kFrontWheelSpeedPin;
      break;
    case REAR:
      taskName_ = (char*)kRearWheelSpeedTaskName;
      pin_ = kRearWheelSpeedPin;
      pinBitMask = 1ULL<<kRearWheelSpeedPin;
      break;
    default:
      LOGE(kClassName_, ("[%-6s]Invalid location provided\n",
          locationToString(location)));
      return;
  }
  location_ = location;
  milesPerRotation_ = (wheelDiameter * M_PI) / kInchesPerMile;

  // Configure the pin
  gpio_config_t gpioConfig = {};
  gpioConfig.intr_type = GPIO_INTR_POSEDGE;
  gpioConfig.mode = GPIO_MODE_INPUT;
  gpioConfig.pin_bit_mask = pinBitMask;
  gpioConfig.pull_up_en = GPIO_PULLUP_ENABLE;
  gpio_config(&gpioConfig);
  logGpioConfig(kClassName_, pin_, gpioConfig);
  gpio_install_isr_service(0); // 0 = default ISR allocation
  gpio_isr_handler_add((gpio_num_t)kFrontWheelSpeedPin, wheelSpeedIsr, 
      (void*)kFrontWheelSpeedPin);
  gpio_isr_handler_add(kRearWheelSpeedPin, wheelSpeedIsr, 
      (void*)kRearWheelSpeedPin);

  // Create the queue for the ISR to place the ticks in
  PinToQueueManager* p2qMan = PinToQueueManager::getInstance();
  dataQ_ = p2qMan->createQueue(pin_, kQueueSize_, kDataSize_);
  if(dataQ_ == 0) {
      LOGE(kClassName_, ("[%-6s]Unable to create data queue\n",
          locationToString(location_)));
      return;
  }

  xTaskCreate(WheelSpeedSensor::task, taskName_, 2048, NULL, 10, NULL);

  LOGI(kClassName_, ("[%-6s]Instantiation Successful\n", 
      locationToString(location_)));
}

///
///
///
WheelSpeedSensor::~WheelSpeedSensor() {
  // TODO: Stop the task
  // TODO: Delete the FreeRTOS Queue
}

///
///
///
void WheelSpeedSensor::task(void* arg) {
  //
  // TODO: Figure out how to pass data to the task at creation-time
  //
  //uint32_t currTicks = 0, prevTicks = 0, speed = 0;
  //for(;;) {
  //  if(xQueueReceive(dataQ, &currTicks, portMAX_DELAY)) {
  //    // Dividing the rotation time (currTicks_ - prevTicks_) by 
  //    // portTICK_PERIOD_MS decouples the calculation from the FreeRTOS 
  //    // tick rate.
  //    speed = milesPerRotation_ / 
  //        (((currTicks - prevTicks) / portTICK_PERIOD_MS) / kMillisPerHour);
  //    LOGD(kClassName_, ("[%-6s]milesPerRotation_=%u currTicks_=%u "
  //        "prevTicks_=%u", locationToString(location_), milesPerRotation_, 
  //        currTicks_, prevTicks_));
  //    LOGI(kClassName_, ("[%-6s]speed_=%u", locationToString(location_), 
  //        speed_));
  //  }
  //}
}

///
///
///
void IRAM_ATTR WheelSpeedSensor::wheelSpeedIsr(void* arg) {
  static TickType_t wheelSpeedTicks = 0;
  wheelSpeedTicks = xTaskGetTickCountFromISR();

  static uint32_t pin = 0;
  pin = (uint32_t)arg;

  LOGD("wheelSpeedISR", ("wheelSpeedTicks=%u", wheelSpeedTicks));

  static PinToQueueManager* pinToQueueMan = PinToQueueManager::getInstance();
  static QueueHandle_t q = 0;
  q = pinToQueueMan->getQueueForPin(pin);
  xQueueSendFromISR(q, &wheelSpeedTicks, NULL);
}