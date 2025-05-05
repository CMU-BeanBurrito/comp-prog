Notes on solutions/approaches to problems

# A: 

The GCD of a sequence cannot exceed the maximum element in that sequence.

So, take the maximum element `mx` (or 1 instance of it) and put it in B, `gcd(B) = mx`.

Put all remaining elements in C, it will have at least one element `e, e < mx`, so `gcd(C) < mx, gcd(C) != gcd(B)`.

The only time this is not true (and therefore the only time the answer is `No`) is if all elements in sequence `A` are equal. Then, no matter which sequence the elements are assigned to, the gcd of both sequences will be the only distinct element in `A`.

# B: 

If we ignore the second loss condition (difference between min and max exceeds `k`), then it's easy to see that Tom wins if the total number of apples in all the boxes is odd, and Jerry wins if it is even.

How/when does the second loss condition come into play? Except for the first turn, at the start of every subsequent turn, the difference between the min and the max does not exceed `k`, otherwise the game would have ended after the previous turn. Given that, the current player is never forced to lose by this condition as they can just take an apple from the box with the most apples. At worst, this will make the difference between min and max go from 0 to 1 (if the boxes all had the same numbe of apples). `k >= 1` so the second loss condition will not be activated here.

However, we need to consider the first turn. If the difference between min and max exceeds `k+1`, Tom will lose after his first turn as there is no way for him to reduce the difference to at most `k` with just 1 turn.

So, if the difference between min and max exceeds `k+1` initially, Jerry wins.

Otherwise, the winner is determined by the parity of the total sum of apples at the beginning: Tom wins if it is odd, Jerry wins if it is even.

# C: 
*MSAS = maxmium subarray sum
*Take -1E13 as -INF, since it will not overflow but is negative enough to isolate any segments

Start by replacing all forgotten values with -INF, this breaks up the array into segments, each segment is a contiguous block of remembered values. 

Now take the MSAS of the whole array, this is the same as the greatest MSAS of any segment. If this value exceeds `k`, there is no solution.

Otherwise, there is a solution.

Choose any forgotten index (leaving the rest as -INF), we can do binary search on the value that should be at this index.
Why? The editorial has a good in-depth proof/explanation of this, but it boils down to this forgotten index bordering a segment whose MSAS is less than `k`, by tuning this forgotten value, we also tune the MSAS of this segment (or the subarray that is this segment and a neighboring segment).


# D: 

On each step, we should take the maximum number of apples that we can. 

# E: 

# F1: 

# F2: 
