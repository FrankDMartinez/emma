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
####Application Concept####

This program will be a simple command line application with a text only interface. When started, the application will display the title and license information of the application. The application will enter its main loop and begin the simulations. Once simulations are complete, the data gathered from the simulations will be analyzed and the results of that analysis sent to the standard output location.

####Abstract Data Types####

Each simulated election will be represented by an object indicating:

* The number of Candidates in the election, an integer
* The number of Voters in the election, an integer no less than the number of Candidates
* The actual utility of Each Candidate to Each Voter, a floating point value from a Gaussian distribution of mean 0 and variance 1
* The degree of Voter ignorance, a floating point value from a Gaussian distribution of mean 0 and variance 1
* The fraction of Voters voting honestly versus voting strategically, a floating point value ranging from 0 to 1
* A collection of statistics for each voting method with respect to this simulated election
* The Condorcet Candidate in that election
* The True Condorcet Candidate in that election

Each voting method, with respect to a particular election, will be represented by an object indicating:

* The Candidate elected by that method in that election
* A collection of Bayesian Regret statistics
* A collection of IBR statistics

Each collection of Bayesian Regret statistics for a particular voting method in a particular election will consist of:

* The method's Bayesian Regret for the particular election, a floating point value
* The method's Bayesian Regret per Voter for the particular election, a floating point value

Each collection of IBR statistics for a particular voting method in a particular election will consist of:

* The IBR of Each Voter produced by the method for the particular election, a collection floating point values
* The arithmetic mean of the IBRs produced by the method for the particular election, a floating point value
* The standard deviation of the IBRs produced by the method for the particular election, a flaoting point value
* The fraction of Voters for Whom the particular voting method resulted in the least IBR for the particular election, a floating point value

Each voting method, separately from the representation with respect to a particular election, will be represented by an object indicating:

* A collection of simulation-wide Bayesian Regret statistics
* A collection of simulation-wide IBR statistics
* The fraction of elections the particular method:
  - Elects the Condorcet Candidate
  - Elects the True Condorcet Candidate

Each collection of simulation-wide Bayesian Regret statistics for a particular voting method will be represented by an object indicating:

* The arithmetic mean of Bayesian Regret per Voter from all elections, a floating point value
* The standard deviation of the Bayesian Regret per Voter from all elections, a floating point value

Each collection of simulation-wide IBR statistics for a particular voting method will be represented by an object indicating:

* The arithmetic mean of the IBR of Each Voter from all elections, a floating point value
* The standard deviation of the IBR of Each Voter, a floating point value
* The fraction of elections the particular method results in the least IBR for the largest fraction of Voters, a floating point value
* The fraction of Voters for Whom the particular voting method resulted in the least IBR, a floating point value

Operation Overviews
----------------

The follow sections help to give a simplified perspective of the application and its operations.

####Application Algorithm Overview####

1. Display the title and license information.
1. Determine what is requested from simulations.
1. Generate simulation data.
1. Output requested results.

####Determining Requested Information Overview####

1. Parse given options.
1. Display usage information and exit, if required.
1. Determine what statistics to collect based on such parsing.

####Simulation Data Generation Overview####

1. Run simulations.
1. Collect primary statistics from each simulation if required.
1. Collect secondary statistics if required.

####Outputting Requested Results Overview####

1. Collect requested results from the simulation(s) and/or associated statistics.
1. Output the collected results.

####Running Simulations Overview####

1. Determine the number of elections to run.
1. Prepare each election.
1. Determine the Candidate elected by each voting method for each election.

####Collecting Primary Statistics Overview####

1. Collect required Bayesian Regret statistics for each method in each election.
1. Collect required IBR statistics for each method in each election.
1. Collect required Condorcet agreements for each method in each election.

####Collecting Secondary Statistics Overview####

1. Collect Bayesian Regret statistics for each method from all elections if required.
1. Collect IBR statistics for each method from all elections if required.
1. Collect Condorcet agreement rates for each method from all elections if required.

####Election Preparation Overview####

1. Determine the number of Candidates in the current election.
1. Determine the number of Voters in the current election.
1. Determine the actual utility of Each Candidate to Each Voter.
1. Determine the degree of Voter ignorance.
1. Determine the *perceived* utility of Each Candidate to Each Voter based on the degree of Voter ignorance.
1. Identify honest Voters and strategic Voters.
1. Determine the Candidate with the "optimum societal utility".
1. Determine the Condorcet Candidate.
1. Determine the True Condorcet Candidate.

####Primary Bayesian Regret Statistics Collection Overview####

1. Collect each method’s Bayesian Regret for each election if required.
1. Collect each method’s Bayesian Regret per Voter for each election if required.

####Primary IBR Statistics Collection Overview####

1. Collect the IBR produced by each method for each election for each Voter if required.
1. Collect the arithmetic mean of the IBRs produced by each method for each election if required.
1. Collect the standard deviation of the IBRs produced by each method for each election if required.
1. Collect the fraction of Voters for Whom each method resulted in the least IBR for each election if required.

####Primary Condorcet Agreement Rate Collection Overview####

1. Collect Condorcet Candidate agreement of each method for each election if required.
1. Collect True Condorcet Candidate agreement of each method for each election if required.

####Secondary Bayesian Regret Statistics Collection Overview####

1. Collect arithmetic mean of Bayesian Regret per Voter from all elections for each method if required.
1. Collect standard deviation of Bayesian Regret per Voter from all elections for each method if required.

####Secondary IBR Statistics Collection Overview####

1. Collect the arithmetic mean of the IBRs of Each Voter from all elections for each method if required.
1. Collect the standard deviation of the IBRs of Each Voter if required.
1. Collect the fraction of elections each method results in the least IBR for the largest fraction of Voters if required.
1. Collect the fraction of Voters for Whom each voting method resulted in the least IBR if required.

####Secondary Condorcet Agreement Rate Collection Overview####

1. Collect the fraction of elections in which each method elects the Condorcet Candidate if required.
1. Collect the fraction of elections in which each method elects the True Condorcet Candidate if required.

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
