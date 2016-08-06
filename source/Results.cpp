//===--- Results.cpp - Results Output Functionality ---===//
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
// Functionality relating to reproting results.
// In general, all functionality will eventually pass thru here
// in the process of outputting results.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "Results.h"
#include "Logging.h"
#include "Printing.h"

namespace Results {
  static void outputElectionNumber(const unsigned election_index);
  static void outputHonestyFraction(const Simulation::Election election);
  static void outputNumberOfCandidates(const Simulation::Election election);
  static void outputNumberOfVoters(const Simulation::Election election);
  static void outputTrueCondorcetData(const Simulation::Election election);

  void output(const Data::Generated::Scenarios* scenarios) {
    std::cout << __func__ << " is not fully implemented yet" << std::endl;
    Logging::log("outputing requested results");
    for (unsigned election_index = 0;
         scenarios->size() > election_index;
         election_index++) {
      outputElectionNumber(election_index);
      outputNumberOfVoters(scenarios->at(election_index));
      outputNumberOfCandidates(scenarios->at(election_index));
      outputHonestyFraction(scenarios->at(election_index));
      outputTrueCondorcetData(scenarios->at(election_index));
    }
  }

  static void outputElectionNumber(const unsigned election_index) {
    Printing::printAsOneLine("Election #", election_index + 1);
  }

  static void outputHonestyFraction(const Simulation::Election election) {
    Printing::printAsOneLine("Honesty fraction: ", election.honestyFraction());
  }

  static void outputNumberOfCandidates(const Simulation::Election election) {
    Printing::printAsOneLine("# of Candidates: ", election.ballotSize());
  }

  static void outputNumberOfVoters(const Simulation::Election election) {
    Printing::printAsOneLine("# of Voters: ", election.electorateSize());
  }

  static void outputTrueCondorcetData(const Simulation::Election election) {
    Simulation::CondorcetCandidate the_Candidate =
      election.theTrueCondorcetCandidate();
    std::string identification_string;
    if (the_Candidate.exists() == true) {
      identification_string = "#";
      identification_string += std::to_string(the_Candidate.identifier());
    } else {
      identification_string = "Does Not Exist";
    }
    Printing::printAsOneLine("True Condorcet Candidate: ",
                             identification_string);
  }
}
