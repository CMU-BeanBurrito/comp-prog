Notes on solutions/approaches to problems

# A: Status Code
Simply check if the input is within the range 200 to 299, inclusive.

# B: Unauthorized
We can simulate the entire process naively.

Maintain two variables: flag indicating whether we are logged in or not, and count of authentication errors (answer).

Simply update the variables based on each operation:
- `login`: login flag = true
- `logout`: login flag = false
- `public`: do nothing
- `private`: if login flag = false, increment authentication error count

Return authentication error count as the answer.

# C: K-bonacci

There are two cases: `k > n` and `k <= n`.

Case 1: `k > n`

We can see that `A[n]` will be 1, as it is part of the first segment, so we are done.

Case 2: `k <= n`

We can see that the first `k` elements are `1`, every subsequent element is the sum of the previous `k` elements.

Therefore, we know `A[k] = k` (as it is the sum of the `k` `1`s at the start of `A`).

Now, the next element `A[k+1]` is the sum `A[1] + A[2] ... + A[k]`. However, `A[k] = A[0] + A[1] ... + A[k-1]`.

So, `A[1] + A[2] ... + A[k-1] = A[k] - A[0]`. So, `A[k+1] = 2*A[k] - A[0]`.

We can generalize this for all remaining elements `i > k`: `A[i] = 2*A[i-1] - A[i-k-1]`.

Remember to calculate every value modulo 1E9, return `A[n]` as the answer.

# D: Logical Filling

Clearly, any `?` that are adjacent to an `o` can immediately be confirmed as `.`.

Now count how many `o`s we have (call this `os`).

There are three cases:
- Case 1: all remaining `?` can be confirmed as `.` (`os == k`)
- Case 2: not all remaining `?` can be confirmed as `.`, there are 2 subcaes to consider
  - Case 2a: the max amount of `?` will have to be converted into `o`
  - Case 2b: less than the max amount of `?` will have to be converted into `o`

Case 1: all remaining `?` can be confirmed as `.`.

Simply will in all remaining `?` with `.` and return the answer.

Case 2: at least some of the `?` will be made into `.` How to we know whether the max amount must be converted?

We determine what the max amount is:
- for each contiguous block of `?`s (even of length 1) of length `x`, up to `ceil(x/2)` of the `?` can be converted.
- find the max amount for all blocks and sum them up, call it `mx`
- if `mx + os == k`, then we must convert the maximum amount of `?` into `.` and we are in case 2a. otherwise we are in 2b.

Case 2a: We need to convert the maximum amount of `?` to `o`.
- For each contiguous block, the block has odd or even length.
- If it has odd length `x`, then there is only one way to maximize it: `????? -> o.o.o`, so the 1st, 3rd, 5th, xth will all be `o`, rest will be `.`
- If it has even length `x`, then there are two ways to maximize it: `???? -> o.o. OR .o.o`, since both are valid, all `?` in this block will remain as `?`

Case 2b: We do not need to convert the maximum amount of `?` to `o`.
- Since any individual `?` may be converted, but does not have to be, we will leave all of the remaining `?` as `?`.

# E: Reachable Set

# F: Add One Edge 3

# G: Push Simultaneously