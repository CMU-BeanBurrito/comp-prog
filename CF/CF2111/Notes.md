Notes on solutions/approaches to problems

# A: Energy Crystals

Suppose `x` is very large. How do we proceed? Start by simulating the process by hand:
- 0, 0, 0
- 1, 0, 0
- 1, 1, 0
- 1, 1, 3
- 3, 1, 3
- 3, 5, 3
- 3, 5, 5
- 9, 5, 5
- etc.

Clearly, we need at least 3 operations to get all 3 crystals to at least 1. To get all crystals above 2, we need 5 operations. To get all crystals above 4, we need 7 operations. The reason why we only need 2 operations for each power of 2 after the first one is that when the third crystal doubles* itself to match the others, it can double* itself again since the other 2 are already equal to it. So, we can do both doubles* in one operation.

So, the answer is `3 + floor(log(x))`, using log base 2. To implement this easily, we can just start with our answer as 3, and repeatedly divide `x` by 2 (rounding down) until `x == 1`. On each division, increment answer by 2.

# B: Fibonacci Cubes

The drawing in the explanation of the test case gives a lot away. Clearly, all dimensions must at least be `f(n)` and at least 1 dimension needs to be at least `f(n)` + `f(n-1)` (this is equal to `f(n+1)`).

It turns out this is also sufficient. Why? Let's establish an important fact. If we have a box (or remaining part of a box) with space `w, l, h`, and we inserted a cube with side length `x`, the remaining space is at least `w-x, l-x, h-x`. 

Suppose we have a box of dimensions `f(n+1) * f(n) * f(n)`, width, length, height, respectively. We first put in the largest cube of side length `f(n)`. It occupies `f(n) * f(n) * f(n)` volume.

So we have at least `f(n-1) * f(n) * f(n)` volume left. We insert the second largest cube, which occupies `f(n-1) * f(n-1) * f(n-1)` volume.

We now have at least `f(n-3) * f(n-2) * f(n-2)` space left. So, we can fit the third largest cube in.

We can see that when we insert the kth cube, we will have at least `f(k) * f(k+1) * f(k+1)` space, so we will always be able to isnert it.

So, having `f(n+1) * f(n) * f(n)` is sufficient. Due to `n` being small, we can always calculate `f(k)` naively.

# C: Equal Values

Call the first operation "left", and the second operation "right". Clearly, we will never do more than 1 left operation, and we will never do more than one right operation. If we do more than one left operation, one of them will completely cover the other one, so the other one was pointless. The argument is the same for multiple right operations.

There are two cases:
- We choose one index `i`, and we perform 1 left operation on it and 1 right operation on it.
- We choose two index `i`, `j`, `i < j`, both indices containing the same value (`a[i] == a[j]`). We do a left operation on index `i`, and a right operation on index `j`.
  - Note that if `i = 1`, or `j = n`, we are fine, since that operation will cost 0 and have no effect on the array.

It is easy to see that in case 2, if there are elements in between `i` and `j` that do not equal `a[i]`, this will not work as we did not make the elements in the middle equal. So, we can only choose case 2 if all indices in between `i` and `j` (inclusive) are equal. If we can, then the cost would be `(n-(j-i+1)) * a[i]`.

Therefore, for a particular element value `e`, the lowest cost we can achieve if we are to make all elements in the array equal to `e` is as follows:
- call `x` the length of the longest contiguous segment in the array such that all elements in the segment are equal to `e`.
- we choose `i` to be the first index of this segment, and `j` to be the last index of this segment
- perform a left operation on index `i` and a right operation on index `j`.
- the left operation costs `e * (i-1)`, the right operation costs `e * (n-j)`, so our total cost is `e * (n-j+i+1)`
- this is equivalent to `e * (n - (j-i+1))`.
- `(n - (j-i+1))` is the number of elements that were not part of the segment we chose, and is equivalent to `n-x`.

So, begin by iterating over `a` and computing `x` for each value in the array (can store them in a map).

Then, iterate over the entries of the map, computing `e * (n-x)` for each entry. `e` will be the key, `x` will be the value.

The answer is simply the minimum `e * (n-x)`.

# D: Creating a Schedule

I was unable to prove it, but a greedy solution will work for this problem.

Our greedy approach is as follows:
- Take 2 groups, the classroom `mn` with the minimum rooom number that is not booked yet, and the classroom `mx` with the maximum room number that is not booked yet. So, moving between `mn` and `mx` is the greatest possible distance among the remaining available classrooms
- Have the first of these 2 groups schedule be: `mn, mx, mn, mx, mn, mx`.
- Have the second of these 2 groups schedule be: `mx, mn, mx, mn, mx, mn`.
- Update `mn` and `mx` for the next pair of groups, as `mn` and `mx` are now booked for the whole day.
- Repeat until all groups have a schedule

# E: Changing the String

# F: Puzzle

# G: Divisible Subarrays
