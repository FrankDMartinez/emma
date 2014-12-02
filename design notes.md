Design Notes
============

Introduction
------------
The purpose of this document is to provide an overview of how the election method mathematics application (a.k.a., `emma`) is intended to work and preliminary guidelines for implementation. `emma` simulates elections using differenerent voting methods to quantitaties compare different elections using the "Bayesian Regret" methodology as described in the appendix, enabling One to use such results in whatever fashion One sees fit.

Overview
--------
The application has three phases with various numbers of sub-phases and nested sub-phases:
  1. Analysis
    1. Election simulations
      1. Utility generation
        1. Actual utility generation
        1. Perceived utility generation
      1. Determining which Voters are honest and which are "strategic"
      1. Vote casting according to the various election methods and/or honesty/strategy
    1. Bayesian Regret analysis
      1. Bayesian Regret determinations for each election method
        1. Individual Bayesian Regret determination
        1. Collective Bayesian Regret determination
      1. Bayesian Regret based determinations for each election method
        1. Arithmetic mean of Individual Bayesian Regrets determination
        1. Standard deviation of Individual Bayesian Regrets determination
        1. Geometric mean of Individual Bayesian Regrets determination
        1. Geometric standard deviation of Individual Bayesian Regrets determination
        1. Collective Bayesian Regret per Voter determination
    1. Condorcet analysis
      1. Agreement with Condorcet election
      1. Agreement with "True Condorcet" election
  1. Sorting analysis by selected criteria
  1. Output of analysis results

System Architecture
-------------------

Data Design
-----------

Component Design
----------------

Interface Design
----------------

Requirements
------------

Appendix
----------
######Bayesian Regret######

According to the Center for Range Voting, "Bayesian Regret" is defined as "the 'expected avoidable human unhappiness' caused by using [a particular election method]" and the Bayesian Regret of a particular election method can be determined thusly:

1. Presume Each Voter has a personal "utility value" for the election of Each Candidate. For example, if Candidate Smith is elected, then Voter Jones will acquire a certain number of extra "lifetime happiness units".
1. Voters cast votes based both on these personal "utility values" and, if They are so-called "strategic" Voters, on a particular strategy.
1. The election system elects a Candidate.
1. The sum over All Voters of Their "utility values" for the elected Candidate is the "achieved societal utility."
1. The sum over All Voters of Their "utility values", maximized over All Candidates, is the "optimum societal utility" which would have been achieved if the election system had magically chosen the societally best Candidate. In other words, find the "utility value" of the Candidate which has the highest summed "utility value" across Voters; that value is the "optimum societal utility".
1. The difference between the "optimum societal utility" and the "achieved societal utility" is the "Bayesian Regret" of the election system in this experiment. If the election method chooses the societally best Candidate, this value will be zero; otherwise, it will be positive because the elected Candidate and the societally best Candidate will differ.
