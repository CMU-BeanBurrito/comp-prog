Notes on solutions/approaches to problems

# A: Medium Number
Put the numbers in a 3-vector, sort them, and return the second element. Can also be done by comparing the elements to find the median.

# B: Atilla's Favorite Problem
We only care about finding the maximal character in the string. The number of letters less than or equal to the maximal letter is the answer: `a = 1, b = 2, c = 3, etc.` 

# C: Advantage
The strongest participant is compared to the second strongest participant. Everyone else is compared to the strongest participant. We can find the two strongest participants' strengths by sorting (another copy of the input array) or by keeping two variables. 

# D: Challenging Valleys
We can boil down the conditions to this: As we travel from left to right, once we go upwards a single time, we never go downwards after this.

So, iterate over the array. Once we find any `a[i] > a[i-1]`, any later `i, a[i] < a[i-1]` means this is not a valley. If we do not go down after we go up, then it is a valley.

# E: Binary Inversions
We have 3 options:
- do nothing
- change a 1 to a 0
- change a 0 to a 1

Observe that if we change a 1 to a 0, we should always change the rightmost 1, since this maximizes the number of 1s that come before it. Similarly, if we change a 0 to a 1, we should always change the leftmost 0, since this maximizes the number of 0s that come after it.

We can simply exercise all 3 options, count the number of inversions after each option, and pick the maximum.

To quickly count inversions, we can iterate left to right, keeping track of the number of 1s `ones` we have seen. If we see a 0, then we increment our inversion count by `ones`, since there are `ones` 1s in front of this 0.

# F: Quests
Let's handle the `Infinity` and `Impossible` cases first.

If we can get enough coins in `d` days without ever repeating a quest, the number of days `k` before repeating a quest doesn't matter, and the answer is `Infinity`. To check this, we see if the sum of the `min(n, d)` most rewarding quests amount to at least `c`.

If we do the most rewarding quest every day for `d` days and cannot get enough coins, the answer is `Impossible`. This is because we are essentially setting `k = 0` and are still unable to get enough conis.

If we are in neither of the above 2 cases, then we binary search on `k`, which we know is less than `d`, otherwise, we would've returned `Infinity` (since we cannot repeat any quests if `k = d`).

To check whether a particular value of `k` works, we break up `d` into blocks of `k+1`. In each block, we can do the `min(n, k+1)` most rewarding quests. After the last complete block, there might be some number of leftover days `lo`. In `lo` days we can do the `min(n, lo)` most rewarding quests. Then we simply check whether we've earned at least `c` coins.

# G: SlavicG's Favorite Problem
Since we cannot visit `b` unless our path's XOR is 0, we must find a path from `a` to `c` whose XOR is the same as `b` to `d`.

`b` must not lie on the path between `a` and `c` since we cannot visit it on the way to `c`. If the path from `a` to `b` has XOR 0, then any node on the path will be a valid `c`. 

`d` however, can be anywhere in the tree, except `b`. This is because we can teleport from `c` "past" `b` to `d`, and then if `d-b` has the same XOR as `a-c`, then we have a solution.

So, DFS/BFS from `a`, except for `b` and any of `b`'s subtrees, collecting all paths' XORs. Then, DFS/BFS from `b`, collecting all paths' XORs.

Then check if any path XORs from `a` match any path XORs from `b`. If there is one, it means we can walk to this XOR from `a`, teleport to the same XOR from `b`, then walk to `b` and have total XOR 0.

If there is no path XOR that exists both from `a` and `b`, answer is `-1`.
