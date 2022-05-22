// Related
#include "biketrics-logger.h"
// C standard
// C++ standard
// Library
// Project

///
///
///
const char* logLevelToStr(LogLevel logLevel) {
  switch (logLevel)
  {
  case ERROR:
    return kErrorStr;
    break;
  case WARNING:
    return kWarningStr;
    break;
  case INFO:
    return kInfoStr;
    break;    
  case DEBUG:
    return kDebugStr;
    break;    
  case VERBOSE:
    return kVerboseStr;
    break;
  case UNKNOWN:
  default:
    return kUnknownStr;
    break;
  }
}