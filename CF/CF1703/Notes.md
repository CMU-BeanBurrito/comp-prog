Notes on solutions/approaches to problems

# A: YES or YES?

# B: ICPC Balloons

# C: Cypher

# D: Double Strings

# E: Mirror Grid

# F: Yet Another Problem About Pairs Satisfying an Inequality

# G: Good Key, Bad Key
If we use a bad key, we will not use any more good keys on the later chests.

We lost at least half of all the remaining coins `r` (total among the remaining chests) when we bought the bad key. 
So a good key must have cost more than `r/2`.

We have at most `r/2` coins remaining after opening the chest with the bad key. So a good key is guaranteed to make our final balance lesser.

So, we will use only good keys until some chest `p`, then we will use only bad keys.

We can easily simluate this for each chest `i`:
- use prefix sum to find out how many coins we get from opening all chests before chest `i` with good keys
- every chest `j, j >= i` will yield `a[j] >> (j-i+1)` coins, as it will be affected by `j-i+1` bad keys
 - we only need to calculate this for chests `j, i <= j < min(i, 30)`, as any chests `i+30` and further right will have no coins left after being halved by 30 bad keys (2^30 > 1E9). 
 - so, instead of checking `(n-i)` chests for each chest `i`, we only check at most 30
