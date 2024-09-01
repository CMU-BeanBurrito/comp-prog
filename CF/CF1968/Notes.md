Notes on solutions/approaches to problems

# A: Maximize?
I did this with brute froce in order to save time.

The best way to do this is to recognize that `gcd(a, b) = gcd(a-b, b)`, if a >= b.

Since `x > y`, `gcd(x, y) = gcd(x-y, y)`

`gcd(x-y, y) <= x-y`, so `gcd(x-y, y) <= x-y+y = x`

Therefore, the sum we are trying to maximize can never exceed x.

We can easily find `y` such that `gcd(x-y, y) = x`. 

By Bezout's theorem, `gcd(x, x-1) = 1`. So we can just choose `y = x-1`. 

Then `gcd(x, y) + y = 1 + y = x`. We already proved that `x` is the optimal sum.

# B: Prefiquence

We can iterate overall prefixes of a and see if they are a subsequence of b.

First, we traverse b until we see an occurence of a[0] in b. 

If one does not exist, clearly the answer is 0.

Otherwise, we check a[1] and continue traversing b from where we left off, looking for a[1] in b.

This is because we cannot reuse the b[i] we stopped at earlier, and there wasn't an early occurrence we could've used.

Continue traversing both strings linearly until at least one is exhausted. The answer is the number of times we were able to find a match for a[i] in b.

# C: Assembly via Remainders

At first, we may think we can simply take `a[i] = x[i]`. However, this will not work since we might have `x[i+1] >= x`. In this case, there would be no possible answer for `a[i+1]`.

To resolve this, we need to increment `a[i+1]` by a multiple of `a[i-1]` (so as not to change `a[i] mod a[i-1]`) until `a[i+1]` exeeds `x[i]`. We can quickly find how much to increment by subtracting. We will add an extra `a[i-1]` since `a[i]` needs to be strictly greater than `x[i+1]`.

# D: Permutation Game

First, let us note that if it is worth jumping to a certain spot in the permutation at all, it is optimal to get there as soon as possible. Our destination will also have the highest value `a[i]` out of all the indices we visit (otherwise, we would've just stayed somewhere else).

Also, we will move positions at most n-1 times (since making n moves would return us to our starting point).

Build a vector containing the order of elements in a that they will reach if they move every turn.

For each spot, calculate the score if we get to that spot as soon as possible and stay there for the rest of our turns. We can do this quickly with prefix sums. Our score is the prefix sum of all the elements we passed to get to our destination, then our destination element multiplied by the remaining turns.

Track the maxmium of all these scores.

Calculate this for both players and simply compare their max scores.

# E: Cells Arrangement

For n = 2, it doesn't matter what we pick.

For n = 3, we can pick (1, 1), (1, 2), (3, 3). This will be useful later.

Clearly, |H| can never exceed 2n-1. This is because the max distance between any 2 cells is 2n-2. So we can have 0, 1, 2....., 2n-2.

For n >= 4, we can always reach this maximum. How to place the points.

We can place two points at (1, 1), (1, 2), and the rest of our points on the main diagonal (3, 3), (4, 4), (5, 5), etc.

This is because the first pair covers distance 1. Each of the points on the diagonal have distance 2 from each other, but also are also each 2 units further away from the initial pair than the previous diagonal point. 

So (3, 3) is distance 3 to (1, 2) and distance 4 to (1, 1).

(4, 4) is distance 5 to (1, 2) and distance 6 to (1, 1).

This pattern can be extended until (n, n), which has distances 2n-3 and 2n-2, respectively. Therefore we have covered all possible distances. So this must be optimal.

# F: Equal XOR Segments

# G1: Division + LCP (Easy)

# G2: Division + LCP (Hard)