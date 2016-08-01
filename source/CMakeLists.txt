cmake_minimum_required (VERSION 3.3.1)
project (EMMA)
add_executable(emma
  Candidate.cpp
  Candidate.h
  CondorcetCandidate.cpp
  CondorcetCandidate.h
  Copyright.cpp
  Copyright.h
  Data.cpp
  Data.h
  Election.cpp
  Election.h
  EMMA.cpp
  EMMA.h
  GivenData.cpp
  GivenData.h
  IndividualElectionStatistics.cpp
  IndividualElectionStatistics.h
  Introduction.cpp
  Introduction.h
  License.cpp
  License.h
  OverviewStatistics.cpp
  OverviewStatistics.h
  Printing.cpp
  Printing.h
  Pseudorandom.cpp
  Pseudorandom.h
  RawParsedOptions.h
  RequestedInformation.cpp
  RequestedInformation.h
  Results.cpp
  Results.h
  RunMode.cpp
  RunMode.h
  RunState.cpp
  RunState.h
  StatisticsRequired.cpp
  StatisticsRequired.h
  Title.cpp
  Title.h
  TranslateOption.cpp
  TranslateOption.h
  Utilities.cpp
  Utilities.h
  Verify.h
  Voter.cpp
  Voter.h
  # from the docopt project
  docopt/docopt.cpp
  docopt/docopt.h
  docopt/docopt_private.h
  docopt/docopt_util.h
  docopt/docopt_value.h
  )

target_compile_features(emma PRIVATE cxx_generalized_initializers)
