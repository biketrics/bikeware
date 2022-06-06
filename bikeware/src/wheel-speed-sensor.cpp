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
#include "GPIO-to-queue-manager.h"
#include "esp-gpio.h"
#include "biketrics-logger.h"

///
///
///
WheelSpeedSensor::WheelSpeedSensor(Location location, uint32_t wheelDiameter)
    : kClassName_("WheelSpeedSensor"), taskName_(0), kQueueSize_(10), 
      kDataSize_(sizeof(uint32_t)), location_(NOT_APPLICABLE), GPIO_(0), 
      q_(0) {
  uint64_t GPIOBitMask = 0;

  // Set GPIO-specific parameters
  switch(location) {
    case FRONT:
      taskName_ = (char*)kFrontWheelSpeedTaskName;
      GPIO_ = kFrontWheelSpeedGPIO;
      GPIOBitMask = 1ULL<<kFrontWheelSpeedGPIO;
      break;
    case REAR:
      taskName_ = (char*)kRearWheelSpeedTaskName;
      GPIO_ = kRearWheelSpeedGPIO;
      GPIOBitMask = 1ULL<<kRearWheelSpeedGPIO;
      break;
    default:
      LOGE(kClassName_, ("[%-6s]Invalid location provided\n",
          locationToString(location)));
      return;
  }
  location_ = location;
  milesPerRotation_ = (wheelDiameter * M_PI) / kInchesPerMile;

  // Configure the GPIO
  gpio_config_t gpioConfig = {};
  gpioConfig.intr_type = GPIO_INTR_POSEDGE;
  gpioConfig.mode = GPIO_MODE_INPUT;
  gpioConfig.GPIO_bit_mask = GPIOBitMask;
  gpioConfig.pull_up_en = GPIO_PULLUP_ENABLE;
  gpio_config(&gpioConfig);
  logGpioConfig(kClassName_, GPIO_, gpioConfig);
  gpio_install_isr_service(0); // 0 = default ISR allocation
  gpio_isr_handler_add((gpio_num_t)kFrontWheelSpeedGPIO, wheelSpeedIsr, 
      (void*)kFrontWheelSpeedGPIO);
  gpio_isr_handler_add(kRearWheelSpeedGPIO, wheelSpeedIsr, 
      (void*)kRearWheelSpeedGPIO);

  // Create the queue for the ISR to place the ticks in
  GPIOToQueueManager* p2qMan = GPIOToQueueManager::getInstance();
  q_ = p2qMan->createQueue(GPIO_, kQueueSize_, kDataSize_);
  if(q_ == 0) {
      LOGE(kClassName_, ("[%-6s]Unable to create data queue\n",
          locationToString(location_)));
      return;
  }

  xTaskCreate(WheelSpeedSensor::task, taskName_, 2048, this, 10, NULL);

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
char* WheelSpeedSensor::getTaskName() {
  return taskName_;
}

///
///
///
Location WheelSpeedSensor::getLocation() {
  return location_;
}

///
///
///
uint32_t WheelSpeedSensor::getGpio() {
  return GPIO_;
}

///
///
///
QueueHandle_t WheelSpeedSensor::getQueue() {
  return q_;
}

///
///
///
uint32_t WheelSpeedSensor::getMilesPerRotation() {
  return milesPerRotation_;
}

///
///
///
void WheelSpeedSensor::task(void* arg) {
  WheelSpeedSensor* ws = (WheelSpeedSensor*)arg;
  char* taskName = ws->getTaskName();
  Location location = ws->getLocation();
  uint32_t milesPerRotation = ws->getMilesPerRotation();
  QueueHandle_t q = ws->getQueue();

  uint32_t currTicks = 0, prevTicks = 0, speed = 0;

  for(;;) {
    if(xQueueReceive(q, &currTicks, portMAX_DELAY)) {
      // Dividing the rotation time (currTicks_ - prevTicks_) by 
      // portTICK_PERIOD_MS decouples the calculation from the FreeRTOS 
      // tick rate.
      speed = milesPerRotation / 
          (((currTicks - prevTicks) / portTICK_PERIOD_MS) / kMillisPerHour);
      LOGD(taskName, ("[%-6s]milesPerRotation_=%u currTicks=%u "
          "prevTicks=%u", locationToString(location), milesPerRotation, 
          currTicks, prevTicks));
      LOGI(taskName, ("[%-6s]speed=%u", locationToString(location), 
          speed));
    }
  }
}

///
///
///
void IRAM_ATTR WheelSpeedSensor::wheelSpeedIsr(void* arg) {
  static TickType_t wheelSpeedTicks = 0;
  wheelSpeedTicks = xTaskGetTickCountFromISR();

  static uint32_t GPIO = 0;
  GPIO = (uint32_t)arg;

  LOGD("wheelSpeedISR", ("wheelSpeedTicks=%u", wheelSpeedTicks));

  static GPIOToQueueManager* GPIOToQueueMan = GPIOToQueueManager::getInstance();
  static QueueHandle_t q = 0;
  q = GPIOToQueueMan->getQueueForGPIO(GPIO);
  xQueueSendFromISR(q, &wheelSpeedTicks, NULL);
}