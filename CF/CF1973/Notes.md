Notes on solutions/approaches to problems

# A: Chess For Three
Each game awards 2 points, so if the total number of points is odd, we can just return -1.

Of course, the max number of draws cannot exceed the total number of games, so that is an upper bound.

Why can't all the games be ties in every situation? Every tie had to involve at least one of player 1 and player 2.

So, the number of ties cannot be greater than `p1+p2`. This does apply to `p2+p3`, and `p1+p3`, but `p1+p2` is less than or equal to those so it is the least upper bound.

So the answer is the `min((p1+p2+p3)/2, p1+p2)`.

# B: Cat, Fox and the Lonely Array
If the answer is k, then if we move the sliding window from `a[x, x+k-1]` to `a[x+1, x+k]`, then any bits we lost from `a[x]` need to be present in `a[x+1, x+k]`.

In other words, there cannot be more than k indices between appearances of any bit (unless the bit is not present in the entire array).

For bit i, call the maximum distance between consecutive appearances (including the start of the array to the first appearance and the last appearance to the end of the array) of bit i `sep[i]`.

Then, the answer is `max(sep)`, the largest `sep[i]`.

# C: Cat, Fox and Double Maximum

# D: Cat, Fox and Maximum Array Split

# E: Cat, Fox and Swaps

# F: Maximum GCD Sum Queries