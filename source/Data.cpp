//===--- Data.cpp - Serialized and Generated Data Utilities ---===//
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
// Functionality related to generated and serialized data.
// Used for testing generation/comparison and for general
// election simulation.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "Data.h"
#include "Election.h"

namespace Data {
  namespace Serialized {
    void compareGeneratedData() {
      std::cout << "compare generated data with serialized data if required, reporting any difference" << std::endl;
    }
    void load(const Emma::RunState* state) {
      std::cout << "Note: Deserialization of data is not available in this release" << std::endl;
    }
    void unload() {
      std::cout << "Note: Serialization of data is not available in this release" << std::endl;
    }
  }
  namespace Generated {
    typedef std::vector<Simulation::Election> Scenarios;

    // Returns election scenarios, complete with Voters,
    // Candidate utilities, and elected Candidates according to
    // various electoral methods
    static Scenarios runSimulations(const Emma::RunState* state);

    void generate(const Emma::RunState* state) {
      std::cout << "generate data:" << std::endl;
      auto simulations = runSimulations(state);
      std::cout << "\tcollect statistics from simulations" << std::endl;
    }

    // Identifies the Condorcet Candidate based on Each Voter's
    // perceived utilities of the Candidates and stores this
    // information as a characteristic of the given election
    static void identifyTraditionalCondorcetCandidate(Simulation::Election* election);

    // Identifies the Condorcet Candidate based on Each Voter's
    // actual utilities of the Candidates and stores this
    // information as a characteristic of the given election
    static void identifyTrueCondorcetCandidate(Simulation::Election* election);

    // Identifies the Condorcet and True Condorcet Candidates in
    // the given election and stores this information therein
    static void identifyCondorcetCandidates(Simulation::Election* election) {
        std::cout << "\tdetermine the Condorcet Candidate" << std::endl;
        identifyTraditionalCondorcetCandidate(election);
        std::cout << "\tdetermine the True Condorcet Candidate" << std::endl;
        identifyTrueCondorcetCandidate(election);
    }

    static void identifyTraditionalCondorcetCandidate(Simulation::Election* election) {
        std::cout << "\t\tfor Each Voter:" << std::endl;
        std::cout << "\t\t\tobtain Their relationships to the Candidates" << std::endl;
        std::cout << "\t\t\tsort the Candidates according to Their perceived utilities" << std::endl;
        std::cout << "\t\t\trun C*(C+1)/2 1-on-1 elections, tallying these comparisons" << std::endl;
        std::cout << "\t\tif there is a Candidate winning C-1 1-on-1 comparisons:" << std::endl;
        std::cout << "\t\t\tstore that Candidate's identifier in the `Election` as the Condorcet Candidate" << std::endl;
    }

    static void identifyTrueCondorcetCandidate(Simulation::Election* election) {
        std::cout << "\t\tfor Each Voter:" << std::endl;
        std::cout << "\t\t\tobtain Their relationships to the Candidates" << std::endl;
        std::cout << "\t\t\tsort the Candidates according to Their actual utilities" << std::endl;
        std::cout << "\t\t\trun C*(C+1)/2 1-on-1 elections, tallying these comparisons" << std::endl;
        std::cout << "\t\tif there is a Candidate winning C-1 1-on-1 comparisons:" << std::endl;
        std::cout << "\t\t\tstore that Candidate's identifier in the `Election` as the True Condorcet Candidate" << std::endl;
    }

    static Scenarios runSimulations(const Emma::RunState* state) {
      Scenarios all_scenarios;
      const double honesty_fraction = 1;
      for (unsigned election_number = 0;
           state->getGivenData().numberOfElections() > election_number;
           election_number++) {
        Simulation::Election election = Simulation::Election(state->getGivenData().numberOfVoters(),
                                                             state->getGivenData().numberOfCandidates(),
                                                             honesty_fraction);
        identifyCondorcetCandidates(&election);
        std::cout << "\tapply each voting method to the current election scenario" << std::endl;
        all_scenarios.push_back(election);
      }
      return all_scenarios;
    }
  }
}
