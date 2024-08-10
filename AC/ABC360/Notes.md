Notes on solutions/approaches to problems

# A: A Healthy Breakfast
Simply check if the R is to the left of the M.

This is the case if:
- the R is the first character, or
- the R is the second character and the M is the third character

# B: Vertical Reading
String is small enough to brute force.

Try valid values for w. If n/w (rounded up or down) is equal to m, this w might be valid. Don't forget that w must also be strictly less than s.

For a value of w, try all c in [0, w). Check if indices (in s) c, w+c, 2w+c, etc. match t[0], t[1], t[2], etc.

If they do, answer yes, if not, try other w and c. If all are exhausted, answer no.

# C: Move It
Pretty simple. For each box that has items initially, leave the heaviest one in the box, and remove all the other ones (to put in other boxes).

So, iterate over each box, add the sum of its objects minus the heaviest object in the box to our answer, return this overall sum as the answer.

# D: Ghost Ants
First, sort the ants by starting position (this includes rearranging the string).

Then, generate a prefix sum where p[i] is the number of "positive ants" at indices [1, i].

Since we only care about crossings/relative positions, move all ants going in the negative direction by 2T. Now we can just count how many positive ants each "negative ant" passed (since positive ants can't pass each other, negative ants can't pass each other).

By using the prefix sum, we know how many positive ants are to the left of each ant initially. We can use its final position to binary search on the positive ants only to see how many would be to the left after the ants walk. So, generate a sorted vector of the positive ants' initial locations.

Now, for each negative ant, use binary search to find how many positive ants it passed. Sum this up for each negative ant and return the sum as the answer.

# E: Random Swaps of Balls (TODO)
The probability of staying in the same place during an operation is:

$$1-\frac{2N-2}{N^2}$$

The probability of moving to a given position is:

$$\frac{2}{N^2}$$


# F: InterSections

# G: Suitable Edit for LIS