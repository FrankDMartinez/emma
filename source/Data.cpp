//===--- Data.cpp - Generated Data Utilities ---===//
//
// This file is part of the Election Method Mathematics Application (EMMA) project.
//
// Copyright (c) 2015 - 2016 Frank D. Martinez and the EMMA project authors
// Licensed under the GNU Affero General Public License, version 3.0.
//
// See the file called "LICENSE" included with this distribution for license information.
//
//===----------------------------------------------------------------------===//
//
// Functionality related to generated data.
// Used for testing generation/comparison and for general
// election simulation.
//
//===----------------------------------------------------------------------===//

#include "Data.h"

#include "Logging.h"
#include "Printing.h"
#include "RunState.h"

#include <iostream>

namespace Data {
// Returns election scenarios, complete with Voters,
// Candidate utilities, and elected Candidates according to
// various electoral methods
static Scenarios runSimulations(const Emma::RunState& state);

Scenarios generate(const Emma::RunState& state) {
  Logging::log(state, "generating data");
  Scenarios simulations = runSimulations(state);
  std::cout << "\tcollect statistics from simulations" << std::endl;
  return simulations;
}

// Identifies the Condorcet Candidate based on Each Voter's
// perceived utilities of the Candidates and stores this
// information as a characteristic of the given election
static void identifyTraditionalCondorcetCandidate(Simulation::Election* election);

// Identifies the Condorcet and True Condorcet Candidates in
// the given election and stores this information therein
static void identifyCondorcetCandidates(Simulation::Election* election) {
    std::cout << "\tdetermine the Condorcet Candidate" << std::endl;
    identifyTraditionalCondorcetCandidate(election);
}

static void identifyTraditionalCondorcetCandidate(Simulation::Election* election) {
    std::cout << "\t\tfor Each Voter:" << std::endl;
    std::cout << "\t\t\tobtain Their relationships to the Candidates" << std::endl;
    std::cout << "\t\t\tsort the Candidates according to Their perceived utilities" << std::endl;
    std::cout << "\t\t\trun C*(C+1)/2 1-on-1 elections, tallying these comparisons" << std::endl;
    std::cout << "\t\tif there is a Candidate winning C-1 1-on-1 comparisons:" << std::endl;
    std::cout << "\t\t\tstore that Candidate's identifier in the `Election` as the Condorcet Candidate" << std::endl;
}

static Scenarios prepareElections(const Emma::RunState& state) {
  Scenarios all_scenarios;
  const double honesty_fraction = 1;
  for (unsigned election_number = 0;
       state.getGivenData().numberOfElections() > election_number;
       election_number++) {
    Logging::log(state, "preparing simulation #", election_number);
    Simulation::Election election{ state.getGivenData().numberOfVoters(),
                                   state.getGivenData().numberOfCandidates(),
                                   honesty_fraction,
                                   state.mode().beVerbose() };
    all_scenarios.push_back(election);
  }
  return all_scenarios;
}

template<typename T>
void for_each_with_index(T& container,
                         std::function<void(typename T::value_type&, unsigned)> op) {
  unsigned idx = 0;
  for(auto& value : container) {
    op(value, idx);
    ++idx;
  }
}

static Scenarios runSimulations(const Emma::RunState& state) {
  Logging::log(state, "running simulations");
  Scenarios all_scenarios = prepareElections(state);
  auto runOneSimulation =
    [&state](Simulation::Election& the_election, unsigned index) {
      Logging::log(state, "running simulation #", index);
      identifyCondorcetCandidates(&the_election);
      std::cout << "\tapply each voting method to the current election scenario" << std::endl;
    };

  for_each_with_index(all_scenarios, runOneSimulation);
  return all_scenarios;
}
}
