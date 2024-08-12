Notes on solutions/approaches to problems

# A: Distanced Coloring
We can repeat a pattern after k rows or columns. So the answer is min(n, k) * min(m, k)

# B: Removals Game
Alice needs a first move that Bob cannot copy. Then she can save the number Bob removed.

If the arrays are the same, or reverse of each other, Bob wins because he can just copy every move Alice does.

If they are not the same or reverse of each other:
- Either Alice's first or last number is not the first or last number for Bob (he can't remove it on the first move)
- She removes this number, and Bob is forced to remove a different number.
- Alice can preserve the number that Bob removed first

# C: Black Circles
Clearly, if a circle has a shorter distance to the target than we initially do, it is not possible to make it.

Can a circle that is further away from the target than us stop us? What about multiple circles? No. The contest editorial has a mathematical proof for it. 

My intuition is that if the circle would intercept us somewhere before the target, it must have been closer to this spot than us initally. Since the target is further away from us than this spot, the circle must also have started closer to the target.

So, we simply iterate over all circles and check if any of them are closer to the target than us.

## Calculating Distance
Of course, the distance between 2 points is $\sqrt{dx^2 + dy^2}.

However, since we only care about comparing distances to each other, there is no need to take the square root, we can just compare squared distances together.

# D:

# E:

# F:

# G: