Notes on solutions/approaches to problems

# A: Quintomania
Simply check all adjacent notes and verify that the absolute difference between them is either 5 or 7. If it is neither, then print NO. If we verify all adjacent pairs to be 5 or 7 semitones apart then print YES.

To accomplish this, we can compare each element to the previous element (starting with comparing the second element to the first).

# B: Startup

Let's call the "value" of a certain brand the sum of the costs of all bottles of this brand that we have.

So this problem boils down to finding the `n` most valuable brands and computing the total of their values.

Use a map to keep track of each brand's value as we iterate over the bottles. Then, sort the values the sum the `n` largest values, or all the values if there are `n` or less brands.

# C: Anya and 1100
There isn't enough time to check the entire string on every query.

So, let's keep track of the number of times `"1100"` occurs in the string, and update this value for each query.

Before any queries, simply count the number of times `"1100"` occurs by iterating over the entire string.

Now, for each query q there are a few cases:
- q's operation did not create a new instance of `"1100"`, but it did not also remove one
- q's operation added a new instance of `"1100"`
- q's operation removed an instance of `"1100"`
- q's operation added a new instance of `"1100"`, but also removed one

How do we know whether q's operation destroyed or created an insatnce of `"1100"`?

To find out if it destroyed one, we first need to see if the index of this operation is part of an instance of `"1100"`. Observe that it's not possible for any index to be part of more than one `"1100"`. Just check the surrounding substrings to see if this index is in a `"1100"`, there are 4 of them. We will see that this index is part of `0` or `1` instance of `"1100"`. Clearly, any `"1100"`s outside this range are unaffected.

Now we perform the operation and update the index. Now we check the same substrings to see how many `"1100"` there are in this range. As with the pre-operation check, we will see that this index is part of either `0` or `1` instance of `"1100"`. The difference between the two (final minus initial) is the change, so we update our total with this. If our total is at least 1, then we print YES. Otherwise, we print NO.

# D: I Love 1543
We can examine each layer indepdently. Consequently, it is useful to be able to extract a given layer from the carpet. First, let's establish the process of examining a single layer assuming we can get a layer into the form a vector of digits ordering the layer clockwise.

To analyze a layer we just have to iterate over it looking for instances of `1, 5, 4, 3`. However, we also have to consider the possibility that this `1, 5, 4, 3` wraps around the end of the vector: for example, the last two elements of the layer are `1, 5`, and the first two elements of the layer are `4, 3` as this would be considered an occurrence of `1, 5, 4, 3`. 

So, how to extract a layer? There are many ways to do it but I prefer to extract one side of the layer at a time:
- top-left corner (inclusive) to top-right corner (exclusive), these are all in the top row (going to the right)
- top-right corner(inclusive) to bottom-right corner (exclusive), these are all in the right column (going down)
- bottom-right corner (inclusive) to bottom-left corner (exclusive), these are all in the bottom row (going to the left)
- bottom-left corner (inclusive) to top-left corner (exclusive), these are all in the left column (going up)

This ensures we collect all elements in clockwise order. It may be helpful to draw some small examples to get the loop guards/bounds exactly right.

The answer is the total number of occurrences of `1, 5, 4, 3` in all the layers.

# E: Reverse the Rivers

First, construct the "map" after the channels are created as shown in the example.

Now, let's focus on handling a single query with a single requirement first. Without loss of generality, let's say it requires the 1st regino to be strictly less than `c`.

We notice that the `i`th regions of each country are non-decreasing. In other words, `b[1][1] <= b[2][1] <= b[3][1]`, etc. 

Initially, all countries are viable, but we need to eliminate country `x` if `b[x][1] >= c`. To do this, we use binary search to find the first country `x` such that `b[x][1] >= c`. Then, all countries `< x` satisfy this requirement. So, range of viable countries narrows from `(1, n)` to `(1, x-1)`.

We repeat this with all the other requirements for this query. When we find a range that satisfies a requirement, the overall range of viable countries is updated to be the intersection between the two ranges since viable countries satisfy all requirement seen so far.

Once we've processed all requirements we check to see if our viable range includes any countries at all. If it does, the answer is the first country in the viable range. If it does not, the answer is -1.

# F: XORificator 3000
First, establish a quick way `f(l, r)` to compute the XOR of a continuous segment `(l, r)`. This is equivalent to doing `f(0, l-1) ^ f(0, r)`.

`f(0, x)`:
- `if (x % 4 == 0), f(0, x) = x`
- `if (x % 4 == 1), f(0, x) = 1`
- `if (x % 4 == 2), f(0, x) = x ^ 1`
- `if (x % 4 == 3), f(0, x) = 0`

Initialize `ans = f(l, r)`, the XOR of all numbers in the input segment. Now we just need to find the XOR of the uninteresting numbers, call this `u`.

Start by finding the first and last uninteresting numbers in `(l, r)`. If there aren't any, we are done.
Otherwise, the uninteresting numbers will be `(x << i) + k, (x << i) + (1 << i) + k, (x << i) + (2 << i) + k, etc.`

So, in `u`, the `i` least significant bits will be `0` if there are an even number of uninteresting numbers and `k` if there are an odd number of interesting bits. What about the more significant bits?

If we right shift all uninteresting numbers by `i` bits, they will be consecutive numbers. So, we can use `f` to find the XOR of the most significant bits of the uninteresting numbers, call this `y`. To find `u`, we left shift `y` by `i` bits and then add the XOR of the `i` least significant bits as described above.

Then `ans ^= u`.

# G: Library of Magic

First, find the highest bit `m` in `n`. Query `2^m, min(2^(m+1)-1, n)`. There are a few outcomes (call the response `resp`):
- `resp = 0`. This means that all 3 of the missing tomes are outside of this interval. So they are all inside `1, 2^m - 1`. why?
 - If 1 tome was in this interval, `resp` would equal this tome.
 - If 2 tomes `a, b` were in this interval, `resp` would equal `a ^ b`, which cannot be 0 as `a, b` are distinct.
 - If 3 tomes were in this interval, `resp & 2^m = 1`, since all 3 numbers would have bit `m` set to 1.
 - decrement `m` and repeat
- `resp = total`, where `total = a ^ b ^ c`. All 3 tomes are in `2^m, min(2^(m+1)-1, n)`. Binary search to split off 1, then binary search to split the remaining 2
- `resp != total && resp != 0`. This means that at least one of the tomes is outside the interval `2^m, min(2^(m+1)-1, n)`. There are two cases:
 - `resp & (1LL << m) == 0`. 2 tomes are within `2^m, min(2^(m+1)-1, n)`. This means that the third one is `total ^ resp`. Now we binary search on `2^m, min(2^(m+1)-1, n)` to try to split the other two.
 - `resp & (1LL << m) != 0`. 1 tome is within `2^m, min(2^(m+1)-1, n)`, it is `resp`. Binary search on `(1, (1LL << m) - 1` to split the other 2.

Binary search:
- if `resp = 0`, all remaining tomes are in the other half of the interval
- if `resp = total*`, all remaining tomes are in this half (total* is the XOR total of remaining tomes, excluding found ones)
- else, we found a tome
