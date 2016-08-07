//===--- GivenData.cpp - "Given Data" Related Typing ---===//
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
// Typing relating to the data given to the application.
// Keeps track of the basic data needed for the application run.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "GivenData.h"
#include "TranslateOption.h"

namespace Emma {
  GivenData::GivenData() {}
  GivenData::GivenData(RawParsedOptions rpo) {
    number_of_candidates =
      translateOption(rpo,
                      "--number-of-candidates",
                      number_of_candidates);
    number_of_elections =
      translateOption(rpo,
                      "--number-of-elections",
                      number_of_elections);
    number_of_voters =
      translateOption(rpo,
                      "--number-of-voters",
                      number_of_voters);
    prng_seed = translateOption(rpo, "--use-seed", prng_seed);
    if (rpo["--verbose"].asLong() == 1) {
      std::cout << "parsing given data: success" << std::endl;
    }
  }
  unsigned GivenData::numberOfCandidates() const {
    return number_of_candidates;
  }
  unsigned GivenData::numberOfElections() const {
    return number_of_elections;
  }
  unsigned GivenData::numberOfVoters() const {
    return number_of_voters;
  }
  unsigned GivenData::seedForPRNG() const {
    return prng_seed;
  }
}
