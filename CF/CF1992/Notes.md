Notes on solutions/approaches to problems

# A: Only Pluses
We want to maximize the product. Also, the final sum of a + b + c is fixed. In order to maximize the product in situation, we want a, b, and c to be as equal as possible. So, Noobish_Monk should increment the minimum of a, b, and c.

So, in the first test case, he should put increment 2 twice, and 3 once. Then he will have 4, 4, 4. The remaining increments should be split so he ends with 5, 5, 4.

In the second test case, all increments should go on the 1.

# B: Angry Monk
We need to cut all original pieces into 1s, except for one (which we will use as the base to merge all the pieces together). This should be the largest since it will save us the most cuts.

For each piece with length p aside from the largest one, it will take p-1 operations to fully cut it.

Then to put all the pieces together it will take n-mx operations, if mx is the largest piece at the start of the problem.

# C:

# D:

# E:

# F:

# G: