//===--- RunState.cpp - "Run State" Related Typing ---===//
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

#include <iostream>
#include "RunState.h"

namespace Emma {
  RunState::RunState(const RawParsedOptions rpo) {
    basic_data = GivenData(rpo);
    _mode = RunMode(rpo);
    statistics = StatisticsRequired(rpo);
  }
  GivenData RunState::getGivenData() const {
    return basic_data;
  }
  RunMode RunState::mode() const {
    return _mode;
  }
  StatisticsRequired RunState::getRequiredStatistics() const {
    return statistics;
  }
}
