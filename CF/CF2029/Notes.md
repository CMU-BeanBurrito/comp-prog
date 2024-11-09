Notes on solutions/approaches to problems

# A: Set
In order for a number `x` to be used for an operation, the set has to contain `x, 2x, 3x....kx`.

Also, if a number `x` is valid, any other number `y, l <= y < x` is also valid. So, we just need to find the largest `x` that is valid, and then answer `x-l+1`.

This largest `x` is `r/k`. Clearly, this value is valid. However, we know `x = (r/k)+1` is not valid, since `kx = r+k` which is greater than `r` and therefore not in the set.

# B: Replacement
If we have at least one 0 and at least one 1 in `s`, we can do the next move because there must be some `10` or `01` in the string.
Inversely, if we do not have at least one 0 and at least one 1, we cannot do anymore moves. This is easy to see.

If `r[i] = 0`, then we replace a `01` or a `10` with a `0`. Either way, `s` loses one 1.
If `r[i] = 1`, then we replace a `01` or a `10` with a `1`. Either way, `s` loses one 0.

Iterate over `r`. If we have at least one 0 and at least one 1 in `s`, we can perform our operation (update the counts of 0s and 1s in `s`).

If we run out of 0s or 1s in `s` before all moves are completed, answer NO. Otherwise, answer YES.

# C: New Rating
*This can be solved with binary search, but I solved it with DP.
*0-indexed

As we iterate over the contests, we are in 1 of 3 states: before the skipped interval, in the skipped interval, or after the skipped interval. We can switch states at most twice, and only from before to in, or in to after.

`dp[0][i]` = rating after contest `i` if we have not skipped any yet
`dp[1][i]` = best rating we can have after contest `i` if we skipped contest `i` (and possibly some contests preceding `i`).
`dp[2][i]` = best rating we can have after contest `i` if we did not skip contest `i`, already skipped some contests before `i` and do not skip any contests after `i`.

For `dp[0]`, we just fill in the rating after each contest if that contest is not skipped
For `dp[1]`, we can either transition from `dp[0]` (start skipping at contest `i`), or continue skipping from a previous contest from `dp[1]`.
For `dp[2]`, we can either transition from `dp[1]` (contest `i` is the first contest we do after skipping), or we already were done skipping and we continue on from `dp[2]`

Final answer is `max(dp[1][n-1], dp[2][n-1])`, since it's possible we started skipping contests and didn't do anymore after.

# D: Cool Graph
Strategy: Split graph into connected components of size 1 or 2. In other words, reduce each node's degree to at most 1. Call this Step 1.

Why? If we get to this point, we are in one of two cases:
- all connected components are size 1. In this case, we are done.
- we have only trees of size 1 and 2, and two trees can be merged into a single tree with one operation (so we can finish from this point in `O(n)` time). Call this Step 2.

Step 1: We can reduce the degree of a node by 2 by performing an operation on it and two of its neighbors. So, we remove 2 edges (or 3, if the two neighbors are also adjacent to each other), and add one (or zero). We can see that by doing this repeatedly, we will eventually reduce every node's degree to 1. We can also see that this will take at most `O(m)` operations since we are removing 1 edge on each operation.

Step 2: As described above, if there are no edges left, we are done. Otherwise, we need to build a final tree. Start with a tree of size 2. We take one of the nodes as the root of our tree. On each operation, we will perform an operation on the root, a neighbor of the root, and a node in another connected component from the root.

This will take `O(n)` operations since we add at least 1 node to our tree on each operation.
 
# E: Common Generator

# F: Palindrome Everywhere

# G: Balanced Problem

# H: Message Spread

# I: Variance Challenge