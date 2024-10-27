Notes on solutions/approaches to problems

# A: Rectangle Arrangement
Observe that the perimeter of any contiguous region is the same as the perimeter smallest rectangle that contains it.

So we want to use all our stamps in as small a rectangular area as possible and this rectangle's perimeter is the answer.

# B: Stalin Sort

Observe that if after the removals, the maximal element is at the start of the array, the array is vulnerable (since we could just Stalin sort until only the maximal elmeent remains). This the optimal strategy.

To do this for a certain element, we need to remove all the elements that precede it, and any greater elements that come after it. Find this quantity for each index in the array. The answer is the minimum.

It is worth noting that since the input size is restricted to 2000, O(n^2) is sufficiently fast.

# C: Add Zeros
We can see that each index can contribute zeroes at most once, and the array must be a specific length in order for this index to contribute. 

Construct a graph - if a certain array length u allows us to contribute a certain number of zeros v, then there is an edge from u to u+v, since if there is an index that requires a to be length u+v, it can also contribute its zeroes.

Now we simply search the graph (DFS or BFS) to find the maximum length we can traverse to, starting at the initial length.

# D1: The Endspeaker (Easy Version)


# D2: The Endspeaker (Hard Version)


# E1: Bit Game (Easy Version)


# E2: Bit Game (Hard Version)
