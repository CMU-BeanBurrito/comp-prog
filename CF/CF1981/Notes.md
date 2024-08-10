Notes on solutions/approaches to problems

# A:
Choose number with highest number of prime factors.
This is the largest power of 2 available.
There is always a power of 2 available since 2l <= r

# B:
The "span" of numbers that we include in n's bitwise OR increase by one on either side each second.

We know to include a bit if it is set to 1 at least once during this span. To check this, we start at the left/lower end of the span, if the bit is set to 0, we see if it will be set to 1 before the right end of the span.

# C:
If all elements are -1, fill in with 1s and 2s.

Can fill in all -1 before the first actual element by multiplying and dividing by 2, similarly with all the -1 after the last actual element.

Now, we need to fill in the -1s in between the actual elements.

Find the LCA of these two elements, and the shortest path between them that includes the LCA. If this path length has the same parity as the distance between the two elements in the array, we can fill in the spaces between them. Otherwise it is impossible.

Use this path to fill in the spaces between the two elements. If it is not long enough, just pad it by multiplying and dividing by 2 since it is the same parity.

# D:

# E:

# F:

# G: