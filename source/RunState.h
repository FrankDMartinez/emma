//===--- RunState.h - "Run State" Related Typing ---===//
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
// Typing relating to the "run state" of the application.
// Keeps track of the mode in which the application runs, the
// statistics to collect, and the basic data needed for the
// application run.
//
//===----------------------------------------------------------------------===//

#include <map>
#include "docopt/docopt.h"
#include "GivenData.h"
#include "RunMode.h"
#include "StatisticsRequired.h"

namespace Emma {
  // Tracks the mode in which the application runs and the
  // statistics to collect
  class RunState {
    // The data passed to the application
    GivenData basic_data;
    // The mode(s) in which the application runs
    RunMode mode;
    // A record of what statistics to collect
    StatisticsRequired statistics;
  public:
    // Standard constructor
    RunState(const RawParsedOptions rpo);
    // Returns the data passed to the application
    GivenData getGivenData() const;
    // Returns the mode(s) in which the application runs
    RunMode getMode() const;
    // Returns a record of what statistics to collect
    StatisticsRequired getRequiredStatistics() const;
  };
}
