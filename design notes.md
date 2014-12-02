Design Notes
============

Introduction
------------
The purpose of this document is to provide an overview of how the election method mathematics application (a.k.a., `emma`) is intended to work and preliminary guidelines for implementation. `emma` simulates elections using differenerent voting methods to quantitaties compare different elections using the "Bayesian Regret" methodology as described in the appendix, enabling One to use such results in whatever fashion One sees fit.

Overview
--------
The application at this point has three phases:
  1. Analysis, in which elections are simulated under various conditions
  1. Sorting, in which the various election methods are ordered by specified criteria
  1. Output of the sort analysis

System Architecture
-------------------
####Analysis Component####
The analysis component simulates the various elections with various conditions, such as the number of Voters, number of Candidates, method of creating utility values, levels of Voter ignorance, and degree of honesty amongst Voters. A certain number of elections are simulated for each combination of these conditions. Each simulated election is in turn analyzed multiple times, once for each election method, in order to ascertain various Bayesian Regret based data and Condorcet related data.

######Bayesian Regret Based Data######
Bayesian Regret based data will be created for each voting method. This data includes:
1. Bayesian Regret as defined in the appendix
1. Bayesian Regret per Voter
1. Individual Bayesian Regret as defined in the appendix
1. The arithmetic mean of the Individual Bayesian Regret
1. The standard deviation of the Individual Bayesian Regret
1. The geometric mean of the Individual Bayesian Regret
1. The standard geometric mean of the Individual Bayesian Regret
1. The percentage of Voters for Whom the voting method resulted in the least Individual Bayesian Regret

######Condorcet related data######
Condorcet related data will be created for each voting method. This data includes:
1. Whether the voting method elected the Condorcet Candidate
1. Whether the voting method elected the true Condorcet Candidate as defined in the appendix

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

######Individual Bayesian Regret######
Individual Bayesian Regret (IBR) is a concept I have devised which is based on traditional Bayesian Regret. IBR is defined as the sum across All Voters of the differences between the utility value of whichever Candidate has the highest utility to the specific Voter and the utility value of the Candidate selected by the particular voting method. Conceptually, IBR measures the difference between the one "perfect" Candidate satisfying All Voters and the Candidate chosen by the particular voting method.

######True Condorcet Candidate######
While the Condorcet Candidate of an election is the Candidate, when compared with every other Candidate, is preferred by more voters, the "True Condorcet Candidate" is the Candidate, when compared with every other Candidate, has greater actual utility for more Voters.