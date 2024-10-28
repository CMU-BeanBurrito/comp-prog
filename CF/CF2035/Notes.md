Notes on solutions/approaches to problems

# A: Sliding
Clearly, everyone ahead of the person leaving does not move. We can easily find this number of people: `r*m + c-1`.

Everyone behind the person who left moves 1 spot, except there is one person per row (at the start of the row) who has to move m spots to get to the end of the next row.

This affects all rows after the row containing the person who left, and there is one person in each row in this situation. There are therefore `n-r` people who have to move `m` spots.

So, 
- `r*m + c-1` people move 0 spots
- `n-r` people move m spots
- the rest move 1 spot

# B: Everyone Loves Tres
For small values of n, we are provided the answer in the examples and can use this to build answers for larger values of n.

The answer to n+2 is "33" concatenated with the answer to n. This is because we are adding 330000.... to the number instead of multiplying it by 100, which would increase the value by more than 330000....

# C: Alya and Permutation
3 cases:
- n is odd
- n is even, but not a power of 2
- n is a power of 2

Case 1: n is odd. 

k cannot exceed n, since the final index is odd. So k cannot exceed the final element (which is at most n). So we should put n at index n.

In this case, we need to have all bits in n by the time we reach index n. We can do this by putting n-1 at index n-1.
Now we just need to have 1 by the time we reach index n-1. To do this we can just use 1 at index n-3 (adding it to our bitset), and then use 3 at index n-2 to keep the 1. We could have also done 3, 1.

The first n-4 indices can be filled in with the remaining elements in any order.

Case 2: n is even, but not a power of 2. Clearly, k cannot exceed x = 1 | 2 | 3 ..... | n. We will see that k = x.

Call the highest bit in x bit m. On its own, it has value 2^m. All the bits less significant than m would total value m-1. We can put m-1 at index n, then we just need to acquire bit m.

To do this, we can put n at index n-1 and 2^m at index n-2. We know n has bit m, but we also know n is not just 2^m since n is not a power of 2. So we had bit m to our bitset at index n-2, preserve it with n at index n-1, and add the rest of the bits with m-1 at index n

Case 3: n is a power of 2.

Similar to case 2, k = x = 1 | 2 | 3 ..... | n.

However, this time we will put n at index n. So, we need to get the rest of the bits aside from bit m. Let's do this in two steps:
- get bit 0 using 1 then 3 at indices n-4, n-3
- get the rest of the bits (all except 0, m) using n-2, n-1  

# D: Yet Another Real Number Problem
We can think of breaking down every element into its prime factorization. Any instances of 2 in its prime factorization can be moved to any index greater than it. Clearly, we want to put each '2' on the highest element it can be on (i.e. the maximum element in the suffix beginning at its original index).

So, we iterate across the array. We revisit any indices to the left and see if the current index's element is than any previous index's base number (highest number after removing all 2s from prime factorization). Any 2s that are at an index whose element's base number is lower than the current index's element should be moved to the current index.

Note that we compare the current element with its 2s vs. other elements without their 2s, since the current elements' 2s cannot be moved.

Use a set to track where all the 2s are while also being able to remove entries that no longer have any 2s.

# E: Monster

# F: Tree Operations

# G1: Go Learn! (Easy Version)

# G2: Go Learn! (Hard Version)

# H: Peak Productivity Forces