// Related
#include "pin-to-queue-manager.h"
// C standard
#include <stdio.h>
// C++ standard
// Library
// Project
#include "biketrics-common.h"
#include "biketrics-logger.h"

///
PinToQueueManager* PinToQueueManager::instance = 0;

///
///
///
PinToQueueManager* PinToQueueManager::getInstance() {
  if (instance == 0) {
    instance = new PinToQueueManager();
  }
  return instance;
}

///
///
///
QueueHandle_t PinToQueueManager::createQueue(uint32_t pin, uint32_t qSize, 
    uint32_t dataSize) {
  QueueHandle_t q = xQueueCreate(qSize, dataSize);
  if(q == 0) {
    LOGE(kClassName_, ("Queue creation failed for pin=%u\n", pin));
  } else {
    if(pinQueueMap.insert(PinQueuePair_T(pin, q)).second == false) {
      LOGE(kClassName_, ("Insertion into map failed for pin=%u, "
          "deleting queue...\n", pin));
      vQueueDelete(q);
      q = 0;
    } else {
      LOGD(kClassName_, ("Successfully created queue for pin=%u ("
          "qSize=%u, dataSize=%u)\n", pin, qSize, dataSize));
    }
  }
  return q;
}

///
///
///
QueueHandle_t PinToQueueManager::getQueueForPin(uint32_t pin) {
  PinToQueueMapIt_T it = pinQueueMap.find(pin);
  if(it == pinQueueMap.end()) {
    LOGW(kClassName_, ("Queue not found for pin=%u\n", pin));
    return 0;
  }
  return it->second;
}

///
///
///
void PinToQueueManager::printMap() {
  PinToQueueMapIt_T it;
  for (it=pinQueueMap.begin(); it != pinQueueMap.end(); ++it) {
    LOGD(kClassName_, ("pin=%u, q=%d\n", it->first, it->second))
  }
}

///
///
///
PinToQueueManager::PinToQueueManager()
    : kClassName_("PinToQueueManager") {}

///
///
///
PinToQueueManager::~PinToQueueManager() {}