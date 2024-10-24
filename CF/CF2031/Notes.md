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

Greedy solution - if we find a beautiful segment, take it, since any segments that we haven't seen that use previous elements will overlap with this segment.

If we do find a segment, afterwards, we only consider the suffix of the original array after this segment.

In this suffix, keep track of all prefixes we have seen. If we see this prefix again, it means that there was a subarray (segment) that was beautiful. Reset our map since we no longer consider previous elements

# E: Sakurako, Kosuke, and the Permutation
Re-frame the permutation as a graph. There are n nodes numbered 1 to n.

There is an edge from i to j if and only if p[i] = j. There will be n edges, each node will have 1 edge entering it and 1 edge exiting it.

Based on the problem statement, we need every node to satisfy one of these conditions:
- Be in its own cycle of 1 (edge pointing from itself, to itself)
- Be in a cycle of 2 (2 nodes each pointing to each other).

If we have a cycle of x nodes, we need to break it up into cycle of at most 2 nodes. In other words, we need to remove x-2 nodes. 

How does swapping affect this graph? Swapping a and b redirects 2 edges since the edge pointing from u to a now points from u to b, and the edge pointing from v to b now points from v to a. This will also cause a split into 2 different cycles of size x-y and y. So, we need to do (x-2)/2, rounded up, operations to resolve a cycle of x > 2.

The answer is the sum for all cycles.

# F: Kosuke's Sloth

# G: Sakurako and Chefir
