//===--- StatisticsRequired.h - "Statistics To Gather" Related Typing ---===//
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
// Typing relating to statistics the application should gather.
// Keeps track of which information the application should
// collect.
//
//===----------------------------------------------------------------------===//

#ifndef EMMA_STATISTICSREQUIRED_H
#define EMMA_STATISTICSREQUIRED_H

#include "IndividualElectionStatistics.h"
#include "OverviewStatistics.h"
#include "RawParsedOptions.h"

namespace Emma {
  // Tracks what information the application should collect
  class StatisticsRequired {
    // The statistics for each method to collect in each
    // individual election simulation
    IndividualElectionStatistics each_election;
    // The statistics for each method to collect regarding the
    // overall set of election simulations
    OverviewStatistics simulation_wide;
  public:
    StatisticsRequired();
    StatisticsRequired(const RawParsedOptions rpo);
    // Returns the statistics for each method to collect in each
    // individual election simulation
    IndividualElectionStatistics getIndividualElectionStatistics() const;
    // Returns the statistics for each method to collect
    // regarding the overall set of election simulations
    OverviewStatistics getOverviewStatistics() const;
  };
}

#endif
