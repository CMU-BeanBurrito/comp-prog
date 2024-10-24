Notes on solutions/approaches to problems

# A: Sakurako and Kosuke
While this can be done in constant time, using the parity of n, during the contest I chose to just simulate it.

# B: Sakurako and Water
If two or more lakes are on the same "down-right" diagonal, their heights can be changed simultaneously. Furthermore, this is the only condition under which two (or more) lakes can have their heights changed simultaneously.

So, for each down-right diagonal, we find the deepest lake with height h. Then we can "fix" all lakes on this diagonal with |h| operations.

Simply sum the total number of operations for all diagonals.

# C: Sakurako's Field Trip
Greedy solution - start on the outside (start and end) of the array and work inwards towards the middle. If swapping a pair is better than the current state, do so.

Sum up the disturbance and return.

# D: Kousuke's Assignment



# E: Sakurako, Kosuke, and the Permutation


# F: Kosuke's Sloth

# G: Sakurako and Chefir
