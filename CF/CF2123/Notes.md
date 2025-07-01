Notes on solutions/approaches to problems

# A: Blackboard Game

If Alice chooses a number `a` s.t. `a mod 4`:
- is `0`, Bob must choose a number `b` s.t. `b mod 4 = 3`
- is `1`, Bob must choose a number `b` s.t. `b mod 4 = 2`
- is `2`, Bob must choose a number `b` s.t. `b mod 4 = 1`
- is `3`, Bob must choose a number `b` s.t. `b mod 4 = 0`

If `(n-1) mod 4 == 3`, then every number on the blackboard can be paired, and Bob can win.

Otherwise, there will be at least one number that cannot be paired, Alice picks this number and Bob cannot respond.

So, we just need to check if `n mod 4 == 0`, in which case Bob wins. Otherwise Alice wins.

# B: Tournament

There are two cases:
- the tournament ends with only one player remaining
- the tournament ends with more than one player remaining (`k > 1`)

In the first case, clearly only the player with the maximum strength (or a player tied for the maximum strength) can be the last player standing. So, if the player has strength equal to the maximum, the answer is YES, otherwise it is NO.

In the second case, any player can make it into the last `k`, as they never have to play against anyone. So, the answer is YES.

# C: Prefix Min and Suffix Max

Claim: The answer for a particular element is `1` if one of the following holds (and `0` otherwise):
- there are no lesser elements to the left, OR
- there are no greater elements to the right

## Proof that one of these conditions are sufficient:
Suppose we are looking at element `e`, and there are no lesser elements to the left. We need to eliminate all other elements.
- We can eliminate all elements to the left by doing the "prefix" operation with the prefix ending with `e`. Since `e` is the minimum element in the prefix, all elements to the left are eliminated.
- We can eliminate all elements to the right (except one) by doing the "suffix" operation with the suffix beginning after `e`.
- We now have `e`, and one other element `d` to the right.
  - If `d > e`, we do the prefix operation on the whole array (just `d, e`). `d` will be eliminated, `e` will be preserved.
  - If `d < e`, we do the suffix operation on the whole array (just `d, e`). `d` will be eliminated, `e` will be preserved.

Suppose we are looking at element `e`, and there are no greater elements to the right. We need to eliminate all other elements.
- We can elminate all elements ot the right by doing the "suffix" operation with the suffix ending with `e`. Since `e` is the maximum element in the suffix, all elements to the right are eliminated.
- We can eliminate all elements to the left (except one) by doing the "prefix" operation with the prefix beginning before `e`.
- We now have `e`, and one other element `d` to the left.
  -- If `d > e`, we do the prefix operation on the whole array (just `d, e`). `d` will be eliminated, `e` will be preserved.
  - If `d < e`, we do the suffix operation on the whole array (just `d, e`). `d` will be eliminated, `e` will be preserved.

## Proof that one of these conditions are necessary:
In the "sufficient" proof, we used the following strategy:
- Our target element is either the minimum in the prefix or the maximum in the suffix.
- In the former case, do the prefix operation, use a suffix operation to get down to 2 elements.
- In the latter case, do the suffix operation, use a prefix operation to get down to 2 elements.
- Trivially eliminate the undesired element.
- If both are true, then we can just do a prefix operation and a suffix operation and be done.

If neither are true, then we can get down to 3 elements, we will have `e`, a lesser element to the left, and a greater element to the right. However, we can no longer eliminate any elements without eliminating `e`. Clearly, there doesn't exist a prefix with `e` as the minimum or a suffix with `e` as the maximum, there is also no way to eliminate either of the other two elements without also eliminating `e`.

We've (loosely) proven that if at least one of the two conditions holds for a particular element, it can be the last element remaining. Otherwise, it cannot.

# D: Binary String Battle

It is worth noting that Alice's operation is the same as picking any `k` indices and making them `0`.

There are a few "simple" cases we should handle first:

Case 1: The initial binary string contains at most `k` ones. If this is the case, Alice can clearly win the game immediately.

Case 2: The length of the binary string `n` is greater than or equal to `2*k`, and we are not in Case 1 (so there are at least `k+1` ones) Bob will win. Why?

Bob only needs to guarantee that prior to every Alice turn, there are at least `k+1` ones. He can create a contiguous block of `k` ones, so as long as there is `1` more one outside of that block, there will be at least `k+1` ones. If the `n >= 2k`, then there will always be "room" for this block away from the additional one.

Case 3: We are not in Case 1 or Case 2. Alice wins, she can begin by removing the ones at the ends, Bob will not be able to replace both (or we would be in Case 1). 

On every Alice turn, she can remove exactly `k` ones (unless there are less than `k` left, in which case she wins). However, Bob will not always be able to add `k` ones as he will have to "waste" ones on the middle. Therefore the number of ones will gradually decrease and Alice will win.

# E: MEX Count

# F: Minimize Fixed Points

# G: Modular Sorting
