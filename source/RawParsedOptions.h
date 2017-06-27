//===--- RawParsedOptions.h - "Raw Parsed Options" Related Typing ---===//
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
// Typing relating to options after they have been parsed.
// Holds the raw information of those options so they can be
// used in a meaningful way.
//
//===----------------------------------------------------------------------===//

#ifndef EMMA_RAWPARSEDOPTIONS_H
#define EMMA_RAWPARSEDOPTIONS_H

#include <map>
#include "docopt/docopt.h"

namespace Emma {
  typedef std::map<std::string, docopt::value> RawParsedOptions;
}

#endif
