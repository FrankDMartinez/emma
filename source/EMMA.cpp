//===--- EMMA.cpp - Application Entry Point For EMMA ---===//
//
// This file is part of the Election Method Mathematics
// Application (EMMA) project.
//
// Copyright (c) 2015 - 2016 Frank D. Martinez and the EMMA
// project authors
//
// Licensed under the GNU Affero General Public License, version
// 3.0.
//
// See the file called "LICENSE" included with this distribution
// for license information.
//
//===------------------------------------------------------===//
//
// Entry point for the application.
// Every run of this application is guaranteed to pass thru
// here.
//
//===------------------------------------------------------===//

#include "EMMA.h"

int main(int argc, char **argv) {
  Introduction::display();
  Emma::RunState state = RequestedInformation::determine(argc, argv);
  Data::Serialized::load();
  Data::Generated::generate();
  Data::Serialized::compareGeneratedData();
  Data::Serialized::unload();
  Results::output();
  return 0;
}
