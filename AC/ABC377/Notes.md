Notes on solutions/approaches to problems

# A: Rearranging ABC
Check that there is 1 A, 1 B, and 1 C regardless of order.

# B: Avoid Rook Attack
Board is small, just brute force all squares that are attacked.

# C: Avoid Knight Attack
Board is large, but knights can only attack up to 8 squares at once. So we can just iterate over all the knights and keep track of all attacked squares (using a map so we know if a knight attacks a square that's already attacked).

# D: Many Segments 2
Observe that if a pair `(l, r)` is valid, then `(l+1, r)` is valid (if `l+1 <= r`).

Therefore, for each `r`, there is some earliest `l` for which `(l, r), (l+1, r)....(r, r)` is valid (or there are no valid pairs `(x, r)`). Call this earliest valid `l = f[r]`. Clearly, this value must be greater than `Lmax[r]`, which is the greatest value `L` for which there exists a segment `L, R`.

Also, `f[r]` must be at least `f[r-1]`. If `x= f[r] < f[r-1]`, then `(x, r-1)` would also be valid.

So, `f[r] = max(Lmax[r]+1, f[r-1])`.

Summary of logic:
Init `d[r] = 1` for all `r` (clearly cannot be further left than this, so start with best case scenario).
When we read in the segments, `d[R[i]] = max(d[R[i]], L[i]+1)`, this will maintain `Lmax+1` for each `r` while we read in.
Iterate over `r, 1 <= r <= M`.
- `d[r] = max(d[r], d[r-1])`, we have to choose whichever is more restrictive, `d[r-1]` or `Lmax+1[r]`.

Answer is sum of valid segments for each `r`, which is `r-d[r]+1`.

# E: Permute K times 2
Permutation can be reframed as a graph (directed edge from `i` to `j` if `p[i] = j`).

Therefore, the graph is a series of cycles. Find all the cycles. Then, for `k` permutes, we take `2^k - 1` steps along this cycle.

So we simply add this to to the index, modulo the size of this index's cycle.

Use fast exponentation since k can be large.

# F: Avoid Queen Attack

# G: Edit to Match
