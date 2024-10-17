Notes on solutions/approaches to problems

# A: Destroying Bridges
There are n-1 bridges leaving island 1. If we can destroy all of those, then the answer is 1.

If we cannot destroy n-1 bridges, then we cannot disconnect any island from the network so the answer is n.

# B: Equal XOR
Each number (1 to n) must have both its occurrences in the first half, both in the second half, or one in each half.

Both first half: add both occurreences to the left array. This will not affect left XOR, keeping left and right XOR equal.
Both second half: add both occurrences to the right array. This will not affect right XOR, keeping left and right XOR equal.
One each half: add one occurrence to each array. This will have the same effect on left and right XOR, keeping them equal.

Left and right arrays have to be even length, so make sure to add the appropriate number of elements. Of the numbers that have one
occurrence in each half, we should only add an even number of those to each array. I handle that by adding only numbers that have both
occurrences in one half to keep left and right lengths even. If those are exhausted and the left and/or right arrays are not full, I add
numbers with one occurrence in each half.

# C: MEX Game 1
It is clear to see that both players will ignore numbers greater than MEX(a). This is also the maximum score Alice can achieve. Find this
first as it will be useful later.

For Alice to achieve a certain score X, all numbers below X must have frequency at least 2, except for one element that can have frequency 1.

We know all elements < MEX(a) have at frequency at least 1.

Iterate from 0 to MEX(a)-1. The second time we see an element with frequency 1, this is the answer. If at most one element in this range has 
frequency 1, then the answer is MEX(a).

Why?

As mentioned above, it is clear that both players will ignore numbers greater than MEX(a), at least until the score can no longer be affected.
If an element has frequency of at least 2, Alice can always get it. This is because if Bob deletes it, she can take the second occurrence of it.
However, since Alice goes first, she can take one element that has frequency 1. Aside from that first element, any other element that has frequency 1
could be denied by Bob. Essentially, Alice can "follow" Bob's moves and ensure that she collects all the elements with frequency 2. Therefore, when Alice
makes her first move, Bob should take the lowest number with frequency 1 (excluding the number Alice took).

# D:

# E:

# F:

# G: