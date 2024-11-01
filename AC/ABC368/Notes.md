Notes on solutions/approaches to problems

# A: Cut
First, we cut the deck into 2 parts. Initially, the top part is: `a[0], a[1], a[2]...a[n-k-1]`, since it is the first `n-k` cards. The bottom part is `a[n-k], a[n-k+1], a[n-k+2]....a[n-1]`, since it is the remaining `k` cards. Then, we take the bottom part and move it to the top.

So, we print out `a[n-k], a[n-k+1]....a[n-1]`. Then we print out `a[0], a[1]....a[n-k-1]`.

# B: Decrease 2 max elements
Input size is small, can do a pure simulation:
- sort entire array
- if second element (1-indexing) is positive, there is are at least 2 positive elements, so we are not done
 - decrement first and second element
 - increment operation count
- otherwise, there is at most 1 positive element remaining, we are done

# C: Triple Attack
Input is too large to do a pure simulation.

Suppose that we are attacking a monster with health `h[i]` and before our first attack on this monster, `T % 3 = 0`.

If `h[i] = 1`, clearly we only need 1 turn to kill it.
If `h[i] = 2`, clearly we need 2 turns to kill it.
If `h[i] = 3, 4, or 5`, we need 3 turns to kill it.

So, we can do 5 damage in 3 turns. So if `h[i] >= 5`, then we can just use `3*(h[i]/5)` turns and then our monster will have less than 5 health, and we can easily use the above cases to finish it off. 

However, this is all assuming that `T % 3 = 0` when this battle starts, which it might not be, it could be 1 or 2. We can simulate the first turn (if `T % 3 = 2`), or the first two turns (if `T % 3 = 1`). Then `T % 3 = 0` and we can use the approach described above.

If `T % 3 = 1`, there are two cases: the monster dies on the first turn, or it doesn't. If it does, it means `h[i] = 1`. In this case, we know the fight will take one turn. If it does not, then we simulate the next 2 turns (4 damage, since the second turn will have the empowered 3-damage attack). If the monster is dead, we are done. Otherwise, `T % 3 = 0` and we can handle the remaining health on the monster using the above approach.

If `T % 3 = 2`, then our next attack is empowered. Simulate this attack. If the monster dies, we are done. Otherwise, `T % 3 = 0` and we can handle the remaining health on the monster using the above approach.

Essentially, we see that the problem is a lot simpler if `T % 3 = 0` at the start of the fight, so we simulate a couple turns to get to this state.

# D: Minimum Steiner Tree
Trivially, we need all nodes in `V`. Call these essential nodes. However, for all pairs of essential nodes `i, j` in `V`, we need all the nodes on the path between `i, j`.

To accomplish this, we can do a simple DFS. How do we know if a node should be added to the answer set? 

If there is an essential node in any of this node's subtrees, it should be added to the answer set. Therefore, if a node has a child that is an essential node, it will add itself to the answer and return `true` to its parent. 

Then the parent also knows it should add itself to the answer (since it has a descendant that is essential). The parent will continue to pass `true` up the stack to all nodes whose subtree the essential node was found. If a node's subtree contains no essential nodes, it will pass `false` to its parent. That way the parent knows it should only add itself to the answer is there is an essential node found it in its other subtrees.

# E: Train Delay

# F: Dividing Game

# G: Add and Multiply Queries
