Notes on solutions/approaches to problems

# A
Problem statement basically contains pseudocode for the entire problem, nothing else necessary.

# B
Keep track of two greatest elements while traversing array.

# C
We will never pay out more subsidies than the sum of the transportation costs of all the participants.
So, if the sum of the participants' costs is greater than or equal to our total budget, the budget per participant can be infinite.

Otherwise, there will be some participants that are not reimbursed for their full cost. 
Sort the participants and build a prefix sum. If we make the individual budget the cost of participant i, our total cost will be
the sum of the participants' (up to the ith, those who have less costs) costs, plus i's cost times the rest of the participants (the ones with greater cost than i).

Traverse until we reach a point where we are unable to make the individual budget the cost of participant i. This is an upper bound. We know how much over the budget we are. We simply divide this by the number of participants who have the cost of participant i or higher. This is the amount over the upper bound the individual budget is, simply subtract to get the answer.

# D
Use dynamic programming. Build 3 rows, one for each move in a game.

`dp[ROCK][i]` is the maximum number of games we can win if we played ROCK in the ith game.

For `i=0`, all moves have dp[move][0] = 0, since we cannot win any games if none are played.

For each game, we always have two options, since we are never allowed to play the losing option. If we choose to tie (e.g. play ROCK against ROCK), then we didn't choose this move last game. So, we want to look at the previous game and see which option gave us the most wins through the first i-1 games. Since we are tying, we don't add a win for this game.

If we are choosing to win, then we once again look at the other 2 options since we didn't play this move last game. Take the better of the two, but add a win since we are choosing to win this game.

At the end, look at the end of each row to see which "path" was optimal: `dp[ROCK][n]`, `dp[PAPER][n]`, or `dp[SCISSORS][n]`



# E

# F

# G