Notes on solutions/approaches to problems

# A: Dora's Set
In one operation, we need to remove at least 2 odd numbers, or the even numbers in our operation will have gcd 2.

We leverage the fact that consecutive numbers have gcd 1. So remove x, x+1, x+2, where x is odd.

Still need to prove that x, x+2 are coprime. gcd(x, x+2) must also divide x+2-x, 2. So, the gcd is 1 or 2.
Clearly, it is not 2. So it must be 1.

So, removing x, x+1, x+2 is valid if x is odd. Then, we have the strategy:
- Start at l
- if l is even, move to l+1 and remove l+1, l+2, l+3. skip l+4. remove l+5, l+6, l+7, skip l+8...
- if l is odd, remove l, l+1, l+2, skip l+3. remove l+4, l+5, l+6, skip l+7...

Be sure to handle different cases (l odd, l even, r-l+1 mod 4, etc.)

# B: Index and Maximum Value
The element that is originally the maximum can never be exceeded.
In order for another element to exceed the original maximum value, it must first reach the original maximum value and then be incremented. If this happens, the element that is originally the maximum will also increment. So, we simply track the maximum and increment/decrement it on operations that it is affected by (whenever this value is in [l, r]).

# C: Dora and C++
We can change the difference between two elements x, y by gcd(a, b) according to Bezout's Theorem.

However, when it comes to a mod gcd(a, b) - b mod gcd(a, b), you can only toggle this value to gcd(a, b) minus this value or vice versa. So if a mod gcd(a, b) is 1, b mod gcd(a, b) is 6, and gcd(a, b) is 8, you can only make a mod gcd(a, b) - b mod gcd(a, b) 5 or 3. 

Essentially, if we take all elements mod gcd(a, b), they form some sort of circle. To get the minimum range, we want to create the largest possible gap between two elements. The range is gcd(a, b) minus this gap size. 

# D: Iris and Game on the Tree
*color c will refer to green or white, !c will refer to the opposite color
*GL = # of leaves that are initially green
*WL = # of leaves that are initially white
*QL = # of leaves that are initially uncolored
*QI = # of internal nodes that are initially uncolored

First we observe that the path between the root and the leaf is irrelevant. If the root and leaf are the same color, no points are scored, if they are different colors, 1 point is scored.

There are 2 major cases, initially:

Case 1: The root is already colored (with color c).
In this case, it's pretty clear Iris should just color as many leaves as possible with color !c.
The answer is the nubmer of leaves already colored with !c (`GL or WL depending on root color`), plus the number of leaves Iris can color with !c (`(QL+1)/2`, since Iris goes first).

Case 2: The root is initially uncolored. This case breaks down into 3 sub-cases:
- Case 2a: GL and WL are different.
- Case 2b: GL == WL, and QI is even.
- Case 2c: GL == WL, and QI is odd.

2a: Rather simple. Iris should color the root right away (green if WL > GL, white if GL > WL). By doing so, she guarantees `max(WL, GL) + QL/2`, since Dora will start coloring the leaves first. Why is this the best strategy?
- If Iris starts with a leaf node, Dora can color the root (green if GL > WL, white if WL > GL). This means the score will be `min(WL, GL) + (QL+1)/2`, or worse, if GL > WL and Iris colored the first leaf with green (or white if WL > GL). At best, this is equal to our proposed strategy: `max(WL, GL) - min(WL, GL) >= 1`, and `0 >= QL/2 - (QL+1)/2 >= -1`.
- If Iris starts with an internal node, Dora can color the root as above and the result will be the same as the best case if Iris started with a leaf node.

2b: Also rather simple, note that GL == WL. Iris should simply color the root with either color c, then start coloring leaves with !c. Dora will be the first to start coloring leaves, so Iris only gets `QL/2` from coloring leaves, plus `GL` from the leaves that are already !c. Why is this the best strategy?
- If Iris colors a leaf node with c, then Dora will color the root with c. Iris will then color as many of the remaining `(QL-1)` as she can with color !c. However, since she goes first, this is rounded up to `QL/2`, the same as our proposed strategy.
- If Iris colors an internal node, Dora will color an internal node. Then, Iris is left with the same choice as before this turn. If she continues coloring internal nodes, Dora will do the same and eventually there will be no internal nodes left and it will be Iris's turn. In other words, even number of internal nodes is the same state as 0 internal nodes.

2c: Iris should actually color an internal node first. Suppose Dora tries to also color the internal nodes as in 2b. Then, Iris will color the last internal node and Dora will be in the same position as after Iris colors the first internal node. So, 1 internal node is the same as any odd number of internal nodes. Once Iris colors the last internal node, Dora is forced to color the root or a leaf. If Dora colors a root with c, Iris starts coloring leaves with !c and can color `(QL+1)/2` of them. If Dora colors a leaf with c, Iris colors the root with c! and the starts coloring leaves with c. After coloring the root Iris will `(QL-1)/2` with c, but Dora already colored a leaf with c so there will be `(QL+1)/2` leaves with c. Why is this the best strategy?
- If Iris had colored in a leaf with c at the start, Dora would have colored the root c and the positions would have been reversed, with Iris only coloring `QL/2 (QL-1 leaves left, but Iris goes first after the root is colored, so round up)`.
- If Iris had colored the root with c, Dora could hav ejust colored a leaf with c and would be first in the order, so again, Iris would only be able to color `QL/2` leaves with !c.

Summary:
Root colored with c:                    `ans = # num leaves with !c + (QI+1)/2`
Root not colored, GL==WL:               `ans = GL + QL/2`
Root not colored, GL!=WL, QI even:      `ans = max(GL, WL) + QL/2`
Root not colored, GL!=WL, QI odd:       `ans = max(GL, WL) + (QL+1)/2`

# E: Iris and the Tree

# F: Eri and Expanded Sets
