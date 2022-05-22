#ifndef PIN_TO_QUEUE_MANAGER_H_
#define PIN_TO_QUEUE_MANAGER_H_

// Related
// C standard
#include <stdio.h>
#include <stdlib.h>
#include <map>
// C++ standard
// Library
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
// Project

/// A central manager for all sensor queues. Ultimately, this class maps pins to 
/// sensor queues, so that when an interrupt/event occurs on a partiular pin, 
/// the corresponding data can be put on the appropriate queue.
/// NOTE: This class is a singleton!
class PinToQueueManager {
 public:
  ///
  ///
  ///
  static PinToQueueManager* getInstance();

  ///
  ///
  ///
  QueueHandle_t createQueue(uint32_t pin, uint32_t size, uint32_t dataSize);

  ///
  ///
  ///
  QueueHandle_t getQueueForPin(uint32_t pin);

  ///
  ///
  ///
  void printMap();

 private:
  ///
  typedef std::map<uint32_t, QueueHandle_t> PinToQueueMap_T;
  typedef std::pair<uint32_t, QueueHandle_t> PinQueuePair_T;
  typedef PinToQueueMap_T::iterator PinToQueueMapIt_T;

  /// Class name for printing/logging.
  const char* kClassName_;

  ///
  ///
  ///
  PinToQueueManager();

  ///
  ///
  ///
  ~PinToQueueManager();

  ///
  static PinToQueueManager* instance;

  ///
  PinToQueueMap_T pinQueueMap;
};

#endif // PIN_TO_QUEUE_MANAGER_H_