Notes on solutions/approaches to problems

# A: Make A Equal to B

# B: Playing with GCD
Suppose `a[i] = x` and `a[i+1] = y`.

Then, `b[i]` must be at least `LCM(a[i], a[i+1])`.

Generate `b`:
- `b[1] = a[1]`
- `b[n+1] = a[n]`
- `b[i] = LCM(a[i-1], a[i])`

Then, check whether this is valid or not.

# C1: Good Subarrays (easy version)

# C2: Good Subarrays (hard version)

# E: Equal Binary Subsequences

# F: Swap and Take