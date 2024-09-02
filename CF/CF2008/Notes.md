Notes on solutions/approaches to problems

# A: Sakurako's Exam
If a is odd, the answer is no since there will be a single 1 with nothing to cancel it out, since 2s cannot cancel 1s.

If a is 0, then we only have 2s, so we need an even amount of 2s. If we do, then the answer is yes. If a is 0 and b is odd, the answer is no.

Now we are left with following case: a is even, but greater than 0.

In this case, the answer is yes. If b is odd, then we save 2 1s to cancel out the last 2. If b is even, all the 2s will cancel each other, and all the 1s will cancel each other.

# B: Square or Not
Clearly, the length of s has to be a square of an integer. I used binary search to quickly check if it is, and return the square root if it n is a square. However, linear search from 1 to sqrt(n) is sufficiently fast.

If n is not a square, the answer is no.

If it is, we need to check that the outside is all 1s, and the inside is all 0s. To do so, we iterate over s as a square, with sqrt(n) rows and sqrt(n) columns. The first and last row should be 1, and the first and last column should be 1. All other cell should be 0.

I used i as my row iterator and j as my column iterator. So if either i or j is 0 or sqrt(n)-1, we are on the outside. If we find a 0 on the outside we should answer no. If we are anywhere else, we are on the inside and should answer no if we see a 1. If we traverse through s without answering no, then the answer is yes.

# C: Longest Good Array
The strategy is to start with l, then go to l+1, l+3, l+6, etc.

In other words, the differences between adjacent elements should be 1, 2, 3, 4....

This will maximize the number of elements we can add before we reach r.

We are only interested in the number of elements we end up adding before we reach r. We can use r-l and binary search to quickly find the number of elements we can add. If we add 1 element (aside from l), then our last element will be l+1. If we add 2 elements (aside from l), our last element will be l+3. 3 elements, l+6. So if r-l is 5, we can only add 2 elements.

So, we will compare r-l to the Gauss sum of some number of elements. See REFERENCE.md for info on Gauss sum. Let's say we want to know if we can add 10 elements. We compare r-l to Gauss(10).
- if r-l == Gauss(10), then we can add 10 elements, but we cannot add any more. So we are done.
- if r-l > Gauss(10), then we cannot add 10 elements and should try a smaller number
- if r-l < Gauss(10), then we can add 10 elements, and possibly more

We use binary search to hone in on the max answer. Since r is 1E9, we can add a maximum 44,271 elements since the Gauss sum of any higher number is greater than 1E9.

Important implementation detail: when the binary search concludes, left will be 1 higher than the actual number of elements we are adding after l. But since l counts as an element, the total number of elements we are adding is indeed left.

# D: Sakurako's Hobby

Treat this permuation as a graph. Each index (node) will be part of a cycle. The cycle might be length 1 (if `i == p[i]`).

Each index can only reach the indices in the same cycle as itself. So, the answer for each index is the size of black numbers in its cycle.

As we traverse/build the groups, we will do two additional things: maintain the number of groups we have so far (this will also serve as the group's ID), and maintain the number of black numbers in the group while we build it.

In order to build the groups, we can mark a node visited and traverse its edge by going to index p[i]. If this node is already visited, we have traversed the entire group. Increment the group count so the next group has a new ID.

After the whole graph has been traversed, traverse across each index and print the number of black integers in that index's group.

# E: Alternating String

If the string is even length, we do not do a deletion. We will need to choose a character on an odd index to convert all the odd indices to. Simply pick the most common one. Same with even indices.

If the string is odd length, we need to do a choose a character that will be on odd indices, and a character that will be on the even indices, then do a deletion that will allow us to do the fewest modificaitons.

For each letter c, and position i in the string, track how many times this character c was seen on:
- an odd index before this index i
- an even index before this index i
- an odd index after this index i
- an even index after this index i

So, if we delete i, all characters on even indices greater than i will now be on odd indices, all characters on odd indices greater than i will now be on even indices.

So, we should choose character co to be put on odd characters, character ce to be put on even characters, and index i to delete such that the following quantity q is maximized:
- `preeven[ce][i] + preodd[co][i] + posteven[co][i] + postodd[ce][i]`

That way, when we delete index i, all the co's on even indices greater than i will be on odd indices. And all ce's on odd incides greater than i will be on even indcies. So we will have the maximum number of characters that do not require modification (minimum operations).

Our answer is then 1 + (n-1-q):
- 1 deletion operation
- n-1 charaters remaining, q of which do not need to be modified: n-q-1 modifications
- n-q is the final answer

# F: Sakurako's Box

Find P (numerator) and Q (denominator) separately. N = 1E9 + 7

P is the sum of all products of pairs. Using prefix sum, add the product of each index and the sum of all previous indices. Make sure to keep this sum of products modulo N.

Q is n choose 2. However, since this is the denominator, we need to calculate its inverse modulo N, then multiply P by this inverse. See the Extended Euclidean section in REFERENCE.md.

Now we simply answer P * inv(Q) modulo N.

# G: Sakurako's Task

# H: Sakurako's Test