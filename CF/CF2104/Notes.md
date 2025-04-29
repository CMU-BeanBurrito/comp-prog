Notes on solutions/approaches to problems

# A: Three Decks
If the sum of the totao numbers of cards is not divisible by 3, clearly the answer is no.

The other case in which the answer is no is if deck B already has more cards than the average of the 3 decks. This is because B can only gain cards and if it already has more than the target value, there is no solution (i.e. a = 2, b = 9, c = 10).

If we are in neither of the above two cases, the answer is yes.

# B: Move to the End
*using 1-indexing in this explanation to match problem statement

We want the sum of the last k elements to be maximized.

We can reframe the operation as making this choice:
- do nothing, or
- remove `a[n-k+1]` from the suffix and add any element from `a[1, n-k]`

Clearly, if we choose the second option, we choose the maximum element in `a[1, n-k]`. 

So, if the maximum element in `a[1, i]` is `x[i]`, then:

`ans[k] = sum(a[n-k+1, n]) + max(0, a[n-k+1] - x[n-k])`

We can easily compute `x` by iterating over `a`, and `x[i]` is the largest element seen so far.

# C: Card Game

# D: Array and GCD

# E: Unpleasant Strings

# F: Numbers and Strings

# G: Modulo 3
