//===--- TranslateOption.h - "Translating Raw Options" Related Functionality ---===//
//
// This file is part of the Election Method Mathematics
// Application (EMMA) project.
//
// Copyright (c) 2015 - 2016 Frank D. Martinez and the EMMA project authors
// Licensed under the GNU Affero General Public License, version 3.0.
//
// See the file called "LICENSE" included with this distribution
// for license information.
//
//===----------------------------------------------------------------------===//
//
// Functionality relating to translating raw options.
// Translates the raw options given to the application.
//
//===----------------------------------------------------------------------===//

#include <string>
#include "RawParsedOptions.h"

namespace Emma {
  // Translates the named `option` as recorded in the
  // `RawParsedOptions` into a useful value, returning it if
  // practical, or returning the `default_value` if not; at this
  // point in time, if the given option is valid, it associated
  // value will be a single integer represented by a string
  unsigned translateOption(RawParsedOptions rpo, const std::string option, unsigned default_value);
}
