Notes on solutions/approaches to problems

# A: Vlad and the Best of Five
Count freq(A) and freq(B), output the character with the higher frequency.

# B: Vlad and Shapes
A square has the same number of 1s in each row of the square, a triangle will not.

So we scan the grid (starting at the top) until we find a row that has at least one '1' and record how many 1s this row has, call this s.

We then continue downwards, counting the number of '1's in any row that has at least one '1'. If any row has some number of '1's that is not s or 0, the shape is a triangle.

If all rows have s '1's or zero '1's, it is a square.

# C: Vlad and a Sum of Sum of Digits
Since the time limit is very short, we probably cannot simulate the entire problem on each test. However, since n is also small, we can simply precompute the answer to each n.

For a particular value of n, the answer f(n) is f(n-1) + sum of n's digits. We can precompute this for all n s.t. 1 <= n <= 2E5, store them in a table and return the answer to each test case in O(1).

# D: Vlad and Division
By definition, two elements are in the same group if and only if their binary representations are opposite. Therefore, there are also at most two elements in each group.

We will call the only number an element can be paired with the element's "complement".

Count the frequency of each element. For each element, we need at least freq(element) groups, since each group can only have 1 instance of this element, and we also need at least freq(complement) groups, since each group can only have 1 instance of the complement. However, each group can have up 1 instance of each the element and the complememnt. So for this element-complement pair, we need max(freq(element), freq(compelement)) groups. 

Each element-complement pair is independent, since complements are unique. The answer is the sum of groups needed for each pair.

# E: Vlad and an Odd Ordering
If we simulate a small example manually, we can see that each round with starts with a power of 2:
- 1, 3, 5, 7, 9...
- 2, 6, 10, 14, 18...
- 4, 12, 20, 28, 36...
- 8, 24, 40, 56, 72...

So, we need to figure out what round the kth card is in, and the index of the kth card within that round (i.e. 20 is the 3rd card in the 3rd round).

If we can figure out how many cards are removed during round i, and how many cards were remaining prior to round i, we can figure out which round the kth card is placed.

In each round, half (rounded up) of the r remaining cards are placed - can be written as (r+1)/2.

Starting in round 1, we see compare k and (n+1)/2. If k <= (n+1)/2, the kth card is in the first round, we'll see how to compute what the kth card is from this point.

If k > (n+1)/2, then we discard the first (n+1)/2 cards. So of the n/2 cards remaining, we are now looking for the (k-(n+1)/2)th card, we can assign k to this new value and n = n/2. 

We know (n+1)/2 cards will be discarded this round. We repeat this process until we find the proper round and index within that round.

We can see that each round is a simple arithmetic sequence, where the constant difference is two times the first number. So, if we find that the kth card is placed in the 5th round and is the 4th card in the 5th round, we know that this card is 112:
- start of the 5th round is 16 (1, 2, 4, 8, 16)
- 1st card in this round is 16, each subsequent card is 32 higher than the previous
- 16 + 32 + 32 + 32 = 112

# F: Vlad an Avoiding X

# G: Vlad and Trouble at MIT
