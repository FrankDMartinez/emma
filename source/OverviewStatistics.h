//===--- OverviewStatistics.h - "Statistics for Each Method Overall" Related Typing ---===//
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
// Typing relating to statistics for each method overall the
// application should gather.
// Keeps track of which information about each method overall
// the application should collect.
//
//===----------------------------------------------------------------------===//

namespace Emma {
  // Track what information about each method overall the
  // application should collect
  class OverviewStatistics {
    // collect Bayesian Regret statistics for this method from
    // all elections
    bool _BayesianRegret = true;
    // collect standard deviation of Bayesian Regret per Voter
    // from all elections for this method
    bool _BayesianRegretStandardDeviation = true;
    // collect Condorcet agreement rates for this method from
    // all elections
    bool _CondorcetAgreementRates = true;
    // collect the fraction of elections in which this method
    // elects the Condorcet Candidate
    bool _CondorcetCandidateFraction = true;
    // collect IBR statistics for this method from all elections
    bool _IBR = true;
    // collect the standard deviation of the IBRs
    bool _IBRStandardDeviation = true;
    // collect the fraction of elections the particular method
    // results in the least IBR for the largest fraction of
    // Voters
    bool leastIBRFractionForLargestFraction = true;
    // collect the fraction of Voters for Whom the particular
    // voting method resulted in the least IBR
    bool leastIBRFractionOfVoters = true;
    // collect arithmetic mean of Bayesian Regret per Voter from
    // all elections for this method
    bool meanBayesianRegret = true;
    // collect the arithmetic mean of the IBRs from all
    // elections
    bool meanIBR = true;
    // collect the fraction of elections in which this method
    // elects the True Condorcet Candidate
    bool trueCondorcetCandidateFraction = true;
  public:
    // whether to collect Bayesian Regret statistics for this
    // method from all elections
    bool collectBayesianRegret() const;
    // whether to collect standard deviation of Bayesian Regret
    // per Voter from all elections for this method
    bool collectBayesianRegretStandardDeviation() const;
    // whether to collect Condorcet agreement rates for this
    // method from all elections
    bool collectCondorcetAgreementRates() const;
    // whether to collect the fraction of elections in which
    // this method elects the Condorcet Candidate
    bool collectCondorcetCandidateFraction() const;
    // whether to collect IBR statistics for this method from
    // all elections
    bool collectIBR() const;
    // whether to collect the standard deviation of the IBRs
    bool collectIBRStandardDeviation() const;
    // whether to collect the fraction of elections the
    // particular method results in the least IBR for the
    // largest fraction of Voters
    bool collectLeastIBRFractionForLargestFraction() const;
    // whether to collect the fraction of Voters for Whom the
    // particular voting method resulted in the least IBR
    bool collectLeastIBRFractionOfVoters() const;
    // whether to collect arithmetic mean of Bayesian Regret per
    // Voter from all elections for this method
    bool collectMeanBayesianRegret() const;
    // whether to collect the arithmetic mean of the IBRs from
    // all elections
    bool collectMeanIBR() const;
    // whether to collect the fraction of elections in which
    // this method elects the True Condorcet Candidate
    bool collectTrueCondorcetCandidateFraction() const;
  };
}
