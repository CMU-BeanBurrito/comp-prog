Notes on solutions/approaches to problems

# A: 123233

Take n is as a string, count the frequency of each character and see if it matches the requirements.

# B: Hurdle Parsing

Count the number of dashes since the last pipe. If we see a pipe, append dash count to answer and reset dash count to 0.

# C: Move Segment
*blocks are 1-indexed

Traverse the string to get 3 variables `x, y, z`: the last index of (k-1)th 1 block, the first index of the kth 1 block, and the last index of the kth 1 block.

Then, output the original string up to and including the (k-1)th 1 block (start of the string through x). Then, we need to output the kth 1 block (y through z). Then, we need to output the 0 block that preceded the kth 1 block (x+1 through y-1). Then we output the rest of the string that followed the kth 1 block (z+1 to end).

# D: Strange Mirroring
*0-indexed, decrement k upon reading it in

It is easy to find which index in the original string `S` corresponds to the index `k` in the final string `S'`, we simply take `rem = k % n`, where `n` is the length of the original `S`. All we have to figure out is whether or not to flip the case of this character.

Imagine a binary string `F`, where `F[k] = 0` if `S[rem] == S'[k]`, that is, the character's case was not flipped. And `F[k] = 1` if `S[rem] != S'[k]`, that is the character's case was flipped.

By looking at some small cases manually, we can see that `F` is initally `n` 0s. Then it is `n` 0s followed by `n` 1s:
- n(0)
- n(0) + n(1)
- n(0) + n(1) + n(1) + n(0)
- n(0) + n(1) + n(1) + n(0) + n(1) + n(0) + n(0) + n(1)

We can see that on each operation, each set of n bits inserts a set of n bits (of which they are the negation) directly to the right of it.

In other words, every n(0) becomes n(0) + n(1).

We can also see that the for the `i`th set of bits prior to an operation, after the operation, the `2*i`th set of bits will be the same as the `i`th set, and the `2*i+1`th set will be the negation.

Since we know what set we are in: `quot = k/n`, we can backtrack to see how many negations there were to get to this set.

This can be visualized as a perfect binary tree. Initally, there is only a root with a 0. Then, on every operation, every leaf node that is a 0 gets a left child with 0 and a right child with 1. Every leaf node that is a 1 gets a left child with 1 and a right child with 0. So, we are simply backtracking until we get to the level with 2 nodes.

We repeatedly divide `quot` by 2, if `quot` is odd, this means it is the negative child, and is the negation of its parent. Otherwise, it will be the same as its parent. 

Clearly, if we have an even number of negations, then `S'[k] = S[rem]`. If there are an odd number of negations, then `S'[k]` is `S[rem]` with its case flipped.

# E: 1D Bucket Tool
Note: my solution is very similar to the editorial's solution with ordered set, so I will just discuss the differences between that solution and mine, as well as some additional thoughts/elaboration.

My map maintains the inclusive right endpoint of each segment in addition to the color. So:
- `mp[i].first` = the inclusive right endpoint of the segment starting at `i`
- `mp[i].second` = the color of the segment starting at `i`

To check whether we need to merge the current segment (the one in which the queried index lies) with its neighbors, we can iterate forwards/backwards and check the color of those segments. To merge two segments, we just set the right endpoint of the left segment to the right endpoint of the right segment, and now the left segment contains both.

# F: Exchange Game

# G: Another Shuffle Window