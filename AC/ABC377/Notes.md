Notes on solutions/approaches to problems

# A: Rearranging ABC
Check that there is 1 A, 1 B, and 1 C regardless of order.

# B: Avoid Rook Attack
Board is small, just brute force all squares that are attacked.

# C: Avoid Knight Attack
Board is large, but knights can only attack up to 8 squares at once. So we can just iterate over all the knights and keep track of all attacked squares (using a map so we know if a knight attacks a square that's already attacked).

# D: Many Segments 2

# E: Permute K times 2
Permutation can be reframed as a graph (directed edge from `i` to `j` if `p[i] = j`).

Therefore, the graph is a series of cycles. Find all the cycles. Then, for `k` permutes, we take `2^k - 1` steps along this cycle.

So we simply add this to to the index, modulo the size of this index's cycle.

Use fast exponentation since k can be large.

# F: Avoid Queen Attack

# G: Edit to Match