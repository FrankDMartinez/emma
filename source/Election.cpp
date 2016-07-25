//===--- Election.cpp - Information About A Single Election ---===//
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
// A collection of information about a particular election, such
// as Voters and Candidates
//
//===----------------------------------------------------------------------===//

#include "Election.h"
#include <cfenv>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include "Printing.h"
#include "Pseudorandom.h"
#include "Verify.h"

namespace Simulation {
  Election::Election(const unsigned count_of_Voters,
                     const unsigned count_of_Candidates,
                     const double honest_Voters)
    : number_of_Voters(count_of_Voters),
      number_of_Candidates(count_of_Candidates),
      honesty_fraction(honest_Voters) {
    createElectorate();
    setElectorateHonesty();
    determineOptimumCandidate();
  }

  unsigned Election::ballotSize() const {
    return number_of_Candidates;
  }

  void Election::createElectorate() {
    for (unsigned Voter_number = 0;
         Voter_number < electorateSize();
         Voter_number++) {
        Voter a_Voter(number_of_Candidates);
        the_electorate.push_back(a_Voter);
    }
  }

  double Election::sumActualUtilitiesOfCandidate(const unsigned identifier) {
    double sum = 0.;
    for (unsigned Voter_index = 0;
         electorateSize() > Voter_index;
         Voter_index++) {
      const Voter* single_Voter = getVoter(Voter_index);
      CandidateUtilities the_Candidate =
        single_Voter->getCandidate(identifier);
      sum += the_Candidate.getActualUtility();
    }
    return sum;
  }

  // Returns the maximum value in the given `std::unordered_map`
  template <class Key, class Value>
  static Value findMaxValue(std::unordered_map<Key,Value> um) {
    using pair_type = typename decltype(um)::value_type;
    auto pr = std::max_element
      (
        std::begin(um),
        std::end(um),
        [] (const pair_type & p1, const pair_type & p2) {
          return p1.second < p2.second;
        }
      );
    return pr->second;
  }

  // Returns a collection of `Key` objects with the given `Value`
  template <class Key, class Value>
  static std::set<Key>
  findKeysSorted(std::unordered_map<Key,Value> um,
                 const Value v) {
    std::set<Key> the_set;
    for (const auto each : um ) {
      if (v == each.second) {
        auto lambda = [the_set, each] () {
          std::string key_string = std::to_string(each.first);
          std::string value_string = std::to_string(each.second);
          Printing::printAsOneLine({"duplicate entry for: ",
                                    key_string,
                                    ", ",
                                    value_string});
          Printing::printLines({"existing entries:"});
          for (auto each_key : the_set) {
            std::string entry_string = std::to_string(each_key);
            Printing::printAsOneLine({"\t", entry_string});
          }
        };
        Verify::ensure(the_set.insert(each.first).second == true,
                       2,
                       &lambda);
      }
    }
    return the_set;
  }

  void Election::determineOptimumCandidate() {
    std::unordered_map<unsigned, double> utilities;
    for (unsigned Candidate_identifier = 0;
         ballotSize() > Candidate_identifier;
         Candidate_identifier++) {
      utilities[Candidate_identifier] =
        sumActualUtilitiesOfCandidate(Candidate_identifier);
    }
    double max_value = findMaxValue(utilities);
    std::set<unsigned> the_Candidates =
      findKeysSorted(utilities, max_value);
    if (the_Candidates.size() == 1) {
      setSocietallyOptimumCandidate(*(the_Candidates.begin()));
    }
  }

  unsigned Election::electorateSize() const {
    return number_of_Voters;
  }

  Voter* Election::getVoter(unsigned index) {
    return &(the_electorate[index]);
  }

  unsigned Election::numberOfStrategicVotersNeeded() const {
    unsigned number_of_honest_Voters =
      (unsigned) std::rint(electorateSize() * honesty_fraction);
    return electorateSize() - number_of_honest_Voters;
  }

  void Election::setElectorateHonesty() {
    const unsigned number_of_strategic_Voters =
      numberOfStrategicVotersNeeded();
    const std::vector<unsigned> strategic_Voter_indicies =
      strategicVoterIndices(number_of_strategic_Voters);
    for (auto each : strategic_Voter_indicies) {
      getVoter(each)->makeStrategic();
    }
  }

  void Election::setSocietallyOptimumCandidate(const unsigned identifier) {
    societally_optimum_Candidate = identifier;
  }

  std::vector<unsigned> Election::strategicVoterIndices(const unsigned strategic_count) {
    std::vector<unsigned> indices;
    for (unsigned count = 0; count < electorateSize(); count++) {
      indices.push_back(count);
    }
    std::shuffle(indices.begin(),
                 indices.end(),
                 Pseudorandom::prn_generator);
    return std::vector<unsigned>(indices.begin(), indices.begin() + strategic_count);
  }
}
