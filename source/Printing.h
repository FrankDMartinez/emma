//===--- Printing.h - Print Related Functionality ---===//
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
// Functionality relating to general output.
//
//===----------------------------------------------------------------------===//

#ifndef EMMA_PRINTING_H
#define EMMA_PRINTING_H

#include <string>
#include <vector>

namespace Printing {
  // prints the given string in textual form, as opposed to
  // binary form
  void print(std::string);

  // prints the given string value and subsequent arguments in
  // textual form, as opposite to binary form
  template<class... Others>
  static void print(const std::string s, Others... others);

  // Prints the given strings in the given order as one line,
  // moving the printing position to the start of the next line
  // when finished
  void printAsOneLine(std::vector<std::string> strings);

  // Prints each of the given strings on a separate line in the
  // given order
  void printLines(std::vector<std::string> strings);

  // prints the given double value in textual form, as opposite
  // to binary form
  void print(const double);

  // prints the given unsigned value in textual form, as
  // opposite to binary form
  void print(const unsigned);

  // prints nothing
  void print();

  // prints the given double value and subsequent arguments in
  // textual form, as opposite to binary form
  template<class... Others>
  static void print(const double d, Others... others) {
    print(d);
    print(others...);
  }

  // prints the given unsigned value and subsequent arguments in
  // textual form, as opposite to binary form
  template<class... Others>
  static void print(const unsigned u, Others... others) {
    print(u);
    print(others...);
  }

  template<class... Others>
  static void print(const std::string s, Others... others) {
    print(s);
    print(others...);
  }

  // Prints the given arguments in the given order as one line,
  // moving the printing position to the start of the next line
  // when finished
  template<class... Others>
  static void printAsOneLine(std::string s, Others... others) {
    print(s);
    print(others...);
    print("\n");
  }

  // Prints the given arguments in the given order as one line,
  // moving the printing position to the start of the next line
  // when finished
  template<class... Others>
  static void printAsOneLine(const char* s, Others... others) {
    std::string the_string = s;
    print(s, others...);
    print("\n");
  }
}

#endif
