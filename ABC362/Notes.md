Notes on solutions/approaches to problems

# A:
For each color/value of C, just pick the minimum of the other two colors which we can buy.

# B:
Take the slopes of the 3 legs, if any two of them are perpendicular (product is -1), then they form a right angle and the triangle is a right triangle.
If a leg is parallel to the y-axis, its slope is undefined, look for a leg with slope 0 (parallel to x-axis).
Use proportions to see if the slopes are perpendicular.

# C:
The minimum possible sum of our choices is the sum of all the lefts. If that sum is greater than 0, there is no solution. Similar, if the sum of the rights (the maximum total we can pick) is negative, there is no solution. Otherwise, there is a solution.

Start by choosing all the minimum values. Iterate over them, incrementing them by however much is needed to get the sum to 0. If increasing a value to its maximum is not enough, raise it to the maximum and move to the next value.

# D:
Replace bidirectional edges with 2 unidirectional edges, each with the weight of the bidirectional edge. However, to each edge, add the weight of the destination vector. Now we can simply run Dijkstra's algorithm.

# E:

# F:

# G: