#ifndef BIKETRICS_LOGGER_H_
#define BIKETRICS_LOGGER_H_

// Related
// C standard
// C++ standard
// Library
// Project
#include "biketrics-common.h"

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
const char* const kUnknownStr = "UNKNOWN";

///
///
///
const char* logLevelToStr(LogLevel logLevel);

/// Print and log macros
#define PRINT(x) printf x ; fflush(stdout);
#define LOG(level, class, x) \
    printf("[%-7s][%s]", logLevelToStr(level), class); printf x; fflush(stdout)

/// Enable/disable print statements
#define NO_PRINTING FALSE
#define NO_LOGGING  FALSE
#if NO_PRINTING == TRUE
  #define PRINT(x) (void)0
#endif
#if NO_LOGGING == TRUE
  #define LOG(level, class, x) (void)0
#endif

#endif // BIKETRICS_LOGGER_H_