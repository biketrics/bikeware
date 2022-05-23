#ifndef BIKETRICS_LOGGER_H_
#define BIKETRICS_LOGGER_H_

// Related
// C standard
// C++ standard
// Library
// Project
#include "biketrics-common.h"

/// Enable/disable printing and/or logging at each log level
#define NO_PRINTING              FALSE
#define NO_LOGGING               FALSE
#define SUPPRESS_ERROR_LOGGING   FALSE
#define SUPPRESS_WARNING_LOGGING FALSE
#define SUPPRESS_INFO_LOGGING    FALSE
#define SUPPRESS_DEBUG_LOGGING   FALSE
#define SUPPRESS_VERBOSE_LOGGING FALSE

///
///
///
enum LogLevel {
  ERROR,
  WARNING,
  INFO,
  DEBUG,
  VERBOSE,
  UNKNOWN
};

/// Log level strings
const char* const kErrorStr   = "ERROR";
const char* const kWarningStr = "WARNING";
const char* const kInfoStr    = "INFO";
const char* const kDebugStr   = "DEBUG";
const char* const kVerboseStr = "VERBOSE";

///
///
///
const char* logLevelToStr(LogLevel logLevel);

/// Print and log macros
#define PRINT(x) printf x ; fflush(stdout);
#define LOG(level, class, x) \
    printf("[%-7s][%s]", logLevelToStr(level), class); printf x; fflush(stdout)

/// Enable/disable printing/logging
#if NO_PRINTING == TRUE
  #define PRINT(x) (void)0
#endif
#if NO_LOGGING == TRUE
  #define LOG(level, class, x) (void)0
#endif

/// Log level macros
#define LOGE(class, x) LOG(ERROR,   class, x)
#define LOGW(class, x) LOG(WARNING, class, x)
#define LOGI(class, x) LOG(INFO,    class, x)
#define LOGD(class, x) LOG(DEBUG,   class, x)
#define LOGV(class, x) LOG(VERBOSE, class, x)
#if SUPPRESS_ERROR_LOGGING == TRUE
  #define PRINT(x) (void)0
#endif
#if SUPPRESS_ERROR_LOGGING == TRUE
  #define PRINT(x) (void)0
#endif
#if SUPPRESS_ERROR_LOGGING == TRUE
  #define PRINT(x) (void)0
#endif
#if SUPPRESS_ERROR_LOGGING == TRUE
  #define PRINT(x) (void)0
#endif
#if SUPPRESS_ERROR_LOGGING == TRUE
  #define PRINT(x) (void)0
#endif

#endif // BIKETRICS_LOGGER_H_