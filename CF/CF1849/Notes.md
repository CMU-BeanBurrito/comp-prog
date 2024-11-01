Notes on solutions/approaches to problems

# A: Morning Sandwich
First, we need to determine the limiting factor. It is either the bread, or the filling (ham/cheese). (It can be both bread and filling, in which case we can pick either).

If the bread is the limiting factor, it means we used all `b` slices of bread, and `b-1` slices of filling.
So, the condition is `c+h > b-1`, and we can have `2b-1` layers.

Otherwise, the filling is the limiting factor. We used all `c+h` slices of filling, and `c+h+1` slices of bread.
So, we can have `2(c+h)+1` layers.

# B: Monsters
The input values are too large to truly simulate every event. However, we can still do a simulation.

The ith can only die on a turn where it has health `h <= k`. Since any time it takes damage, it will lose `k` health, on the turn before it dies, it will have `a[i]%k` health.
We also know that any monsters who have health`a[j]%k > a[i]%k` will die before monster `i`.
So, monsters will die in descending order of their health `a[i]%k`, if there is a tie, the second criteria is index `i`.

For example, if `k = 10`, and `a = [17, 31, 56, 42, 9, 36, 18]`, then after taking remainder modulo `k`, `a = [7, 1, 6, 2, 9, 6, 8]`. Clearly, the monster with 9 health should die first, then the one with 8, etc.
So, we sort first by lesser health mod k, then we sort by index.

Can be implemented by using pairs. Default pair sort sorts in ascending order of first element, then ascending order of second element. Can modify pairs by having the first element be `k-a[i]%k` or `-a[i]%k`.

# C: Binary String Copying
Two operations have the same result if they affect the same interval of indices.
In other words, the first index and last index changed by sort A must be the same as the first index and last index changed by sort B for sort A and sort B to create the same string.
So, we can simply keep track of all of these pairs and see how many unique ones we have.

If the first 1 in the segment comes before the last 0, some characters will be moved.
Observe that only characters between the first 1 and the last 0 of the segment can move.

If the first 1 in the segment comes after the last 0, the segment is already sorted, so this copy `t[i] == s`. This is a special case that can be represented by a pair of invalid indices such as `(-1, -1)` or `(INT_MAX, INT_MAX)`.

So, for each index `i`, find the last 0 in the prefix including `i`. Similarly, find the first 1 in the suffix including `i`.

Then, when we get an operation `i, j, i < j`, we know the location of the last 0 in the prefix `[1, j]`, and the first 1 in the suffix `[i, n]`. Call these values `L`, `F`, respectively.

If `L < F`, then the segment is sorted so we can store `(-1, -1)`. Observe that if `L` or `F` is outside `[i, j]`, the segment is necessarily sorted.

Otherwise, `L` and `F` will change values (indices `k, F < k < L` may change as well). So, we can store `(F, L)`.

# D: Array Painting
First, let's get the speical case of with only 1 tile out of the way - the answer is clearly 1 coin.

Now, if we have a red tile, we can essentially "spread" its value for free. If its value is 1, we can color one neighbor for free. If its value is 2, we can color both neighbors for free.

For any element `a[i]`, let's assume all elements to the left of it (indices less than `i`), are already red, `a[i]` is blue, and all elements to right of it (indices > `i`) are also blue. So, we have 3 options.
- If `a[i-1] > 0`, we can "spread" `a[i-1]`'s value to `a[i]` and color `a[i]` for free.
- If `a[i+1] > 0`, we can color `a[i+1]` blue, then "spread" `a[i+1]`'s value to `a[i]` and color `a[i]` for free.
- We can pay 1 coin, to have `a[i]` colored red. If the other two options are not possible, we must do this one.

It turns out the optimal strategy is to exercise the first option if we can. We should consider spreading from the previous first because if we do not use the value `a[i-1]` to get a free coloring on `a[i]`, we will not get the chance to use it again. So if it is available we may as well use it now.

If we cannot use the first option, how do we know whether to use the second option or the third option? Let's consider all cases, under the assumption that `a[i+1] > 0` (or we would be forced to go to the third option):
- `a[i] = 0, a[i+1] = 1`
In this case, coloring `a[i]` first, then coloring `a[i+1]` next would cost 2 coins. While we will be able to color `a[i+2]` for free using this strategy, it is possible that we may already be able to use `a[i+3]` to color `a[i+2]` for free. And if we cannot, then we pay the same total amount for these cells. So it is at least equal (and sometimes better) to pay for `a[i+1]` and spread to `a[i]`. Option 2.
- `a[i] = 0, a[i+1] = 2`
If we color `a[i+1]` first, we are guaranteed to color `a[i]` and `a[i+2]` (if it exists) for free, so it is always strictly better than paying for `a[i]`. Option 2.
- `a[i] = 1, a[i+1] = 1`
If we color `a[i]`, we are guaranteed to color `a[i+1]` and `a[i+2]` (if it exists) for free, so it is always strictly better to pay for `a[i]` then spread to `a[i+1]` and spread `a[i+1]` to `a[i+2]`. If we paid for `a[i+1]` and spread backwards, we would have nowhere to spread the value of `a[i]` to and it would be wasted. Option 3.
- `a[i] = 1, a[i+1] = 2`
If we color `a[i]` and spread to `a[i+1]`, we can spread `a[i+1]` to `a[i+2]`, but its other point will be wasted. However, if we color `a[i+1]` and spread it to `a[i]`, then `a[i]`'s point will be wasted. Either way, we waste a point here, but can color `a[i], a[i+1], a[i+2]` for 1 coin total. Option 2 or Option 3.
- `a[i] = 2, a[i+1] = 1`
If we color `a[i]`, we waste 1 point from `a[i]`. If we color `a[i+1]` we waste 2 points from `a[i]`. Option 3.
- `a[i] = 2, a[i+1] = 2`
If we color `a[i]`, we waste 1 point from `a[i]` and 1 point from `a[i+1]`. If we color `a[i+1]` we waste 2 points from `a[i]`. Option 2 or Option 3.

In the end, the logic can be boiled down to this:
- if `a[i-1] > 0`, we color `a[i]` red for free and continue
- else if `a[i] == 0` and `a[i+1] > 0`, color `a[i]` for free and decrement `a[i+1]` (we will formally color and pay for `a[i+1]` on the next step)
- else pay 1 coin to color `a[i]`

# E: Max to the Right of Min

# F: XOR Partition
