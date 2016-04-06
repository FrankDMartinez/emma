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

#include "BasicData.h"
#include "CondorcetData.h"
#include "RunMode.h"
#include "StatisticRequired.h"

namespace Emma {
  // Tracks the mode in which the application runs and the
  // statistics to collect
  class RunState {
    BasicData basic_data;
    CondorcetData the_Condorcet_data;
    RunMode mode;
    StatisticRequired statistics;
  };
}
    // Whether or not the application is running in diagnostic
    // testing mode
    bool testing = false;
    // Whether or not the application is running in verbose mode
    bool verbose = false;
