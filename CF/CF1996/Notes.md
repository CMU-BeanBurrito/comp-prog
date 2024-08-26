Notes on solutions/approaches to problems

# A: Legs

# B: Scale

# C: Sort

# D: Fun

For a particular value of `a`, there are at most $n/a$ values of `b` we should consider. Across all values of `a`, this means we have $n + n/2 + n/3 + .... n/n$ values of `b` to consider. This simplifies to O(n log n) - harmonic series. So we can consider all values of `a` and `b`.

For each pair `a` and `b`, we can find the number of valid triplets in constant time. We simply need to find the maximum value of `c` such that the constraints are met. Clearly, any value of `c` lower than this maximum value will also work for this `a` and `b`. To find this maximum value, solve for `c` in both of the equations and take the minimum. 

The answer is the sum of all valid triplets. 

# E: Decode

# F: Bomb

# G: Penacony
