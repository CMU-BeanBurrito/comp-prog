Notes on solutions/approaches to problems

# A: Perpendicular Segments

Claim: `K <= sqrt(2)*min(X, Y)`.

Proof:
Call the slope of a segment the quotient of its y-component divided by its x-component. Two segments are perpendicular if the products of their slopes is -1.
If a segment's x-component is 0, then it is only perpendicular to segments that have slope 0. 

Assume for the sake of contradiction that the claim is false. Without loss of generality, assume `X > Y`. So assume that `K > sqrt(2)*Y`.

The y-component of the first segment AB can be at most `Y`. Therefore, if this segment's length is at least `K`, the x-component of AB must be greater than `Y`.
The absolute value of AB's slope is less than 1, so the absolute value of CD's slope must be greater than 1.

The y-component of the second segment CD can be at most `Y` (due to the restriction of the grid). Therefore, since this segment's length is at least `K`, the x-component of AB must be less than `Y`.
Then the length of this segment is less than `sqrt(2)*Y`. But this segment has length `>= K > sqrt(2)*Y`. Therefore, this is a contradiction.

How can we leverage this claim? We've established that each segment never has to be longer than `sqrt(2)*min(X, Y)`.

Therefore, we pick `A = (0, 0), B = (min(X, Y), min(X, Y)), C = (min(X, Y), 0) and D = (0, min(X, Y))`, AB and CD have length exactly `sqrt(2)*min(X, Y) >= K`.
AB has slope 1, CD has slope -1 so they are perpendicular. 

Essentially, we take the largest square contained within the grid, and take the 2 diagonals of the square as our segments.

# B: Black Cells
*call cells whose indices are on the list/in the input array "key" cells

Observation: If n is even, all key cells are painted black, and no non-key cells will be painted black. If n is even, all key cells are painted black, and one non-key cell will be painted black.

If n is even:
- Each key cell is paired with exactly one other key cell
- We need to minimize the greatest distance between any 2 cells that are paired
- Since `a` is sorted, we can simply pair `a[0]` with `a[1]`, pair `a[2]` with `a[3]`, etc.
- The answer is the maximum distance between one pair's cells

If n is odd:
- Each key cell (except one) is paired with exactly one other key cell
- This single key cell will be paired with a non-key cell

Observe that due to the input constraints, `O(n^2)` is sufficient. So, we will brute force by checking each key cell at seeing what the answer is if we chose this key cell to be the one to pair with a non-key cell.
Observe that only even indices of `a` should be considered for skipping: `a[0], a[2], a[4], etc.` This is so there is an even number of key cells on either side of the skipped key cell.

For each of these cells, we iterate over the array looking at the distances `a[1]-a[0], a[3]-a[2], etc.`, As before, the answer for this skipped cell is the max distance between any of these pairs. When we reach the skipped cell, how to do we handle it?

If the key cell `a[s]` we are skipping has a neighboring non-key cell, clearly we should pair these two to minimize the distance. However, it's possible that both cells neighboring the skipped cell are key cells. In this case, we would want to choose another key cell to be paired with a non-key cell (one with a neighboring non-key cell). For this reason, we can ignore this skipped cell.

The overall answer is the best answer (minimum) among all skipped cells.

# C: Action Figures

The only time we buy more than 2 action figures is on the last day if we still have more than 2 we need to buy.
This is because if we buy more than 2 figures, we are paying full price for the 2nd most expensive action figure (and any other figures we buy on this day aside from the most expensive one).
We might have the chance to get this action figure for free later or worst case scenario we buy it on the day n for full price which is at least as good as buying it now.
In other words, we are trying to pair together action figures and make as many pairs as possible, since each pair represents 1 free action figure.

DP solution, `dp[i]` = most action figures we can get for free in the first i days.
We don't need to track which action figures we are taking for free since we will always take the last `dp[n]` figures that are released on that day (since they are the most expensive at the time)

Init: `dp[1] = 0`, since we can buy at most 1 figure on day 1, which will be full price
if `a[i] == 0` then `dp[i] = dp[i-1]`
     - why? since we cannot visit the store.
else: `dp[i] = min(dp[i-1]+1, i/2)` 
     - `dp[i-1]+1`: we try to get the `i`th action figure for free by adding one of the figures we paid full price for in the 1st `i` days to our day `i` purchase.
         - this can be limiting factor since we can only get at most 1 free action figure per day, so we can't get more than `dp[i-1]+1` for free.
     - `i/2`: we can never get more than `i/2` figures for free on the first `i` days:
         - to get 1 figure free, we have to buy at least 2. so if we get `> i/2` for free, we bought `> i` figures, but only `i` figures are available on day `i`.
         - the only time this will be the limiting factor is we already have `i/2` for free (we've purchased all `i-1` characters in pairs), then the ith action figure will not be able to be purchased with another figure.
         - otherwise, there is currently at least 1 action figure (of the first `i-1` figures) that isn't paired up with another so we can pair it up with the `i`th figure to get the `i`th figure for free.
         
At the end, `dp[n] = x`. we can get `x` action figures for free, clearly we want to those to be the more expensive ones. 
We can get at most 1 action figure for free each day we visit the store.
Except for day n, we are buying 0 figures or 2 figures. we never buy > 2 as explained above, same logic goes for never buying exactly 1.
If we buy 2 on day i, the most expensive figure available (which we want to get for free) is the ith figure.
So, the x figures we get for free are the figures that come out on the last x days we visit the store.

Answer is sum of all `n` figures (Gauss sum of `n*(n+1)/2`) minus the costs of the `x` figures we got for free.

# D: Sums of Segments

# E: Best Subsequence

# F: Bermart Ice Cream
