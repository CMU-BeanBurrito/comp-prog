Notes on solutions/approaches to problems

# A: YES or YES?
Answer is YES if all of the following are true:
- First character is 'Y' or 'y'
- Second character is 'E' or 'e'
- Third character is 'S' or 's'

Otherwise, answer is NO.

# B: ICPC Balloons
Each problem yields a balloon, so initialize our answer to `n`.

Now, we traverse the string and whenever we see a character we haven't seen before, increment our answer by 1 since this is the first time a problem has been solved.

# C: Cypher
For each digit, we simply simulate the moves given to us by the string, in reverse.

# D: Double Strings
Add all strings into a map or set so we can easily check if a string we need exists.

For each string, use brute force to divide it in every possible location:
- s[0] and s[1:n-1], s[0:1] and s[2:n-1], etc.
- if both pieces are present in the map, the answer for this string is 1
- if we tried every possible split for this string and couldn't find both pieces for any split, the answer is 0

# E: Mirror Grid
As we rotate the grid, any cell can moves between at most 4 locations. The corners of the grid are the best to illustrate this. If the 4 corners have the same value, we don't need to change them since the corners will stay the corners regardless of the rotation.

The same principle applies to every cell in the grid - each cell is part of a group of 4. Each group of 4 has to be all 1 or all 0s. So, our answer is the sum of required operations across all groups.

Which cells are in the same group? When the grid is rotated, a cell `(r, c)` moves to `(c, n-r-1)`. In other words, the new row is the old column, and the new column is the old row, inverted.

To avoid double counting, we can iterate over certain bounds (note that for odd `n`, we can ignore the single cell in the middle since it never moves). We only need to iterate over one "quadrant", and we can choose this quadrant to be 0 <= row <= `(n-1)/2`. See pictures for a visual representation of how this works for both even and odd `n`.

# F: Yet Another Problem About Pairs Satisfying an Inequality
*This explanation uses 1-indexing

Call an index `i` "eligible" if `a[i] < i`. An ineligible index cannot be paired with any other index.

We will construct two arrays in addition to the input array. `b[i]` is the number of eligible indices that are in `[1, i]`. To build this, we initialize `b[0] = 0` as there are no eligible indices outside the array. 
If `a[i] < i`, then `b[i] = b[i-1]+1` as we found a new eligible index.
Otherwise `b[i] = b[i-1]`.

Our second array, `dp[i]` is the answer if we only consider the first `i` indices. To build this, we initialize `dp[0] = 0` as there are no pairs outside the array, and `dp[1] = 0` as we cannot have a pair with just one index.
If `b[i] > b[i-1]`, it means `i` is an eligible index and we should check how many other eligible indices it can be paired with. According to the inequalities, it can only be paired with indices `j` that are strictly less than `a[i]`. So, we need to check the number of eligible indices at `b[a[i]-1]`. This is the number of eligible indices that index `i` can be paired with.

So, `dp[n]` is our answer.

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
