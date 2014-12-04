Design Notes for the Election Method Mathematics Application (`EMMA`)
============

Overview
------------
The purpose of this program is to simulate elections using different voting methods to quantitatively compare the voting methods using the "Bayesian Regret" and "Individual Bayesian Regret" methodology as described in the appendix, enabling One to use such results in whatever fashion One sees fit.

Requirements
------------
1. The program should simulate elections.
1. The program should vary the number of Candidates in each election.
1. The program should vary the number of Voters in each election.
1. The program should simulate a Candidate's actual utility to Each Voter if that Candidate is elected.
1. The program should vary the way the determination is made of a Candidate's actual utility to Each Voter.
1. The program should simulate Voter ignorance, resulting in a Candidate's utility as perceived by Each Voter before casting votes.
1. The program should vary the fraction of Voters voting honestly versus voting strategically.
1. The program should determine the elected Candidate of a particular election using different voting methods with each method being used on the same 5-dimensional matrix of Candidate count, Voter count, utility determination method, degree of Voter ignorance, and Voter honesty fraction.
1. The program should calculate the Bayesian Regret of each member of the 6-dimensional matrix described in requirement #8.
1. The program should calculate the Bayesian regret per Voter of each member of the 6-dimensional matrix described in requirement #8.
1. The program should calculate the Bayesian Regret of each member of the 6-dimensional matrix described in requirement #8.
1. The program should calculate the Bayesian regret per Voter of each member of the 6-dimensional matrix described in requirement #8.


Architectural Design
-------------------
####Concept of Execution####
####Abstrat Data Types####
####Code Outline####

Detailed Design
----------------

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
