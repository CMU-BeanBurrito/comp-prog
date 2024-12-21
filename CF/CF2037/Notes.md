Notes on solutions/approaches to problems

# A: Twice
Create a simple key/frequency map.

Each key adds floor(frequency/2) operations.

# B: Intercepted Inputs

Clearly, `n*m == k-2`.

Create key/frequency map. Iterate over keys, if a key divides `n*m`, see if the other factor also exists in the map. If it does, then this pair of factors is a valid answer. There is guaranteed to be at least one such answer.

# C: Superultra's Favorite Permutation

We can put all odds together, and all events together. Clearly, the sum of two odds is composite, and the sum of two evens is composite. However, there is one point in the permutation where the sum of one odd and one even must be composite.

Manually, we can see that any pair of odd and even such that neither number exceeds 4 will not yield a composite sum. So, if `n <= 4`, there is no solution. Otherwise, we can use 4, 5 in the middle of the permutation. So, we put all evens except 4 first, then 4, then 5, then the rest of the odds.

# D: Sharky Surfing

To pass hurdle `i` with as few powerups as possible, we want to take greedily take the largest powerups until our jump power is enough to jump the longest hurdle out of the first `i` hurdles. To do so, we just keep track of all of the powerups that were available before the current hurdle (that we didn't take yet). If we can already jump it, then we jump it and move on. If we cannot jump it yet, we greedily take the largest remaining powerups (deleting them from the "available" container)until we have enough jump power.

When we move on, we don't need to go back and change our powerups from previous hurdles, since those moves were both necessary and optimal.

# E: Kachina's Favorite Binary String

# F: Ardent Flames

Refer to official editorial.

Implementation note: if a monster cannot be killed in the number of turns we are testing for (`mid`), do not add an event interval for it. This will represent that there is no position which allows this monster to be killed in `mid` turns.

# G: Natlan Exploring