//===--- IndividualElectionStatistics.h - "Statistics for Each Election" Related Typing ---===//
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
// Typing relating to statistics for each method in each
// election the application should gather.
// Keeps track of which information about each method for each
// election the application should collect.
//
//===----------------------------------------------------------------------===//

namespace Emma {
  // Tracks what information about each method for each election
  // the application should collect
  class IndividualElectionStatistics {
    // collect the method’s Bayesian Regret for each election
    bool _BayesianRegret = true;
    // collect the method’s Bayesian Regret per Voter for each
    // election
    bool _BayesianRegretPerVoter = false;
    // collect Condorecet Candidate agreement of each method for
    // each election
    bool _CondorcetCandidate = false;
    // collect the Individual Bayesian Regret produced by each
    // method for each election
    bool _IBR = false;
    // collect the arithmetic mean of the IBRs produced by each
    // method for each election
    bool meanIBR = false;
    // collect the fraction of Voters for Whom each method
    // resulted in the least Individual Bayesian Regret for each
    // election
    bool leastIBRFraction = false;
    // collect the standard deviation of the IBRs produced by
    // each method for each election
    bool standardDeviationOfIBR = false;
    // collect True Condorecet Candidate agreement of each
    // method for each election
    bool trueCondorcetCandidate = false;
  public:
    // whether to collect the method’s Bayesian Regret for each
    // election
    bool collectBayesianRegret() const;
    // whether to collect the method’s Bayesian Regret per Voter
    // for each election
    bool collectBayesianRegretPerVoter() const;
    // whether to collect Condorecet Candidate agreement of each
    // method for each election
    bool collectCondorcetCandidate() const;
    // whether to collect the Individual Bayesian Regret
    // produced by each method for each election
    bool collectIBR() const;
    // whether to collect the fraction of Voters for Whom each
    // method resulted in the least Individual Bayesian Regret
    // for each election
    bool collectLeastIBRFraction() const;
    // whether to collect the arithmetic mean of the IBRs
    // produced by each method for each election
    bool collectMeanIBR() const;
    // whether to collect the standard deviation of the IBRs
    // produced by each method for each election
    bool collectStandardDeviationOfIBR() const;
    // whether to collect True Condorecet Candidate agreement of
    // each method for each election
    bool collectTrueCondorcetCandidate() const;
  };
}
