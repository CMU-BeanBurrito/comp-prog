Notes on solutions/approaches to problems

# A: Alice's Adventures in "Chess"

# B: Alice's Adventures in Permuting

# C: Alice's Adventures in Cutting Cake
Binary search solution. 0 indexed

Alice has some segment of the cake for herself `[L, R]`. For this to be a valid segment, there must have been some number `x` creatures satisfied by the part of the cake `[0, L-1]`, and some `y` creatures satisfied by `[R+1, N-1]`, and `x+y >= m`.

Compute `pc[i]` = creatures satisfied by prefix of cake ending with `i`, `sc[i]` = creatures satisfied by suffix of cake starting with `i`.

Iterate over all choices of `L` for Alice, binary search to find the rightmost valid `R`. Use prefix sums to quickly calculate tastiness of `[L, R]` and answer the best one.

# D: Alice's Adventures in Cards

# E: Alice's Adventures in the Rabbit Hole

# F: Alice's Adventures in Addition