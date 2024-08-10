Notes on solutions/approaches to problems

# A
Trivial problem - read in both numbers, compare them and output the lesser one followed by the greater one. If they happen to be equal, outputting them in either order will work.

Time: O(1) 
Space: O(1)

# B
This problem can be reduced as follows: if all the characters in the string are the same (all the same letter), the answer is NO. Otherwise, the answer is YES.

Implementation: We can iterate across the string one character at a time, comparing each character to the first character of the string. If all are the same then we answer NO.

If we find a character c that is different from the first character, then moving this character c to the front will make a new string. So we output c, then the entire string in order while skipping c.

Time: O(n), where n is the size of the string since we traverse the string
Space: O(n)

# C
There are several ways to solve this problem, I will cover my approach. For simplicity, start by making a <= b and c <= d (swap a and b if a is greater, swap c and d if d is greater). 

Now, the answer to the problem is found as follows: If one (exactly one, not both) of a or b is numerically between c and d the answer is yes. If both a and b are between c and d, or neither are, the answer is NO.

Time: O(1)
Space: O(1)

# D
Let’s establish a general approach first. We will go from left to right, going as far as we can before making a cut. We then repeat the process with the remaining part of the string.

Now - when do we have to make a cut? We can look at any 2 consecutive bits and know whether a cut is necessary.

Our final string will be all the 0s in the string followed by all the 1s (except the case that the string is all 0s or all 1s, in which case no cuts are necessary). Therefore, we can’t have any pieces that contain “10”. So, any time we see a “10”, we have to make a cut between the 1 and the 0. 

We do not want to cut between two zeroes (00) as this creates another piece unnecessarily. Similarly, we don’t want to cut between two ones (11).

This leaves only one scenario (01). We are allowed to have at most one piece that contains at most one 01. Why? Aside from the trivial case mentioned above, our final string will be all 0s and then all 1s. So at some point in the final string, there will be a 01 but only one and no more. So, the first 01 we see does not need to be cut, but all the other 01s need to be cut.

With this strategy, we can traverse from left to right and count our cuts. We will count the number of 01 cuts and the number of 10 cuts separately. We do this by looking at our current character and the next character. If they are the same, we do nothing and shift over 1 character. If we see an 01, we increment our 01 cut count, if we see a 10, we increment our 10 cut count.

Since we are allowed to have one 01, we subtract 1 from the number of 01 cuts (since we counted all of them), but only if we have one (if we didn’t see any 01s, we shouldn’t decrement).

Now we can add up our total cuts - since the problem asks for the total number of pieces, we simply add 1 to our cut count to get the number of pieces (every cut creates one new piece).

Time: O(n), where n is the length of the string, since we traverse it once
Space: O(n)

# E

An interesting binary search problem, the method I used to solve this required covering several corner cases.

We can immediately start taking in the queries, no setup is required.

We can think of array a as a list of segments. Before we conduct binary search on this query, let’s first check two places. 
If the query is at or before the first sign, no search is required, we can simply interpolate (see below for an explanation) between 0 and the first sign. 
If the query is at the final destination (n), then we simply take the final time (b[k]). 

Otherwise, we need to do binary search on a. There are a few ways to do it but I did this way: the left pointer will try to track the start of the interval containing the queried location, the right pointer will try to track the end of that interval. As always: there are 3 cases in binary search (may help to follow along this part in the video):
If a[mid] == query, then the query is at some signpost. This means that we can answer b[mid] for this query and stop the binary search.
If a[mid] < query, then none of the signs before mid can be the start of the interval containing the query. But mid could be. So we assign left = mid and discard all the previous signs.
If a[mid] > query, then none of the signs after mid can be the end of the interval containing the query. But mid could be. So we assign right = mid and discard all the following signs.

When left and right are next to each other, it means there is only one segment remaining and the query must be located within it. Therefore, the binary search is concluded and we can interpolate to find the desired time.

**Interpolation explanation (good spot to follow along with the video): What do I mean by “interpolate”? The description of the problem states that between any two consecutive signs, the car is moving at a constant speed. We also know the time the car enters and exits the interval. Therefore, if we know where the car is within the interval, we also know what time it is. For example, if the car is in the middle of the interval, the time should be the average of the entry and exit times. If the car is a quarter of the way through, then the time should be one quarter of the interval’s total time plus the entry time. Therefore we take a fraction of how far into the interval the car is: 

(query position - interval start position) / (interval end position - interval start position)

The amount of time it takes to cross the whole interval is:

(interval end time - interval start time)

So to get the time when the car would reach the query position, we multiply the fraction and the total interval time. This is the amount of time it took to get to this spot AFTER entering this interval, so we add the interval start time to get the actual time the car reached this point.

Time: O(q log k), where k is the number of points on the road, and q is the number of queries. This is because for each query, we need to run a binary search on the “road map” (array a) which has k points. Binary search runs in log k time for an array of k points.
Space: O(k), since we need to story the arrays a and b.

# F

We will only count points in one quadrant (I will use Quadrant 1) since symmetry allows us to just multiply the number of valid points in Quadrant 1 by 4 to get our final answer. Since some points may lie on the axes, we need to choose whether a quadrant will include the axis (+x, -x, +y, -y) that lies to its counterclockwise side or clockwise side. In this case, I will use counterclockwise - so Quadrant 1 will include any points that lie on the +y axis. The origin is never a valid point so we don’t have to worry about that.

Since we are only counting lattice points, we can count all the valid points for x=0, then x=1, etc.

So for each x, how do we find/count the valid points? We can think of the two radii as an inner and outer arc. Any point between the two arcs or on the inner arc are “in bounds”. Any other point (including points on the outer arc) are out of bounds. Our approach will be to start at the highest y coordinate that might be valid, then walk our way downward until we cross in the inner arc. We will count the number of valid points we saw along the way and then move one x coordinate to the right.

How do we know what the highest potentially valid y coordinate is for a given x? We know that y=r+1 can never be valid. See Math 1 below for an explanation. However, r might be valid (and often is). So, we will always start there and decrement until we are in bounds. See Optimization below for a way to optimize this (but starting at r will be fast enough). 

So now that we are in bounds, we check if y=r is valid: r^2 <= x^2 + y^2 < (r+1)^2. If it is, we found a valid point so we increment our counter and decrement y and check again. We also stop if y somehow reaches 0 (since the y axis is not included in our definition of Quadrant 1). Once we hit a value of y that is no longer valid for this value of x, we have found all valid points for this value of x. So we increment x and repeat.

Math 1: Call the distance from a point to the origin d. d = x^2 + y^2. If y=r+1, then:

$d = x^2 + (r+1)^2$

Since x^2 is non negative: 

$d >= (r+1)^2$, and therefore this point is invalid.

Math 2:

For x=0, y=r is the ONLY valid point and therefore should always be the starting point. This is fairly easy to see: if x=0, y=r+1, then distance to the origin will be (r+1)^2 which is out of bounds (this point lies directly on the outer arc). If y=r, this point is valid as it lies directly on the inner arc. If y=r-1, this point will be inside the inner arc which is out of bounds. It is easy to see that any other values of y will yield an invalid point.

Optimization:

For some value of x, let’s say that the highest valid point was y=h. For x+1, the highest valid point cannot be higher than h. Why? If the highest valid point for x was h, it meant that:

$r^2 <= x^2 + h^2 <= (r+1)^2$        (h was valid for x), but also:

$(r+1)^2 <= x^2 + (h+1)^2$            (h+1 was invalid for x)

Now let’s show that h+1 is also invalid for x+1.

$(r+1)^2 <= x^2 + (h+1)^2 < (x+1)^2 + (h+1)^2$             

$(x+1)^2 > x^2$ because x is non-negative as we are in Quadrant 1.

How can we use this? Once we find the highest valid point for a given x, we save it in a variable before decrementing. That way, when we move to the next x-coordinate we can start at that height (instead of r, for example). Using Math 2, we know that the highest valid height for x=0 is y=r, so we can start there for x=1 and decrement until we are in bounds (perhaps y=r will also be the highest valid point for x=1). Once we are in bounds, we save that height for x=2. Basically, this will reduce the amount of decrementing we have to do before we reach the valid points. 

Time: O(r), since we are essentially searching the perimeter of the band created by the inner and outer circles.
Space: O(1), we just need to maintain our counter and a few local variables

# G
First, use math to establish a helpful fact. We can swap any two elements that have an XOR of < 4. What does this mean? This means that two elements can only be swapped if the only bits at which they differ are the two least significant bits. This is because the XOR of two numbers is all the bits at which those two numbers differ.

For example, if two numbers differ at bit 8 (which has value 2^8), then the XOR will be at least 2^8, higher if the numbers also differ at other bits. So, it means that for all bits except the 2 least significant, two numbers must be the same (if they can be swapped). This also means that if these two numbers have the same quotient if integer divided by 4. 

Now for our strategy. We will use the above fact to group all the elements in the array based on whether they can be swapped. All elements in the same group can be swapped, and elements in different groups cannot be swapped. Due to this fact, each index in the original (and final) array must contain an element from a certain group based on the element occupying it in the original array.

To construct our groups, we will use integer division by 4. We’ll perform this division on each element in the original array. If a group exists for this element, we’ll add it to the group, otherwise we’ll start a new group for it.

Since we are trying to return the lexicographically smallest array in the end, we want to sort each group amongst itself so when we need to fill an index with an element from a certain group, we can be sure we are using that group’s smallest element.

Now, we need to build the final array using our groups. We traverse the original array, for each index, we can determine the group that it belongs to by integer dividing the value there by 4. Then we can take the group’s least remaining element and put it in that index. Each group will maintain a pointer so we know which elements have been used from that group.

Time: O(n log n). 

Step 1: 
Create O(n) groups (each number could be in its own group)
Insert each group into map, O(log n) per group
O(n log n) time for Step 1

Step 2:
Sort the elements of each group amongst themselves. Worst case scenario, all n elements are in one group. The sort will then take O(n log n) time.
O(n log n) time for Step 2

Step 3:
Assemble final array, we need to make O(n) accesses to the map which each take O(log n) time.
O(n log n) time for Step 3

Total time: O(n log n)

Space: O(n), aside from the original array (which is also O(n)), the space taken by the groups is equal to the total number of elements in all groups + the number of groups. The number of groups can be at most O(n) so the groups take O(n) space.

# H

## Steps
- Reformulate the grid as a 2-SAT problem
- Construct implication graph
- Run Kosaraju’s algorithm to find strongly connected components
- Examine strongly connected components

## Formulate as 2-SAT

Essentially, for Alice to win, she needs at least two of the three entries in each column to be 1. This can be formulated as a 2-SAT problem. Basically, at least 2 of the 3 entries in each column need to evaluate to “true” and we need to find out if this is possible.

In order for a column to have 2 out of 3, it means that any pair of entries taken from the 3 has to have at least one true. Otherwise, it means at least 2 of the 3 are false.

So, if we have variables a, b, and c. We need one of a, b to be true, one of b, c to be true, and one of a, c to be true. We can use these 3 conditions to write 6 implication (if, then) statements. If a is false, c must be true (or that pair would have two false values). This would be written as “if not a, then c”. If c is false, a must be true (by the same token), “if not c, then a”. We can write these two statements for each pair (for a total of six). We will do this for each column (6*columns statements). 

## Implication graph

We can use this to create an implication graph. Each vertex represents a certain variable. We will have 2*cols variables, since we need “x” and “not x” for each variable x. There exists a directed edge from vertex u to vertex v is u implies v. So using the example above, we had a statement “if not a, then c”. So we will have a directed edge from the “not a” vertex to the “c” node. 

How does this graph translate to a solution? If there is a path between a variable (e.g. “x”) and its negation (“not x”), and there exists a path from “not x” to “x”, then there is a contradiction. This also means they are in the same “strongly connected component”, since there exists a path from each of them to the other. So how can we find strongly connected components?
Kosaraju’s Algorithm

Run DFS on the graph, and add a node to the stack when its DFS concludes. Then, we need to transpose the graph (invert the direction of all edges). In my implementation, I just build two graphs, the original one and the transposed one.

Now, we need to run DFS on the nodes in the stack, popping off one at a time and assigning it to an SCC. If the node we pop off is unassigned, we assign it to a new SCC. If it is assigned, we just do nothing and pop off the next node. Now each node (variable) is assigned an SCC.
Check SCCs	

At this point, all that remains is to check if any variable and its complement are in the same SCC. If we find a pair that is in the same SCC, we have a contradiction and there is no way Alice can win (answer is “NO”). If we check all the variable pairs and there are no contradictions, Alice can generate an array to win (answer is “YES”).

Time: 

Building implication graph(s): 
O(n) clauses to process, so O(n) edges to add to the graph.
O(n) time

## Kosaraju’s Algorithm:
DFS runs in O(V+E), where V is the number of vertices, and E is the number of edges. Both V and E are O(n). We run 2 DFS.
O(n) time

## Checking SCC’s:
We can look up each node’s SCC in constant time, O(n) variables/nodes
O(n) time

O(n) time total

Space: 
We have various vectors/tables for the graph, SCC assignments, stack, etc. all are O(n) space. Total O(n) space

