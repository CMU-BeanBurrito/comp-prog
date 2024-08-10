Notes on solutions/approaches to problems

# A: A+B Again?
Divide by 10 to get the tenths place, divide by modulo 10 to get ones place, add them.

# B: Card GAme
There are 3 distinct cases (which will be broken up further) in which we win, for each, we need to consider the two possible card matchups:
Each of these win conditions yields two wins, since it doesn't matter which round happens first
- Win both rounds
  - `a1 > b1 && a2 > b2`
  - `a2 > b1 && a1 > b2`
- Tie the first round, win the second round
  - `a1 == b1 && a2 > b2`
  - `a2 == b1 && a1 > b2`
- Win the first round, tie the second round
  - `a1 > b1 && a2 == b2`
  - `a2 > b1 && a1 == b2`

If none of these are true, it means we lose every game. Also, it's not possible for more than 2 of these cases to be true, otherwise it would be possible for us to win more than 4 games.

# C: Showering
In order for us to shower, there needs to be a gap of s minutes in one of the following places:
- Between the start of the day and the start of the first task
- Between the end of a task and the start of the next task
- Betweeh the end of the final task and the end of the day

Simply iterate over the tasks, checking if there is a gap between the start of this task and end of the current task (or start of the day for the first task).
Check if there is a gap between the end of the final task and the end of the day.

If we found a gap, answer is yes, otherwise, no.

# D: Slavic's Exam
Solve this problem greedily, and with two pointers. The first pointer will iterate across t, the second pointer will iterate across s.

For each character in t, we need to find the same character in s, or a question mark. Also the characters we choose in s need to be in the same order as the characters in t.

Initially, both pointers are at the start of their respective strings. Neither pointer will ever move backwards.

For each character in t, `t[i]`:
 - If our s pointer `s[sptr]` is on a question mark or `t[i]`, then `t[i]` is resolved. If the `s[sptr]` is on a question mark, replace it with the t character. Then move to the next character in t.
 - If not, then keep moving `sptr` until we resolve `t[i]`. If we get to the end of the s and t is not fully resolved, answer is no.

We might have some leftover queswtion marks, fill these in with any letters.

Answer yes and output the string we've generated.

# E: Triple Operations
## Overall Strategy

Our first step is to create a 0, so we can choose it as x in the future. If we never create a 0, we will need an infinite number of operations.

Before we have a 0, each operation also makes another number y larger (1 additional operation required in the future to get y to 0). So, we want to choose the smallest number l to set to 0. Keep choosing this number as x until it gets to 0. Count each operation as double since it increases another number.

Second step is just to get the rest of the nubmers to 0. For each number y, it will take $floor(log(y))$ operations. Do this and output the number of operations.

## Implementation Details

1 second time limit means we can't just simulate all the operations even though it is O(n log n). We can optimize the second step from nlogn to n. To do this, we must compute $floor(log(y))$ in constant time. This number only changes when we reach a power of 3 (3, 9, 27, 81, etc.). Then, it remains the same until we reach the next power of 3. So, we can just precompute the powers of 3 until the maximum value of n, and then keep track of which one we are on, incrementing to the next power of 3 when we reach on one the blackboard. 

# F: Expected Median

## Overall Strategy
Since we are picking subsequences, and not subarrays, we will end up choosing every combination of k elements. So, which ones count towards our answer? If we pick k, at least (k+1)/2 of them have to be 1. 

Step 1: get a count of 0s and 1s in the input.

Step 2: See how many different subsequences there are if we include no zeroes, 1 zero, 2 zeroes, etc. up until (k+1)/2, since we don't want to count subsequences which have (k+1)/2 or more zeroes. We can also stop early if we hit the total number of zeroes in the array.

How to do this? Let's say we have 4 zeroes and 6 ones in the array, and k is 5. 

First, we want to try having no 0s. So, we need to pick 5 ones from the 6 that we have, which is 6 choose 5 = 2. So add 2 to our answer.
Next, we want to try adding 1 zero. So, we need to pick 1 zero from 4, and 4 ones from 6. That is 4 choose 1 times 6 choose 4. That is 60, add that to our answer.
We repeat this for 2 zeroes, but not for 3 since k is 5 and that would make our subsequences majority 0. 

The problem arises with the math that supports this. The n choose k formula contains multiple factorials, and computing 200000! is not feasible. There is also the issue of dividing by k! or (n-k)! to deal with. The section below (Math) will go over the general strategy as far as this problem is concerned. More details will be in the REFERENCE.md file in the top level of this repo.

## Math
We need to precompute the factorials of 1 to MAXN, which is easy enough. The trickier part is finding the inverses of these factorials, since n choose k requires us to divide by k! and (n-k)!. So, we need to precompute factorials of 1 to MAXN and the inverses of these factorials.

Computing the factorials is easy enough. Computing the inverses is a little more challenging. We will use the extended Euclidean algorithm to find the inverses. Then, when we calculate n choose k, we will multiply n! by the modular inverse of k! and the modular inverse of (n-k)!. See REFERENCE.md for notes on the extended Euclidean algorithm.

# G1: Ruler (easy version)
*The solution for the hard version will also work for the easy version of the problem, but for the easy problem I will discuss a simpler solution that will only work for the easy version. The hard solution will build on it.

Essentially, this problem is a glorified binary search problem. Any $y < x$ will give us the correct measurement, any $y >= x$ will give us an incorrect measurement that is 1 unit too large.

Our initial search space is $2 <= x <= 999$.

In this version, we can just use a rectangle that has height 1 and length y (mid). We query with 1, y and see if the result is y or y+1. If it is y, then $y < x$, so left should move to mid+1. If the result is y+1, then $y >= x$ so right should move to mid. 

Eventually, we will get down to 1 value (left == right). This is the answer. We know we can do this in 10 queries because for each query, we eliminate at least half of the search space. $2^10 = 1024 > 998$, which is the size of our original search space.

# G2: Ruler (hard version)
Our analysis in the easy version of this problem will tell us that we cannot use the exact same code since $2^7 = 128 < 998$. So, we need to make use of the height as well. 

When we query, instead of querying with 1, y, where y is the midpoint between left and right, we will divide the space between left and right into 3 sections. So we will have a mid1 which is 1/3rd of the way from left to right, and a mid2 which is 2/3rds of the way from left to right. We can then query with mid1, mid2.

If the result is mid1*mid2, then we know x is greater than both mid1 and mid2. So, left becomes mid2+1. 
If the result is mid1*(mid2+1), then we know x is greater than mid1, and less than or equal to mid2. So, left becomes mid1+1, right becomes mid2.
If the result is (mid1+1)*(mid2+1), then we know x is less than or equal to mid1 and less than or equal to mid2 (mid1 might be equal to mid2). So, right becomes mid1. 

By doing this, we are essentially removing 2/3 of the search space each query ("ternary search"), instead of 1/2. As in the easy version, we will eventually converge on one number which will be our answer. 

$3^7 = 2187 > 998$, so 7 queries will be sufficient for us to narrow the search space down to 1 number.

