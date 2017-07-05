//===--- Verify.h - Utilities to ensure expectations are met ---===//
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
// A collection of utilities to help ensure expectations are met
//
//===----------------------------------------------------------------------===//

#include "Printing.h"

#include <iostream>

namespace Verify {
  template <class... Others>
  static void outputForEnsure(const unsigned first, Others... others);

  template <class... Others>
  static void outputForEnsure(std::vector<Simulation::Candidate>, Others... others);

  static void outputForEnsure() {}

  static void outputForEnsure(Simulation::Candidate the_Candidate) {
    std::cout << "Candidate: { _designation = "
              << the_Candidate.designation()
              << ", _utilities = { _actual = "
              << the_Candidate.utilities()->actualUtility()
              << ", _perceived = "
              << the_Candidate.utilities()->perceivedUtility()
              << " } }"
              << std::endl;
  }

  template <class... Others>
  static void outputForEnsure(const std::string first, Others... others) {
    std::cout << first;
    outputForEnsure(others...);
  }

  template <class... Others>
  static void outputForEnsure(std::vector<Simulation::Candidate> Candidates, Others... others) {
    std::cout << "All Candidates:" << std::endl;
    for (auto each : Candidates) {
      outputForEnsure(each);
    }
    outputForEnsure(others...);
  }

  template <class... Others>
  static void outputForEnsure(const unsigned first, Others... others) {
    std::string text = std::to_string(first);
    std::cout << text;
    outputForEnsure(others...);
  }

  template <class... Arguments>
  static void ensure(const bool condition_met,
                     const int error_number,
                     Arguments... arguments) {
    if (condition_met == false) {
      std::string error_string = std::to_string(error_number);
      Printing::printAsOneLine("internal error #",
                               error_string);
      outputForEnsure(arguments...);
      Printing::printAsOneLine("'EMMA' will shut down now");
      std::exit(0);
    }
  }
}
