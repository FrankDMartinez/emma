To-do list:

1. ~~Write to-do list~~ DONE!!!
1. ~~Cross off first item~~ DONE!!!
1. ~~Write [design notes](design notes.md)~~ DONE!!!
1. Implement solution as guided by the design notes:
	1. ~~Display the title and license information.~~ DONE!!!
	1. ~~Determine what is requested from simulations.~~ DONE!!!
		1. ~~Parse given options.~~ DONE!!!
		1. ~~Display usage information and exit, if required.~~ DONE!!!
		1. ~~Determine the mode to run in based on such parsing.~~ DONE!!!
		1. Determine what statistics to collect based on such parsing.
	1. Load serialized data if required.
	1. Generate data:
		1. Run simulations:
			1. Determine the number of elections to run.
			1. For each election:
				1. ~~Prepare the election scenario:~~ DONE!!!
					1. ~~Determine the number of Candidates.~~ DONE!!!
					1. ~~Determine the number of Voters.~~ DONE!!!
					1. ~~For Each Voter:~~ DONE!!!
						1. ~~For Each Candidate:~~ DONE!!!
							1. ~~Determine the actual utility of the Candidate to the Voter.~~ (We can adjust this later to focus on multiple issues.)
					1. ~~Determine the degree of Voter ignorance.~~ (Currently using a pseudo-random normally distributed number for the perceived utility; We can change this later.)
					1. ~~For Each Voter:~~ DONE!!!
						1. ~~For Each Candidate:~~ DONE!!!
							1. ~~Determine the *perceived* utility of the Candidate to the Voter based on the degree of Voter ignorance.~~ (Currently using a pseudo-random normally distributed number for the perceived utility; We can change this later.)
					1. ~~Identify honest Voters and strategic Voters~~ DONE!!!
						1. ~~Determine the number of Voters which vote honestly and the number which vote strategically.~~ DONE!!!
							1. ~~Determine the ideal ratio of Voters voting honestly to Voters voting strategically.~~ DONE!!!
							1. ~~Determine what ratio of honest Voters and of strategic Voters from the election's entire electorate most closely matches that ratio.~~ DONE!!!
						1. ~~Randomly select Voters to vote honestly or strategically in accordance with those numbers.~~ DONE!!!
					1. ~~Determine the Candidate with the "optimum societal utility".~~ DONE!!!
						1. ~~For each Candidate:~~ DONE!!!
							1. ~~Sum the actual utilities of that Candidate to the Voters.~~ DONE!!!
						1. ~~If exactly 1 Candidate has the highest actual utility sum:~~ DONE!!!
							1. ~~Record that Candidate as the 1 with the "optimum societal utility".~~ DONE!!!
						1. ~~If more than 1 Candidate has the highest actual utility sum:~~ DONE!!!
							1. ~~Choose 1 of the Candidates with the highest actual utility sum.~~ DONE!!!
							1. ~~Record that randomly chosen Candidate as the 1 with the "optimum societal utility".~~ DONE!!!
					1. Determine the True Condorcet Candidate.
						1. Sort Each Voter's preferences of Candidates by actual utilities.
						1. For Each Candidate, A:
							1. For Each OTHER Candidate, B:
								1. Determine Who is elected in a 1-on-1 plurality election based on actual utilities.
									1. Start with 0 votes for both A and B.
									1. For Each Voter:
										1. Get ranking of A.
										1. Get ranking of B.
										1. If A is ranked higher than B, record a vote for A.
										1. If B is ranked higher than A, record a vote for B.
									1. If A has more votes recorded than B, record A as elected over B.
									1. If B has more votes recorded than A, record B as elected over A.
									1. If A and B have the same number of votes recorded, one of the two is randomly selected and considered elected over the Other. (Note: other methods use other tie breaking means.)
							1. If A would be elected over All Other Candidates in these 1-on-1 plurality elections:
								1. Record A as the True Condorcet Candidate.
						1. If there is no Candidate selected as the True Condorcet Candidate:
							1. Record the fact the election has no True Condorcet Candidate.
				1. For each voting method:
					1. Determine the Candidate elected by this method in this election.
						1. Determine the Condorcet Candidate. ("CW wins 1-on-1 versus X, for all rivals X.")
							1. Sort Each Voter's preferences of Candidates in accordance with the Voter's voting nature; in the event of equal perceived utility between 2 Candidates, order the 2 Candidates at random.
								1. For Each Voter:
									1. If the Voter is an honest Voter:
										1. Sort Candidates by perceived utility
									1. If the Voter is a strategic Voter:
										1. Utilize the "moving average strategy" to adjust the Voter's perspective of Each Candidate:
											1. Of the first 2 Candidates with the higher perceived utility, rank that Candidate first and the other last.
											1. For Each Candidates after the first 2:
												1. If the average perceived utility of the Candidate is above the average perceived utility of the preceding Candidates:
													1. Rank that Candidate in the next avilable highest position.
												1. If the average perceived utility of the Candidate is below the average perceived utility of the preceding Candidates:
													1. Rank that Candidate in the next avilable lowest position.
												1. If the average perceived utility of the Candidate equals the average perceived utility of the preceding Candidates:
													1. Rank that Candidate in either the next avilable highest or lowest position based on a coin flip.
							1. For Each Candidate, A:
								1. For Each OTHER Candidate, B:
									1. Determine Who is elected in a 1-on-1 plurality election based on perceived utilities.
										1. Start with 0 votes for both A and B.
										1. For Each Voter:
											1. Get ranking of A.
											1. Get ranking of B.
											1. If A is ranked higher than B, record a vote for A.
											1. If B is ranked higher than A, record a vote for B.
										1. If A has more votes recorded than B, record A as elected over B.
										1. If B has more votes recorded than A, record B as elected over A.
										1. If A and B have the same number of votes recorded, one of the two is randomly selected and considered elected over the Other. (Note: other methods use other tie breaking means.)
								1. If A would be elected over All Other Candidates in these 1-on-1 plurality elections:
									1. A is the Condorcet Candidate.
							1. If there is no Candidate selected as the Condorcet Candidate, there is no Condorcet Candidate.
		1. Collect statistics from each simulation if required:
			1. For each election:
				1. For each voting method:
					1. Collect required Bayesian Regret statistics:
						1. Collect the method’s Bayesian Regret for the particular election if required.
						1. Collect the method’s Bayesian Regret per Voter for the particular election if required.
					1. Collect required IBR statistics:
						1. For Each Voter:
							1. Collect the IBR produced by this method for this election if required.
						1. Collect the arithmetic mean of the IBRs produced by this method for this election if required.
						1. Collect the standard deviation of the IBRs produced by this method for this election if required.
						1. Collect the fraction of Voters for Whom this method resulted in the least IBR for this election if required.
					1. Collect required Condorcet agreements:
						1. Collect Condorcet Candidate agreement of this method for this election if required.
						1. Collect True Condorcet Candidate agreement of this method for this election if required.
		1. Analyze collected statistics if required:
			1. For each voting method:
				1. Collect Bayesian Regret statistics for this method from all elections if required.
					1. Collect arithmetic mean of Bayesian Regret per Voter from all elections for this method if required.
					1. Collect standard deviation of Bayesian Regret per Voter from all elections for this method if required.
				1. Collect IBR statistics for this method from all elections if required.
					1. For Each Voter:
						1. Collect the arithmetic mean of the IBRs from all elections if required.
						1. Collect the standard deviation of the IBRs if required.
					1. Collect the fraction of elections the particular method results in the least IBR for the largest fraction of Voters if required.
					1. Collect the fraction of Voters for Whom the particular voting method resulted in the least IBR if required.
				1. Collect Condorcet agreement rates for this method from all elections if required:
					1. Collect the fraction of elections in which this method elects the Condorcet Candidate if required.
					1. Collect the fraction of elections in which this method elects the True Condorcet Candidate if required.
	1. Compare generated data with serialized data if required, reporting any difference.
		1. Compare simulation data, reporting any difference.
			1. For each election:
				1. Compare each election scenario's data, reporting any difference.
				1. Compare each voting method's information, reporting any difference.
		1. Compare election statistics, reporting any difference.
			1. For each election:
				1. For each voting method:
					1. Compare Bayesian Regret statistics:
						1. Compare the method’s Bayesian Regret for the particular election, reporting any difference.
						1. Compare the method’s Bayesian Regret per Voter for the particular election, reporting any difference.
					1. Compare IBR statistics:
						1. For Each Voter:
							1. Compare the IBR produced by this method for this election, reporting any difference.
						1. Compare the arithmetic mean of the IBRs produced by this method for this election, reporting any difference.
						1. Compare the standard deviation of the IBRs produced by this method for this election, reporting any difference.
						1. Compare the fraction of Voters for Whom this method resulted in the least IBR for this election, reporting any difference.
					1. Compare Condorcet agreements:
						1. Compare Condorcet Candidate agreement of this method for this election, reporting any difference.
						1. Compare True Condorcet Candidate agreement of this method for this election, reporting any difference.
		1. Compare analysis statistics:
			1. For each voting method:
				1. Compare Bayesian Regret statistics for this method from all elections, reporting any difference.
				1. Compare IBR statistics for this method from all elections, reporting any difference.
				1. Compare Condorcet agreement rates for this method from all elections:
					1. Compare the fraction of elections in which this method elects the Condorcet Candidate, reporting any difference.
					1. Compare the fraction of elections in which this method elects the True Condorcet Candidate, reporting any difference.
	1. Serialize data if required.
	1. Output requested results:
		1. Collect requested results from the simulation(s) and/or associated statistics.
		1. Output the collected results.
