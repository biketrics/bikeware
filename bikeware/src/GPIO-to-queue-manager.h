#ifndef GPIO_TO_QUEUE_MANAGER_H_
#define GPIO_TO_QUEUE_MANAGER_H_

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

/// A central manager for all sensor queues. Ultimately, this class maps GPIOs to 
/// sensor queues, so that when an interrupt/event occurs on a partiular GPIO, 
/// the corresponding data can be put on the appropriate queue.
/// NOTE: This class is a singleton!
/// NOTE: For speed, this class could be re-factored to use a pre-allocated 
/// array where the GPIO number serves as the index and the valued stored in the
/// array is the corresponding queue's address. This was initially 
/// implemented using std::map to give myself practice using this type.
class GPIOToQueueManager {
 public:
  ///
  ///
  ///
  static GPIOToQueueManager* getInstance();

  ///
  ///
  ///
  QueueHandle_t createQueue(uint32_t GPIO, uint32_t size, uint32_t dataSize);

  ///
  ///
  ///
  QueueHandle_t getQueueForGPIO(uint32_t GPIO);

  ///
  ///
  ///
  void printMap();

 private:
  ///
  typedef std::map<uint32_t, QueueHandle_t> GPIOToQueueMap_T;
  typedef std::pair<uint32_t, QueueHandle_t> GPIOQueuePair_T;
  typedef GPIOToQueueMap_T::iterator GPIOToQueueMapIt_T;

  /// Class name for printing/logging.
  const char* kClassName_;

  ///
  ///
  ///
  GPIOToQueueManager();

  ///
  ///
  ///
  ~GPIOToQueueManager();

  ///
  static GPIOToQueueManager* instance;

  ///
  GPIOToQueueMap_T GPIOQueueMap;
};

#endif // GPIO_TO_QUEUE_MANAGER_H_