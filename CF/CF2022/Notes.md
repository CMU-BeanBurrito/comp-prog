Notes on solutions/approaches to problems

# A: Bus to Penjamo
We can do this greedily. Iterate over each family and put pairs of this family into empty rows. This means both family members of the pair will be happy.

When we are done with this step, each family will have at most 1 unseated member, and we will have some number (maybe 0) empty rows.

Seat as many of these unseated members as possible in their own row (happy) and put the rest in rows together (unhappy). The total number of unhappy people will be the number of unseated members after the first step, minus the number of remaining rows after the first step.

# B: Kar Salesman
There are two constraints. 

Constraint 1: If the model with the most cars in stock (maximum element in a) has value `mx`, we need at least `mx` customers since each customer can only buy one of these cars.

Constraint 2: If the sum of cars in stock (sum of a) is `sum`, we need at least `ceil(sum/x)` customers, since each customer can only buy `x` cars.

The answer is simply the higher of these two lower bounds.

# C: Gerrymandering

Tricky DP problem. We will consider 3 types of subproblem. Each will have a total number of cells that is divisible by 3. `dp[c][i]` will represent the most possible votes when considering the first i columns under the cth state.
- State 0: top row has 3 ckells, bottom row has 3k cells, i=3k
- State 1: top row has 3k+2 cells, bottom row has 3k+1 cells, i=3k+1
- State 2: top row has 3k+1 cells, bottom row has 3k+2 cells, i=3k+1

For our DP, we will add a possible district to this subproblem. See comment at top of file to see the terms I use for each district shape. We will then look at the votes in this district and update the future indices of the DP with the result.

If we are in the first type of subproblem we have 3 options.
- add row district to top row (which will also necessitate a row district added to bottom row)
- add L district. doesn't necessitate a certain type of district to follow (could be row or flip r)
- add r district. doesn't necessitate a certain type of district to follow (could be row or flip L district) 

If we are in the second type of subproblem we have 2 options.
- add row district to bottom row (which will necessitate a row district added to bottom row)
- add flip L district. doesn't necessitate a certain type of district to follow (could be row, L, or r)

If we are in the third type of subproblem we have 2 options.
- add row district to top row (which will necessitate a row district added to top row)
- add flip r district. doesn't necessitate a certain type of district to follow (could be row, L, or r)

To set up the DP, it is important to recognize that some indices are invalid. For example, `dp[1][0]` is not a valid index, because this would represent a top row of 1 cell and a bottom row of 0 cells, the sum is not divisible by 3. To handle this, we can initialize all states to some sentinel value (indicating invalid), and begin cascading from `dp[0][0] = 0` which is a valid state (empty map). Valid subproblems will only compute solutions for valid future subproblems, so if we see an invalid subproblem (indicated by sentinel value), we can just skip it since no valid future subproblem will gain anything from it.

# D:

# E:

# F:

# G: