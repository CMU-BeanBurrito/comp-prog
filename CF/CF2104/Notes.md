Notes on solutions/approaches to problems

# A: Three Decks
If the sum of the total numbers of cards is not divisible by 3, clearly the answer is no.

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

`ans[k] = suf[n-k+1] + max(0, mx[n-k] - a[n-k+1])`
`ans[n] = sum(a[1, n])`, as we have nothing to swap if `k` spans the whole array

We can easily compute `x` by iterating over `a`, and `x[i]` is the largest element seen so far.

# C: Card Game

Start by breaking this down into 2 cases:
- Alice has card `n`
- Bob has card `n`

Alice has card `n`:
- If Alice has card `1` and card `n`, she wins. This is becuase card `1` is the only card that beats card `n`, and she knows Bob does not have card `1`. So she can play card `n` for the entire game and win every turn.
- If Alice has card `n-1` and card `n`, she wins. This is becuase card `n` is the only card that beats card `n-1`, and she knows Bob does not have card `n`. So she can play card `n-` for the entire game and win every turn.
- Otherwise, Alice loses. Suppose Bob has card `1` and card `n-1`, and Alice has all other cards. If she plays card `n`, Bob will play card `1` and win the turn. If she plays any other card, Bob will play card `n-1` and win the turn.

Bob has card `n`:
- If Bob has card `n` and one more card `x`, Bob wins. This is because card `1` is the only card that beats card `n`, and since Bob sees what card Alice plays before he plays, if Alice plays card `1`, he plays card `x` and wins the turn. If she plays any other card, Bob plays card `n` and wins the turn.

So, if Alice has card `n`, she also needs card `n-1` or card `1`. If Bob has card `n`, he just needs one other card (any card).

# D: Array and GCD

The cheapest ideal array of size `x` is the `x` smallest primes. An array of size `x` is beautiful if its sum equals or exceeds the sum of the first `x` primes, since when making an array ideal, we can change any or all elements as long as the sum does not increase.

So, we need to find the largest `k` such that the sum of the `k` largest elements in `a` is greater than or equal to the sum of the `k` smallest primes.

We do the following pre-processing to later be able to quickly compute the sum of the `k` smallest primes:
- Sieve of Eratosthenes
  - `n <= 4E5`, so we only need to worry about up to `4E5` primes. This is less than `6E6` which we have time to process. So our sieve can be size `6E6`.
- Gather all primes from the sieve
- Compute prefix sum on the array of primes, call this `p_primes`

We then sort the array `a` in descending order and compute a prefix sum `p` on it. We iterate backwards across `p`, and the first time we see `p[i] >= p_primes[i]` we have found the answer, `k = i`: the sum of the greatest `k` elements in `a` is greater than or equal to the sum of the smallest `k` primes. This is also the greatest value of `i` for which the statement is true (since we iterated backwards).

Therefore, we only need to remove `n-k` elements from the original array.

# E: Unpleasant Strings

# F: Numbers and Strings

# G: Modulo 3
