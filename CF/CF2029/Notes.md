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
 
# E: Common Generator

# F: Palindrome Everywhere

# G: Balanced Problem

# H: Message Spread

# I: Variance Challenge