Notes on solutions/approaches to problems

# A: Two Screens
Since copying overwrites the entire destination, copying is only useful if the two strings have a common prefix.

Check how long the common prefix is.

If we do not copy at all, our answer is len(s) + len(t).

If we copy, our answer is len(s) + len(t) - len(common prefix) + 1 (since it takes 1 second to copy).
- Subtract len(common prefix) since we copy these characters once instead of twice
- Add 1 since it takes 1 second to copy

Whichever of these is lesser is the answer.
- If len(common prefix) is 0, then there is nothing to copy so not copying is clearly faster
- If len(common prefix) is 1, they are equivalent
- If len(common prefix) is > 1, copying saves us time and is the answer

# B: Binomial Coefficients, Kind Of
Clearly, if `n = 0` or `k = n`, `C[n][k] = 0`.

Manual calculation reveals that otherwise, `C[n][k] = 2^k`.

Precompute powers of 2, mod 1E9 + 7, simply return the appropriate power based on `k[i]`.

# C: New Game
Clearly, all the cards selected must be consecutive. 
More formally, if we have cards with distinct values `x, y`, we also have cards for every value `i, x < i < y`.

First, use map to track frequency count of each type (`a[i]`) of card.

Next, sort card types into classes. A class contains all card types that exist in the deck and are consecutive, and no other types.

We can only select cards for one class.

If a class has at most k types, we can select all cards whose type is in this class. This class's score is the sum of all its types' frequencies.

If a class has at more than k types, we have to select a contiguous subset (with length k) of this class.
To quickly determine which subset of these is best, use a sliding window of length k (or prefix sum) and see which window has the highest sum of frequencies.
This highest window is the best score for this class.

Return the best score among all classes.

# D: Attribute Checks

# E: Card Game

# F: Choose Your Queries

# G: Variable Damage
