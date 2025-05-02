Notes on solutions/approaches to problems

# A: Permutation Warm-Up

`f(p)` is always even, since the number of odd elements on even indices must equal the number of even elements on odd indices. Clearly, `f(p)` is the sum of the absolute distances between `p[i]` and `i`.

The max value of `f(p)` is if `p` is "backwards": `n, n-1, n-2,...3, 2, 1`.
- If `n` is even, then this value is `n*n/4`
  - distances will be `n-1, n-3, n-5,..., 1, 1, 3, ...., n-3, n-1`
  - `f(p) = 2 * (sum of first n/2 odd numbers)`
  - can be derived as (sum of first n numbers) - (sum of first n/2 even numbers)
  - this is the same as (sum of first n numbers) - 2*(sum of first n/2 numbers)
  - `n*(n+1)/2 - 2*(n/2)*(n/2 + 1)/2`
  - `n*(n+1)/2 - (n/2)*(n/2 + 1)`
  - `n/2 * [(n+1) - (n/2 + 1)]`
  - `n/2 * n/2 = n*n/4`
- If `n` is odd, then this value is 
  - distances will be `n-1, n-3, n-5, ..., 2, 0, 2, 4, ... n-3, n-1`
  - `f(p) = 2 * (sun of first n/2 even numbers)`
  - can be derived as 2 times (sum of first n/2 numbers)
  - `2 * (n/2) * (n/2 + 1) / 2`
  - `(n/2) * (n/2 + 1)`

These values can be calculated iteratively (i.e. loop over 1, 3, 5, 7, 9, etc. and add them up). There is enough time within the time limit to do it this way and it comes with the benefit of not having to derive the formulae shown above.

Let's call this maximum value of `f(p)` we derived above `m`. We also know that `f(p)` can be `0` (if `p[i] = i` for all `i`). Since we know `f(p)` is even, we know that there are at most `m/2 + 1` values `f(p)` can be. It turns out `f(p)` can be any of these values and `m/2 + 1` is already the answer.

Why can `f(p)` be any even number between `0` and `m`, inclusive? Will not provide full proof here, but essentially start with the permutation `p = 1, 2, 3, 4, 5...`, start with the outer pair `(1, n)`. If swapping them will make `f(p)` too high, do not swap, and move inwards. Otherwise, swap, then move inwards. Repeat until `f(p)` is the precise even value desired.

# B: SUMdamental Decomposition

For a certain bit `b`, if `x & (1 << b)`, we need an odd amount of elements to have `1` on the `b`th bit. 

Clearly, our elements have to sum to at least `n`. If the number of bits asserted in `x` exceed the value of `n`, we are done. Otherwise, it means we have some 0s (which are not allowed). So, we have to assert various bits to make all our elements non-negative. 

For each bit, if we assert this bit in an even number of zeroes, we will not affect the XOR. Since we want to minimize the sum, we start at the least significant bits. We can assert a bit in up to `n` elements, but this number should have the same parity as before this step.

# C: Neo's Escape

Each "peak" needs an agent. This is because an agent can clear an entire peak by itself, but cannot clear multiple peaks (it would have to clear a higher value later).

# D: Needle in a Numsack

Binary search

# E: Spruce Dispute

# F: Fallen Towers