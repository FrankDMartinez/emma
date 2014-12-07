Design Notes for the Election Method Mathematics Application (`EMMA`)
============

Overview
------------
The purpose of this program is to simulate elections using different voting methods to quantitatively compare the voting methods using the "Bayesian Regret" and "Individual Bayesian Regret" ("IBR") methodology as described in the appendix, enabling One to use such results in whatever fashion One sees fit.

Requirements
------------
1. The program should simulate elections, each consisting of a combination of:
  1. A certain number of Candidates
  1. A certain number of Voters
  1. A certain way to determine a Candidate's actual utility to Each Voter if that Candidate is elected
  1. A certain degree of Voter ignorance, resulting in simulating a Candidate's utility as perceived by Each Voter before casting votes
  1. A certain fraction of Voters voting honestly versus voting strategically
1. The program should determine the elected Candidate(s) of each election using different voting methods with each method being used on the same election combination described above, creating an election/results pair ("E/R") for each election.
1. For each method in an E/R, the program should determine:
  1. The Bayesian Regret
  1. The Bayesian Regret per Voter
  1. The IBR of Each Voter
  1. The arithmetic mean of the IBRs
  1. The standard deviation of the IBRs
  1. The fraction of Voters for Whom the particular voting method resulted in the least IBR
  1. Whether the voting method elects the Condorcet Candidate as defined in the appendix
  1. Whether the voting method elects the True Condorcet Candidate as defined in the appendix
1. For each voting method, the program should calculate:
  1. The fraction of elections the particular method:
    1. Results in the least IBR for the largest fraction of Voters
    1. Elects the Condorcet Candidate
    1. Elects the True Condorcet Candidate
  1. The arithmetic means of:
    1. The Bayesian Regret per Voter from all elections
    1. The IBR of Each Voter from all elections
  1. The standard deviations of:
    1. The Bayesian Regret per Voter
    1. The IBR of Each Voter
  1. The fraction of Voters for Whom the particular voting method resulted in the least IBR

Architectural Design
-------------------
####Concept of Execution####

This program will be a simple command line application with a text only interface. When started, the application will display the title and license information of the application. The application will enter its main execution loop and begin the simulations. Once simulations are complete, the data gathered from the simulations will be analyzed and the results of that analysis sent to the standard output location. If the application is given `--test` as the first argument on the command line, the application will produce test data and results to help verify all processes work as expected.

####Abstrat Data Types####

Each simulated election will be represented by an object indicating:
* The number of Candidates in the election
* The number of Voters in the election
* The way the actual utility of Each Candidate to Each Voter
* The degree of Voter ignorance
* The fraction of Voters voting honestly versus voting strategically
* A collection of statistics for each voting method with respect to this simulated election

Each voting method, with respect to a particular election, will be represented by an object indicating:
* The Candidate elected by that method in that election
* A collection of Bayesian Regret statistics
* A collection of IBR statistics
* Whether the voting method elects the Condorcet Candidate
* Whether the voting method elects the True Condorcet Candidate

Each collection of Bayesian Regret statistics for a particular voting method in a particular election will consist of:
* The method's Bayesian Regret for the particular election
* The method's Bayesian Regret per Voter for the particular election

Each collection of IBR statistics for a particular voting method in a particular election will consist of:
* The IBR of Each Voter produced by the method for the particular election
* The arithmetic mean of the IBRs produced by the method for the particular election
* The standard deviation of the IBRs produced by the method for the particular election
* The fraction of Voters for Whom the particular voting method resulted in the least IBR for the particular election

Each voting method, separately from the representation with respect to a particular election, will be represented by an object indicating:
* A collection of simulation-wide Bayesian Regret statistics
* A collection of simulation-wide IBR statistics
* The fraction of elections the particular method:
  - Elects the Condorcet Candidate
  - Elects the True Condorcet Candidate

Each collection of simulation-wide Bayesian Regret statistics for a particular voting method will be represented by an object indicating:
* The arithmetic mean of Bayesian Regret per Voter from all elections
* The standard deviation of the Bayesian Regret per Voter from all elections

Each collection of simulation-wide IBR statistics for a particular voting method will be represented by an object indicating:
* The arithmetic mean of the IBR of Each Voter from all elections
* The standard deviation of the IBR of Each Voter
* The fraction of elections the particular method results in the least IBR for the largest fraction of Voters
* The fraction of Voters for Whom the particular voting method resulted in the least IBR

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

######Condorcet Candidate######
The Condorcet Candidate of an election is the Candidate, when compared with every other Candidate, is preferred by more Voters.

######Individual Bayesian Regret######
Individual Bayesian Regret (IBR) is a concept I have devised which is based on traditional Bayesian Regret. IBR is defined as the sum across All Voters of the differences between the utility value of whichever Candidate has the highest utility to the specific Voter and the utility value of the Candidate selected by the particular voting method. Conceptually, IBR measures the difference between the one "perfect" Candidate satisfying All Voters and the Candidate chosen by the particular voting method.

######True Condorcet Candidate######
While the Condorcet Candidate of an election is the Candidate, when compared with every other Candidate, is *preferred* by more voters, the "True Condorcet Candidate" is the Candidate, when compared with every other Candidate, has *greater actual utility* for more Voters.
