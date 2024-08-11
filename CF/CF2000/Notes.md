Notes on solutions/approaches to problems

# A: Find K Distinct Points with Fixed Center
Put all the points on a line. 

If odd number of points, put one in the center. Then put n/2 points in the n/2 coordinates above the center, and n/2 points in the n/2 coordintes below the center.

If even number of points, do the same thing but don't put a point in the center.

# B: Minimize Equal Sum Subarrays

Generate q by rotating p by one index. The result of this is that the only segment across which p and q will be equal is the whole permutation (which can never be avoided).

For any segment aside from the whole permutation, p's segment and q's segment will have the same numbers, except for one. However, since it is a permutation, those two numbers will be different and therefore the segments' sums will be different.

# C: Perforom Operations to Maximize Score (TODO)
If we can get a new max, do that.

# D: Determine Winning Islands in Race

# E1: Eliminating Balls with merging (Easy Version) (TODO)
For a given array or subarray, the maximum value can always survive.

Break this array down into subarrays using the max value as a delimiter.

If the sum of this subarray is less than the max just used, none can survive.

Otherwise, the max can survive. Repeat the process.

# E2: Eliminating Balls with merging (Hard Version)