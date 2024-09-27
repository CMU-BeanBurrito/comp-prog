Notes on solutions/approaches to problems

# A
All `?` are definitely wrong answers.

For other answers, if there have not been n answers of that type prior to this question, it might be correct.

Keep a count of each answer type seen so far. If we seen an answer that has been chosen n times already, this answer cannot be correct. Otherwise, it could be.

# B
If the whole list has the same parity, no moves are required.

Otherwise, we must convert all evens to odds, since we cannot convert odds to evens (sum of an odd and even is odd).

In order to convert an even to an odd in one operation, the odd must be larger. Otherwise, it will take two operations.

We should convert all the evens that are smaller than the largest available odd we have (which will keep increasing as we convert evens), which costs one operation each.

If we ever encounter an even larger than our largest odd, we should immediately spend two operations to convert the largest remaining even since it will allows us to convert all other remaining evens in one operation each. 

So if there are e evens in the original array, the answer should be 0, e, or e+1.

# C

# D

# E

# F

# G