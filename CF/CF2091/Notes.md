Notes on solutions/approaches to problems

# A: Olympiad Date
Construct map with counts of needed digits.
Read in all input and simulate the pulling process, checking if we are done after each pull.

# B: Team Training
If a single student is strong enough, they should be on a team by themselves, since adding more students to the team doesn't make any additional strong teams, and those extra students might be able to make another strong team.

Sort in descending order, if a student can be their own team, do so. If not, add the next student to their team, and so on, until their team is strong enough.

If we reach the end and some suffix of the students collectively are not strong enough, we do not need to worry about adding them to existing teams of sufficient strength due to the reason outlined above.

# C: Combination Lock
Even `n` has no solution.

For odd `n`, do `n, n-1, n-2....1`

# D: Place of the Olympiad
Each row can be treated independently.

What is the max number of participants we can seat in a row of `m` if we can't have a bench longer than `x`?

This means that 1 out of every `x+1` spots must be vacant. So, for each row, `m/(x+1)` spots must be vacant. We round down since there will be less than `x` spots at the end that can be occupied. So, the total number of spots we can use for the whole venue without having a bench longer than `x` is `n * (m/(x+1))`.

If we keep increasing the length of the maximum bench, eventually we will find a suitable solution (since all participants will fit in the venue). We can also always find a solution with max bench length `L+1` if we found a solution for max bench length `L`. Lastly, we cannot have a bench less than 1 since at least 1 particpant will always exist.

So, we can use binary search on the bench length, starting with feasible interval `[1, m]`. Check if the max number of participants we can accomodate for this bench length `x` is greater than or equal to `k`. If it is, this bench length is feasible, and our max feasible answer is `x`. If it is not, then this max bench length is too short and the minimum our answer can be is `x+1`.

# E: Interesting Ratio
If we look at the prime factorizations of two numbers `a, b`, the LCM is found by looking at each prime factor for `a` and `b`, and selecting the higher power of the two. Then we multiply all these powers of primes. Conversely the GCD is found by selecting the lower power of the two.

Therefore, the quotient of LCM/GCD is the product of powers of primes, where the power for each prime is the absolute difference between the two powers of primes in the numbers `a, b`.

For a ratio to be interesting, the sum of these absolute differences must be exactly 1. In other words, `b` must be a prime multiple of `a`. 

If `p` is a prime number:
- `1, p` is interesting
- `2, 2p` is interesting
- `3, 3p` is intersting
- etc.

So, for each choice of `a`, any pair `a, ap <= n` will qualify. This means that for each choice of `a` (`1 <= a < n`), any primes `p <= n/a` will qualify.

So, we use the sieve of Eratosthenes to collect all primes up to the max value of `n`. Then, we iterate over all values of `a`, and for each of them, we count how many primes will qualify.

# F: Igor and the Mountain

# G: Gleb and Boating