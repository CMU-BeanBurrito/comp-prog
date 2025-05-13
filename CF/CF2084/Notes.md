Notes on solutions/approaches to problems

# A: Max and Mod

*explained using 1-indexing since the problem statement uses it.

Let's cover the case when `n` is odd first.

We can see that if `max(p[i-1], p[i]) = i-1`, this will always be the case: 1 mod 2 = 2-1, 2 mod 3 = 3-1, etc.

So, let's try `p[i] = i-1` and `p[i-1] = i-2`. Then, `p[2] = 1, p[3] = 2, p[4] = 1`.

However, we have one remaining element (`n`), and one remaining empty index (`1`).
It turns out we can just do `p[1] = n`, as `max(p[1], p[2]) mod 2 = 1`, since `n` is odd.

So, we are doing `n, 1, 2, 3....n-1`.

What if `n` is even?

We cannot do `p[1] = n`, since `max(p[1], p[2])` will be `n`, and `n mod 2 = 0`, but we need it to be 1.
We cannot do `p[2] = n`, for the same reason.

We cannot do `p[n-1] = n`, since `max(p[n-1], p[n])` will be `n`, and `n mod n = 0`, but we need it to be n-1.
We cannot do `p[n] = n` for the same reason.

Since we can't place `n` at an endpoint (`p[1], p[n]`), wherever we put `n`, it will have to satisfy `n mod x = x-1` and `n mod (x+1) = x`.

If `x` is even, then `n mod x` is even, but `x-1` is odd.
If `x` is odd, then `n mod (x+1)` is even, but `x` is odd.

Even modulo even can never be odd, so there is no solution.

# B: MIN = GCD

Find the minimum element `mn`, and its frequency. If its frequency is at least 2, the answer is YES:
- Put `a[n] = mn`
- Choose `i = n-1`
- `min(a[1], a[2]....a[n-1]) = mn`, since there's at least one instance of `mn`
- `gcd(a[n]) = mn`, since it's the only element in this segment.

Otherwise, we have to do some more work.

So, there is only one instance of `mn`. Clearly, `mn` must be on the "min" side. If it was on the "gcd" side, the gcd of that side would be at most `mn`, and then the min from the "min" side will be greater than `mn` since all other elements are greater than `mn`.

So, we need to find a group of elements whose gcd is `mn`. So, we collect all elements in `a` that are divisible by `mn`. We ignore `mn`, since it cannot be on the gcd side as described above.

If we were only able to collect one element, then the answer is NO, since the gcd of this element `e` is just `e != mn`.

Otherwise, we take the gcd of all the elements we collected. If this gcd is equal to `mn`, the answer is YES, otherwise NO.

# C: You Soared Afar With Grace
*explained with 0 indexing

For an index `i`, call `a[i]` and `b[i]` a "pairing".

The actual pairings do not change during an operation, the pairings just move to a different index.

Let's note that if `a[i], b[i]` is a pairing, `b[i], a[i]` must be a pairing. If `n` is odd, then these are the same pairing and `a[i] = b[i]`, there must be exactly one pairing like this. If `n` is even, there must be zero.

If there is a pairing whose "mirror" does not exist, the answer is `-1` and there is no solution.

To construct the list of operations:
- if `n` is odd, we need to move the pair of `a[i] = b[i]` to the middle
- then, we iterate over the list, for each pairing, its mirror should be in the mirrored position (i.e. `i`, mirrored position is `n-i-1`).
- if its mirror is not in the correct position, we swap the mirror and the element occupying the mirror's spot.

We can see we will actually be done by the time we get to the middle (`n/2`). We can use a map to track and quickly find which indices each element is at during the operations.

# D: Arcology on Permafrost

There are 2 constraints on `f(a)`, the MEX of the array after the operations are finished.

Clearly, `f(a)` cannot exceed the number of elements remaining after the operations, which is `n - mk`.
However, `f(a)` also cannot exceed `n / (m+1)`. Why?
- Suppose `f(a) = x`
- After the operations are concluded, we have at least 1 of each `0, 1, 2, ...x-1`
- There are `m` removals, so if we started with `m` or less instances of an element in `[0, x-1]`, our adversary could remove all instances of this element
- Then, `f(a)` would not be `x`. So, we need to have `m+1` instances of each element less than `f(a)`. In other words, we need to have `f(a)` elements that each have `m+1` or more instances.

So, `f(a) = min(n - m*k, n / (m+1))`.

How to construct the sequence? Clearly, we will not use any numbers greater or equal to `f(a)`.

Start with this strategy. We already established that we will have at least `m+1` instances of each element `0, 1, 2....f(a)-1`.

If we construct our sequence such that any single removal cannot remove more than 1 instance of a particular element, at least 1 instance of each element will survive the `m` removals, and we will reach the desired `f(a)`.

To do this, we can see that we need to "space out" instances of the same element. Clearly, we should space them out by at least `k`, so a removal of length `k` can never remove 2 or more instances of the same element. However, we should also separate by at least `f(a)`, since we need to fit `f(a)` elements at least `m+1` times each.

So, our spacing `s = max(k, f(a))`.

We can do the following strategy:
- Put 0 at 0, s, 2s, 3s...
- Put 1 at 1, s+1, 2s+1, 3s+1...
- Put 2 at 2, s+2, 2s+2, 3s+2...

Unfilled spaces can have any number x such that `0 <= x <= 1E9` (set by problem).

# E: Blossom

# F: Skyscape

# G1: Wish Upon a Satellite (Easy Version)

# G2: Wish Upon a Satellite (Hard Version)

# H: Turtle and Nediam  2
