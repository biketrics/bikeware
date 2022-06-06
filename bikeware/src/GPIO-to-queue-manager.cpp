// Related
#include "GPIO-to-queue-manager.h"
// C standard
#include <stdio.h>
// C++ standard
// Library
// Project
#include "biketrics-common.h"
#include "biketrics-logger.h"

///
GPIOToQueueManager* GPIOToQueueManager::instance = 0;

///
///
///
GPIOToQueueManager* GPIOToQueueManager::getInstance() {
  if (instance == 0) {
    instance = new GPIOToQueueManager();
  }
  return instance;
}

///
///
///
QueueHandle_t GPIOToQueueManager::createQueue(uint32_t GPIO, uint32_t qSize, 
    uint32_t dataSize) {
  QueueHandle_t q = xQueueCreate(qSize, dataSize);
  if(q == 0) {
    LOGE(kClassName_, ("Queue creation failed for GPIO=%u\n", GPIO));
  } else {
    if(GPIOQueueMap.insert(GPIOQueuePair_T(GPIO, q)).second == false) {
      LOGE(kClassName_, ("Insertion into map failed for GPIO=%u, "
          "deleting queue...\n", GPIO));
      vQueueDelete(q);
      q = 0;
    } else {
      LOGD(kClassName_, ("Successfully created queue for GPIO=%u ("
          "qSize=%u, dataSize=%u)\n", GPIO, qSize, dataSize));
    }
  }
  return q;
}

///
///
///
QueueHandle_t GPIOToQueueManager::getQueueForGPIO(uint32_t GPIO) {
  GPIOToQueueMapIt_T it = GPIOQueueMap.find(GPIO);
  if(it == GPIOQueueMap.end()) {
    LOGW(kClassName_, ("Queue not found for GPIO=%u\n", GPIO));
    return 0;
  }
  return it->second;
}

///
///
///
void GPIOToQueueManager::printMap() {
  GPIOToQueueMapIt_T it;
  for (it=GPIOQueueMap.begin(); it != GPIOQueueMap.end(); ++it) {
    LOGD(kClassName_, ("GPIO=%u, q=%d\n", it->first, (int)it->second));
  }
}

///
///
///
GPIOToQueueManager::GPIOToQueueManager()
    : kClassName_("GPIOToQueueManager") {}

///
///
///
GPIOToQueueManager::~GPIOToQueueManager() {}