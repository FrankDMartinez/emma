//===--- RunMode.h - "Running Mode" Related Typing ---===//
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
// Typing relating to the "running mode" of the application.
// Keeps track of the state of the different modes in which the
// application can run.
//
//===----------------------------------------------------------------------===//

#ifndef EMMA_RUNMODE_H
#define EMMA_RUNMODE_H

#include "RawParsedOptions.h"

namespace Emma {
  // Tracks the basic data needed for the application run
  class RunMode  {
    // Whether or not the application is running in diagnostic
    // testing mode
    bool testing = false;
    // Whether or not the application is running in verbose mode
    bool verbose = false;
  public:
    RunMode();
    RunMode(RawParsedOptions rpo);
    // Returns whether or not the application is running in
    // diagnostic testing mode
    bool isTesting() const;
    // Returns whether or not the application is running in
    // verbose mode
    bool beVerbose() const;
  };
}

#endif
