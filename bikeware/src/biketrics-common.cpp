// Related
#include "biketrics-common.h"
// C standard
// C++ standard
// Library
// Project

///
///
///
const char* locationToString(Location location) {
  switch (location)
  {
  case FRONT:
    return kFrontStr;
    break;
  case CENTER:
    return kCenterStr;
    break;
  case REAR:
    return kRearStr;
    break;
  case NOT_APPLICABLE:
  default:
    return kNotApplicableStr;
    break;
  }
}