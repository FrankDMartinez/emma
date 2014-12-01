Design Notes
============

Introduction
------------
The purpose of this document is to provide an overview of how the election method mathematics application (a.k.a., `emma`) is intended to work and preliminary guidelines for implementation. `emma` simulates elections using differenerent voting methods to quantitaties compare different elections using the "Bayesian Regret" methodology as described in the appendix, enabling One to use such results in whatever fashion One sees fit.

Overview
--------

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
1. The sum over All Voters of Their "utility values", maximized over All Candidates, is the "optimum societal utility" which would have been achieved if the election system had magically chosen the societally best Candidate.
1. The difference between the "optimum societal utility" and the "achieved societal utility" is the "Bayesian Regret" of the election system in this experiment. If the election method chooses the societally best Candidate, this value will be zero; otherwise, it will be positive because the elected Candidate and the societally best Candidate will differ.
