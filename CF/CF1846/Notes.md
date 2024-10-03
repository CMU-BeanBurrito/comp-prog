Notes on solutions/approaches to problems

# A: Rudolph and Cut the Rope

The ith nail/rope allow the candy to fall down to some height h = a_i-b_i.

Before we do anything, the candy rests at h_max.

In order to get the candy to the ground (h = 0), we need h_max to be <= 0. 

So we need to cut any rope where h > 0 (if the rope is shorter than the height its nail is at).

So we iterate over all rope/nail pairs, counting how many need to be cut (which is our answer). 
If the nail height (a_i) is larger than the rope length (b_i), it needs to be cut.

Time: O(n)
Space: O(1)

# B: Rudolph and Tic-Tac-Toe

Since the board is small, we can check all rows, columns, and diagonals with brute force.

If a player won, we will find a full row, column, or diagonal with the same symbol.
There is one exception, if the row/column/diagonal is full of '.', it means this row/column/diagonal is still empty so we continue searching.

If we ever find a row/column/diagonal full of the same symbol (as long as that symbol is not '.'), we are done and we can output that symbol as the winner.

If we check all rows/columns/diagonals and do not find a winner, the game was a draw.

Time: O(1), since the board size is fixed. If the board was some arbitrary size n x m, our runtime would be O(mn) since we need to look at each element a few times (depends on the rules with that board).
Space: O(1), since the board size is fixed. If the board was some arbitrary size n x m, our space would be O(mn) since it is convenient to store the whole board (although there may be a way to only store 1 row at a time with O(m)).

# C: Rudolf and Another Competition

First, let's observe that the optimal order to solve problems is in order of shortest time to longest time. This is because the penalty associated with each problem is the sum of the time it takes to solve it plus the time it took to solve all the problems that were solved before this one. Also, we want to solve as many problems as possible, and all of them have the same "value" (1). So we may as well solve the easiest ones first.

So in order to calculate the score (problems solved) and penalty for each participant, we can sort their information and add up their solution times until we exceed the contest duration. The number of times we were able to sum up is the number of problems they solved.

The first row is Rudolf's information. Let's calculate the score and penalty and store it. Let's also keep track of his rank (currently 1).

For the rest of the participants, we calculate their performance (score and penalty) and compare to Rudolf's.
If they outperformed him, we will increment his placing by 1 (he moves down the "leaderboard").
If they do not, his placing remains the same (they are placed below him).

According to the contest rules:
Score:
- greater than Rudolf = outperformed Rudolf, increment Rudolf placing
- less than Rudolf's = did not outperform Rudolf, Rudolf placing stays the same
- same score, go to Penalty Step
Penalty:
- less than Rudolf = outperformed Rudolf, increment Rudolf placing
- greater than Rudolf's = did not outperform Rudolf, Rudolf placing stays the same
- same penalty = did not outperform Rudolf, Rudolf placing stays the same

At the end, we simply output Rudolf's placing.

Time: O(nm log m). There are n participants, for each of them we need to sort the list of solution ties for them, which takes O(m logm) time as there are m problems.
Space: O(m). We need to store and sort the list of solution times (m elements) for each participant. But after we finish calculating the performance of a participant we can reuse this space, so we only need enough space to hold the solution times for 1 participant at a time.

# D: Rudolph and Christmas Tree

First, let's find out how much of each branch is exposed (the height of the exposed portion, call it u_i). to do this, we iterate over the heights of the bases of the branches (y_i).
if the difference between the heights of any 2 consecutive branches (y_i, y_(i+1)) is less than h, the branch y_(i+1) will partially cover branch y. in this case we store u_i = y_(i+1) - y_i.

now we iterate over u_i and calculate the area of each branch based on its uncovered portion, adding it to our sum answer.
if u_i == h, it is fully exposed and we add d*h/2 to ans.

if not, we can find its exposed area by taking its total area and subtracting the area that is covered (since the covered area is a triangle).
the covered area's height is h-u_i. its base is the base of the total triangle, d, times the fraction of the height covered (h-u_i)/h
so the covered area is (h-u_i)*d*(h-u_i)/(2h), and our exposed area is d*h/2 - (covered area).

Time: O(n), as we have to make a few calculations for each branch
Space: O(n), as we store all the branch locations. it is possible to do this in O(1) space by only storing 1 or 2 branch locations at a time, and doing the calculations before reading in the next branch.

# E1: Rudolf and Snowflakes (simple version)

*For the simple version, I will show a simple solution that will not work on the hard version. When I get to the explanation of the hard version, I will explain why the simple solution does not work. 
*The hard solution will work for both versions, if you are only interested in that then skip ahead in the video/document.

We begin with 1 vertex, then add k, then add k^2. We can continue this if we want (k^3, k^4, etc.) but are only required to add up to the k^2 step.

We can brute force this problem, checking all k starting at 2 up to sqrt(n). If k > sqrt(n), then k^2 > n and this k is not possible.

To do this, we initialize our total as 1, then add k, then k^2, then k^3, continuing until our sum reaches or exceeds n. If our sum is exactly n, we answer "YES", if it exceeds n, we increment k by 1 and try again.

Runtime: O(sqrt(n)*log n). This is because we will potentially try sqrt(n) different k values, and each attempt takes log(n) time, since we will go up to power log n, since k^(log n) = n.
Space: O(1), no storage required except our sum and iterators.

# E2: Rudolf and Snowflakes (hard version)

*first I will explain why the easy solution fails, then I will give the hard solution.

Let's assume our runtime for the easy solution is only O(sqrt(n)). In the hard problem, n <= 1E18, which means sqrt(n) = 1E9. we can do about 1E7 operations per second, so this is much too slow.

*the video will contain some whiteboard math that is quickly summarized in this document so be sure to check out the video if this explanation is confusing.

instead of iterating over k, let's iterate over p. p has to be at least 2 since the outer layer of the snowflake is at least k^2. the maximum value of p is 60 since 2^60 (2 is the minimum value of k) is > 1E18 which is the max value of n.

let's take our k to be n^(1/p), rounded down. if k < 2, then it can't be our answer since k > 1. also, this means we are done, since for any greater value of p, k will also be less than 2. so we return "NO".

now for the case where k >= 2.

(whiteboard math in video)

k^(p+1)-1 = (k-1)*n, so we can just check whether our k and p solve this equation. if so, we return "YES", otherwise we increment p and continue.

Runtime: O(log n), since we iterate up to p such that 2^p = n, so p = O(log n).
Space: O(1), no storage

# F: Rudolph and Mimic

*This is an interactive problem, check out codeforces's guide on that if necessasry: https://codeforces.com/blog/entry/45307

We have 5 chances to find the mimic, including giving our final answer. so by the time we walk into the room the 5th time, we need to know the answer.

our strategy will be to count the number of each object in the room on every visit, and compare this count to the previous count to see what has changed.

on our first visit, we will always take our count and then leave without discarding anything since we have no information.

beginning on our second attempt, we take our count and compare it to the previous count. if it changes, it means the mimic changed form. we look at which object's count increased, the mimic has taken the form of this object. so we can discard all objects that are not of this type. 

after we have done our discards, we simply wait until the mimic changes again. since the only remaining objects (aside from the mimic) are all the same type (the form that the mimic chose after its original form), the mimic will be the only one of a different type and then we can give our answer.

in other words:
- mimic begins in form A (unknown)
- wait until mimic shapeshifts
- mimic turns into some form B (we know what B is)
- discard all objects that are not of type B
- wait until mimic shapeshifts
- mimic turns into some form C (all other objects are type B, so we have found the mimic)

We can guarantee this take only 5 visits. the mimic cannot stay in the same form for more than 2 visits in a row. so we can perform our discards on visit 3 in the worst case scenario. in the worst case scenario, the mimic stays in the same form for our 4th visit and we cannot do anything. however, before our 5th visit it is forced to change form, revealing itself.

We can eliminate all objects except for one type during visit 3.
we can pinpoint the mimic during visit 5.

Time: O(n), since we need to look at the objects in the room every time we visit. since the number of visits is bounded, our time is O(n). The number of attempts we have do not matter (as long as it is at least 5) since can always deliver the answer in 5 queries. If n and a_max (number of object types) were both large enough, we would use a map and then our runtime would be O(n logn).

Space: O(1), since we use an array/map to keep track of our count, and the maximum number of object types is bounded (9). If there were n object types our space would be O(n). 

# G: Rudolph and CodeVid-23

Rudolph's current condition (based on the bitstring representing his symptoms) can be thought of as a state. Since there are at most 10 symptoms, we can enumerate all Rudolph states in a graph with at most 2^10 = 1024 vertices. Our goal is to reach state 0 (000000000).

To build our graph, we will iterate over all the medicines and draw edges onto our graph. 

On a bitwise level, Rudolph will have symptom i if and only if he had it before, and the medicine does not remove it, or if the medicine causes it as a side effect.
so if the medicine's symptom removal bitstring is "rem_i", and its side effect bitstring is "add_i", our new state will be (old_state AND NOT rem_i) OR add_i

There will be an edge e between vertices u and v if there is a medicine that will cause Rudolph to go from state u to state v. The edge's weight will be the number of days Rudolph takes the medicine for.
We iterate over all vertices u, and draw an edge between u and v, where v is the "new state": (u AND NOT rem_i) OR add_i. don't forget to do this for all medicines.

*we initialize all graph entries as INT_MAX, and when we draw an edge, we take the min of the current edge (if there exists one) and the new edge since this represents 2 medicines that do the same thing, we don’t care about the one that takes more days. When we traverse the graph with Dijkstra’s, INT_MAX in our adj matrix signifies that 2 vertices are not neighbors since it was never overwritten.

Now that we have our graph, we need to find the shortest path from our initial state to the fully cured state (if one exists). to do this we can simply run Dijkstra's algorithm. There are plenty of resources on Dijkstra's so I will not go through the steps but I will explain the global data structures my implementation maintains.

Based on our graph building, we will have 1 edge per medicine per vertex/state. Therefore we will have O(m*2^n) edges which would be a dense graph. So we should use an adjacency matrix.

dist keeps track of the shortest path to each state, vis keeps track of nodes we have already visited and confirmed shortest paths for. the set unvis keeps track of the best paths we have for unvisited nodes so far. more importantly, it also keeps them ordered so we can easily pick the unvisited node with the shortest path so far.

Time: O((m+n)*(2^n)). Building our graph takes O(m*2^n) time since we need to draw an edge for each medicine for each node. Dijkstra's takes O(E VlogV) time, where E is the number of edges, and V is the number of vertices.
E is m*(2^n) since we drew that many edges. V is 2^n. So we have m*(2^n) + (2^n)log(2^n) = m*(2^n) + n*(2^n), or O((m+n)*2^n).

Space: O(m*(2^n)). We have m*(2^n) edges to store in our graph, all our other data structures take O(2^n) space so our total space simplifies to O(m*(2^n)).
