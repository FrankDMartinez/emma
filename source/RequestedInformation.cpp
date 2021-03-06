//===--- RequestedInformation.cpp - Requested Information Utilities ---===//
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
// Functionality related to determining requested information.
// Analyzes information passed to the application and determines
// how the application should act.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "RequestedInformation.h"

namespace RequestedInformation {
  // Parses given options; `argc` and `argv` are the arguments
  // from `main()`.
  Emma::RawParsedOptions parseOptions(int argc, char **argv);

  Emma::RunState determine(int argc, char **argv) {
    Emma::RawParsedOptions raw_options = parseOptions(argc, argv);
    return Emma::RunState(raw_options);
  }

  Emma::RawParsedOptions parseOptions(int argc, char **argv) {
    const std::string usage =
    R"(Usage:
        emma (-h | --help)
        emma options...

        Options:
          -h --help                                   Show this screen.
          --use-seed=<#>                              The seed to pass to the PRNG function [default: a number representing the current time].
          --number-of-elections=<#>                   Number of elections to simulate [default: 1].
          --number-of-candidates=<#>                  Number of Candidates in each election [default: 3].
          --number-of-voters=<#>                      Number of Voters in each election [default: 64].
          --check-condorcet-agreement=yes|no          Check each method for agreement with the Condorcet Candidate [default: yes].
          --check-true-condorcet-agreement=<yes|no>   Check each method for agreement with the True Condorcet Candidate [default: yes].
          --test                                      Perform diagnostic testing.
          --verbose                                   Activate verbosity.
    )";
    Emma::RawParsedOptions raw_options = docopt::docopt(usage,
                                              { argv + 1, argv + argc },
                                              true);
    if (raw_options["--verbose"].asLong() == 1) {
      std::cout << "parsing given options: success" << std::endl;
    }
    return raw_options;
  }
}
