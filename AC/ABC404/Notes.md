Notes on solutions/approaches to problems

# A: Not Found

Iterate over the string.

For every character from `a` to `z`, track whether we've seen it.

Iterate over characters `a` to `z`, return any one that we didn't see.

# B: Grid Rotation

For every orientation of S (rotated 0 degrees, rotated 90 degrees, rotated 180 degrees, rotated 270 degrees), check how many cells differ between this orientation of S, and T.

The number of operations to get a particular orientation to match is the number of rotations + the number of differing cells.

For example, if the orientation of S rotated 180 degrees differs in 4 cells, this choice would require 6 operations (2 rotations, 4 toggles). Choose the orientation with the lowest number of total operations.

# C: Cycle Graph?

We need to check if the entire graph is one big cycle with no other edges.

We need to check that the degree of each vertex is 2. However, this is not sufficient as there could be multiple connected components, with each of them being its own cycle.

So, we also need to check that there is only one connected component, can easily be done with DFS.

# D: Goin' to the Zoo

There are few enough animals and zoos that we can purely brute force this problem.

There is no point of visiting a particular zoo more than twice. So, we need to iterate over every combination of visiting each zoo 0, 1, or 2 times. 

We can see that there will be `3^n` of these scenarios for `n` zoos.

For each scenario, we:
- check how many times we will see each animal (for each zoo, all its animals will receive however many visits this zoo gets in this scenario)
- compute the cost of the visits in this scenario
- check that each animal has been visited twice
  - if they all have, we check if this scenario's cost is the new minimum
  - if they have not, we ignore this scenario's cost and move onto the next scenario

Return the minimum cost.

This solution runs in `O(mn * 3^n)`, each scenario requires us to check all the animals in each zoo `O(mn)`, and there are `3^n` scenarios.

# E: Bowls and Beans (*WIP)

BFS?

# F: Lost and Pound

# G: Specified Range Sums