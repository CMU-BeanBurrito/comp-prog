REFERENCE FOR COMPETITIVE PROGRAMMING:

# Basic Competitive Programming Concepts

## Prefix Sums
Useful for many things, too many to list here. As a general idea, they are used as precomputation so we can check the total value of a segment in an array in constant time as opposed to time proportional to the length of the segment.

To build it, create another array (it can be done by overwriting the original array, but that is often undesirable and virtually all problems afford plenty of space to make another array). Depending on the situation, it might useful to pad with an initial 0. Otherwise, just add the prefix sum from the previous index and the current element to get the current prefix sum. For example, `prefix_sum[i] = prefix_sum[i-1] + array[i]`. 

### 2D Prefix Sum 
For visualization purposes, assume that rows further down have higher row indices, columns further right have higher column indices.

In a 2D prefix sum p of 2D array a, `p[i][j]` is the sum of all `a[r][c]` where `r <= i and c <= j`. Essentially, it is the sum of the rectangle from `a[0][0]` to `a[i][j]`.

The first row and column of the prefix sum can be calculated as 1D prefix sums: `p[0][1] = p[0][0] + a[0][1]`, `p[0][2] = p[0][1] + a[0][2]`, etc.

However, subsequent cells require 4 values to calculate:
- the cell above: `p[i-1][j]`
- the cell to the left: `p[i][j-1]`
- the cell one diagonal to the top left: `p[i-1][j-1]`
- of course, `a[i][j]`

The cell above contains the sum of the rectangle from `a[0][0]` to `a[i-1][j]`.
The cell to the left contains the sum of the rectangle from `a[0][0]` to `a[i][j-1]`.
However, these two rectangles overlap. The overlap is the rectangle from `a[0][0]` to `a[i-1][j-1]`. Since we count this twice, we need to subtract it from the sum of the other two cells.

So the prefix sum for `p[i][j]` is: `a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1]`. See the following section for visualization.

To get the sum of a rectangle within the array, say, the sum of `a[r1][c1]` to `a[r2][c2]`. We need to take the prefix sum of `a[r2][c2]` and subtract the prefix sum of `a[r1-1][c2]` and subtract the prefix sum of `a[r2][c1-1]`. However, both of these contain the prefix sum of `a[r1-1][c1-1]`. We do want to subtract this, but only once. Since we subtracted it twice, we need to add it once.

So the sum of cells `a[r1][c1]` to `a[r2][c2]` is: `p[r2][c2]` - `p[r2][c1-1]` - `p[r1-1][c2]` + `p[r1-1][c1-1]`. See the following section for visualization.

#### Visualization of 2D Prefix Sum Overlap

##### Computing the prefix sum:

To calculate the prefix sum of the blue square, we need the sum of the the orange, red, and yellow squares.

The red square with the 'x' has the prefix sum of the red and orange squares.
The yellow square with the 'x' has the prefix sum of the yellow and orange squares.

If we add the red and yellow squares that have an 'x', we will have the sum of the orange squares times two, plus the sum of the red squares and yellow squares. So, we need to subtract the sum of the orange squares which is the orange square with the 'x', and lastly add the value of the blue square.

![image info](images/2D%20Prefix%20Sum%20Building.png)

##### Extracting a sum from a prefix sum:

We want to get the sum of the green cells, but the green cell with x contains the sum of the green, red, blue, and purple cells. So, we subtract the prefix sum of the blue cells (blue cell with 'x'), and subtract the prefix sum of the red cells (red cell with 'x'). However, both the blue cell with the 'x' and the red cell with 'x' contain the sum of the purple cells as well. Since we subtracted the blue and red, we also subtracted the purple twice. However, we only want to subtract it once. So, we we need to add it back once. So we add the prefix sum of the purple cells (purple cell with an 'x'). 

![image info](images/2D%20Prefix%20Sum%20Extracting.png)

### 3D Prefix Sum

## Dynamic Programming

Solve large, complex problems by breaking them down into smaller, simpler problems before solving these simpler problems (and combining them to get the solution to the original problem). This is a rather broad topic but will try to include some general thoughts as well as examples.

### Maximum Sum Subarray Problem

Given an array of integers (can be positive or negative), find the maximum (contiguous) subarray sum. Clearly, this can be done naively in O(N^2) by brute forcing all O(N^2) subarrays.

#### Kadane's Algorithm

Keep track of one subarray at a time as we traverse from left to right. For each new element, we decided whether we want to add this new element to the current subarray and continue with this subarray, or start a new subarray that is just this new element. After handling each element, we check if our subarray has the maximum sum, in case it is the true maximum sum subarray and we end up decreasing it by adding negative elements or discarding the subarray. At any given point, our running subarray sum is the maximum sum subarray that ends at the current elemtn. The logic is simple:

If the subarray's sum is:
- negative, then discarding this subarray and starting a new one with just new element will be better
- positive, then extending this subarray with the new element will be better
- 0, doesn't matter, fold into either of the above cases

#### Pseudocode
```
best = 0
sum = 0
a[n]

for i in [0, n)
    if (sum > 0)
        sum += a[i]
    else
        sum = a[i]
    
    best = max(best, sum)

return best
```

#### C++ Implementation
```
// populate
vector<int> a (n);

int kadane()
{
    int sum = 0;
    int best = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum > 0)
        {
            sum += a[i];
        }
        else
        {
            sum = a[i];
        }

        best = max(best, sum);
    }

    return best;
}
```

### 0-1 Knapsack Problem

There are n objects (numbered 1 to n) that each have some value v and weight w. You can carry a maximum total weight of c, and are trying to maximize the total value of items you carry.

Define `dp[i][j]` as the best value we can get considering the first `i` objects, and limiting ourselves to a capacity `j`. We will calculate this for all `i, j` such that `1 <= i <= n` and `0 <= j <= c`. The final answer will be `dp[n][c]`.

Clearly, if our max capacity is 0, or we are including 0 items, the max value we can have is 0. So we can initialize our dp with `dp[i][0] = 0`, and `dp[0][j] = 0`.

Now, for each item, we consider whether or not to add it given each capacity. Our DP has the following logic:

If the capacity `j >= w[i]`, then it is possible to put this ith item in our knapsack. However, we may or may not have to remove some items in our knapsack. 
- Let's first consider the case that we do not take it. Then, the max value we can have for this scenario is `dp[i-1][j]` since we basically just using the first i-1 items.
- The second case is that we do take this item. However, we might have to remove some items. If our current capacity is j, then the items that remain in our knapsack must have total weight at most `j-w[i]`. So, we want the max value we can get considering the first `i-1` items that have weight at most `j-w[i]`, plus the value and weight of this item. This value is `dp[i-1][j-w[i]] + v[i]`.
- Take `dp[i][j]` to be the maximum of the two above cases.

If the capacity `j < w[i]`, then it is not possible to put this ith item in our knapsack under the current capacity restriction, even if we remove all the items currently in our knapsack. So, we just consider the first i-1 items under capacity j: `dp[i-1][j]1`.

#### Pseudocode

```
item values v: [v1, v2, v3....vn]
item weights w: [w1, w2, w3....wn]
max_capacity: c

dp[n+1][c+1]

for i in [0, n]
    for j in [0, c]
        if i == 0 or j == 0
            dp[i][j] = 0
        else if j >= w[i] // this item can fit in our knapsack. consider it
            // do not take this item, just take the best knapsack with weight <= j from before this item
            a = dp[i-1][j]

            // make space for this item and take it. the items we keep (aside from this one) must have at most weight j-w[i]
            // so take the best knapsack with that weight considering the first i-1 items
            b = dp[i-1][j-w[i]] + v[i]

            dp[i][j] = max(a, b)
        else // this item does not fit into the knapsack under weight restriction j, even if we remove all other items. so we cannot take it
            dp[i][j] = dp[i-1][j]

return dp[n][c]
```

#### C++ Implementation

```
// populate with inputs
vector<int> v (n+1);
vector<int> w (n+1);
int c;

int knapsack()
{
    vector<vector<int>> dp (n+1, vector<int> (n+1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i == 0 || j == 0) // no items to consider or can't carry any weight
            {
                dp[i][j] = 0;
            }
            else if (j >= w[i]) // consider item
            {
                int a = dp[i-1][j]; // don't take it, take best knapsack with previous items at this weight
                int b = dp[i-1][j-w[i]] + v[i]; // make room and take it, along with knapsack with previous items that can fit with this item
                dp[i][j] = max(a, b); // take the best out of these two scenarios
            }
            else // can't take this item at this weight restriction, take best knapsack at this weight
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // return best knapsack considering all n items and the knapsack's true capacity c
    return dp[n][c];
}
```

# Basic Algorithms

## Binary Search
Of course, classically used to find the location (or indicate the absence) of an element in a sorted array.
However, in competitive programming, often used to find the minimum or maximum value that satisfies some criteria.
More specifically, there is some critical value that satisfies some criteria. All values higher than it also satisfy this criteria, and none of the values below it do. We would like to find this value.
- Note that sometimes the critical value is the maximum value that fulfills the criteria, all lesser values also fulfill it, but no greater values do, the same approach can be used with slight changes to the logic

### Example

There is some critical value `x` s.t. `f(x)` returns `True`. `f(y) = True` for all `y >= x`, and `f(y) = False` for all `y < x`. We want to find `x` (the lowest value that evaluates to `True`).
We know that `1 <= x <= 100'000'000`. Our search space is then `[1, 100'000'000]`.

We repeated choose the midpoint of our search space (in this first iteration, this would be 50'000'000). We evaluate `f(50'000'000)`.
- If it evaluates to `False`, then we know that `[1, 49'999'999]` will all evaluate to `False`, and therefore do not need to be checked. So our search space becomes `[50'000'000, 100'000'000]`.
- If it evaluates to `True`, then we know that `[50'000'001, 100'000'000]` will all evalute to `True`, but do not need to be searched since we want to find the lowest value that evaluates to `True`. Search space is now `[1, 50'000'000]`.

In essence, our search space at any given time is the set of values that still might be the answer. It is easy to see that it halves in size on each iteration, as we discard one half after each evaluation. It therefore has a runtime of `O(Fn)` where `F` is the runtime of the evaluation itself (function `f`). Eventually only one value will remain (search space contains only one value) and that must be the answer.

These examples require `f` to be "sorted", which is why every value greater than or equal to `x` evalutes to `False` and every value less than `x` evaluates to `True` (or vice versa). Another way of thinking about this is as that we are searching for the first `1` (or the last `0`) in an array that looks like `[0, 0, 0,...,0, 1, 1, 1....1]`. Or the first `0`/last `1` in an array that looks like `[1, 1, 1..., 1, 0, 0, 0.....0]`.

### C++ Implementation (for finding minimum x that fits some criteria)

```
bool f(int x)
{
    ...
    ...
    ...
    return True, or False
}

int binsearch()
{
    int left = 1;
    int right = 100'000'000;

    while(left < right)
    {
        int mid = (left+right)/2;

        if (f(mid))
        {
            // mid could be the answer, but the values above it are not the minimum
            right = mid;
        }
        else
        {
            // mid is not the answer, and none of the values below it evaluate to True either
            left = mid+1;
        }
    }

    // left == right at this point
    return left;
}
```

### C++ Implementation (for finding maximum x that fits some criteria)

```
bool f(int x)
{
    ...
    ...
    ...
    return True, or False
}

int binsearch()
{
    int left = 1;
    int right = 100'000'000;

    while(left < right)
    {
        // Round up mid closer to right. This is because if left + 1 = right, mid will be left and could get stuck infinitely if f(mid) = False
        int mid = (left+right+1)/2;

        if (!f(mid))
        {
            // mid could be the answer, but the values below it are not the maximum
            left = mid;
        }
        else
        {
            // mid is not the answer, and none of the values above it evaluate to False
            right = mid-1;
        }
    }

    // left == right at this point
    return left;
}
```

### C++ Implementation ("classic" setting, find first index with element x or report that none exists)
```
vector<int> a (n);

int binsearch(int x) // x is element we are looking for
{
    int left = 0;
    int right = n-1;

    while(left < right)
    {
        int mid = (left+right)/2;

        if (a[mid] == x)
        {
            // found the element, but we don't know if earlier indices also contain x
            right = mid;
        }
        else if (a[mid] < x)
        {
            // element must be to the right, discard mid and everything to the left
            left = mid+1;
        }
        else // a[mid] > x
        {
            // element must be to the left, discard mid and everything to the right
            right = mid-1;
        }
    }

    // at this point, left == right, or left > right (left == right+1)

    if (left == right) // still need to check this index
    {
        // found it
        if (a[left] == x) return x;

        // x is not in this array
        return -1;
    }

    // if left > right, we already checked all indices and x does not exist
    return -1;
}
```
## Depth-First Search

## Breadth-First Search
Traverse a graph in "levels", visiting all nodes adjacent to the source before moving further outwards.

### C++ Implementation (Base code)
```
#define MAXN [INSERT VALUE]
vector<vector<int>> g (MAXN);
vector<bool> vis (MAXN, false);
queue<int> q;

void bfs(int root)
{
    q.push(root)
    vis[root] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
```

### C++ Implementation (marking distance from source)
Often, it is useful to record the distance of each vertex from the source during the traversal.
To do so, we simply record the distance of a vertex as we push it on the queue.
Its distance from the source is 1 greater than its parent's.

```
#define MAXN [INSERT VALUE]
vector<vector<int>> g (MAXN);
vector<bool> vis (MAXN, false);
vector<int> dist (MAXN, INT_MAX);
queue<int> q;

void bfs(int root)
{
    q.push(root)
    vis[root] = true;
    dist[root] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
                dist[v] = dist[u]+1;
            }
        }
    }
}
```

### Variants and Applications
BFS can be used with multiple sources simultaneously. To do this, push all source/roots onto the queue before any traversal actions.

BFS can be used to bipartition a graph (use even and odd distances to make the two sets).

## Dijkstra's Algorithm

# Math and Number Theory

## Divisibility

Divisibility by 3:
A number is divisible by 3 iff the sum of its digits is divisible by 3 (essentially same rule as 9).

Divisibility by 7:

Divide number into segmenets of 3 digits. If the number of digits is not divisible by 3, the incomplete segment should be the most significant digits. For example, `12345` would be broken up as `12` and `345`. Add each segment, but alternate the sum. For example, `123456789` will be `123 - 456 + 789 = 456`. Original number is divisible by 7 iff this sum is divisible 7 (in this case, it is not).

Divisibiliby by 9:
A number is divisible by 9 iff the sum of its digits is divisible by 9 (essentially same rule as 3).

## Primality

### Consecutive Numbers
- Consecutive numbers are coprime.

gcd(x+1, x) must also divide x+1-x = 1. Trivially, only 1 can divide 1. So gcd(x+1, x) = 1. 

Therefore x and x+1 are coprime.

### Extended Euclidean Algorithm and Modular Inverse
- Inputs: integers a, b
- Outputs: integers x, y s.t. ax + by = gcd(a, b)

Can be used to find modular inverse of a under M (find x s.t. a*x mod M = 1)

Note that it contains the Euclidean GCD algorithm.

- Set b = M, then ax + My = 1 mod M
- Also, My = 0 mod M
- Therefore, ax = 1 mod M

```
int gcdExt(int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    else
    {
        int x1, y1;
        int gcd = gcdExt(b % a, a, &x1, &y1);

        *x = y1 - (b/a) * x1;
        *y = x1;

        return gcd;
    }
}

int inv (int a, int m) // modular inverse of a mod m
{
    int x, y;
    int g = gcdExt(a, m, &x, &y);

    return (x % m + m) % m;
}

```
### Sieve of Eratosthenes

Used to quickly generate a lookup table for prime numbers (precomputed and used many times across many tests). The general idea is to slowly filter/sieve out composite numbers by taking a prime number p and eliminating all other numbers that have p as a factor.

Iterate over all numbers starting with 2 (the first prime). If it has not been filtered out yet, it is prime. If it was composite, it would have been filtered out already because there would be at least one less number that is a factor. Since this number is prime, mark all multiples of it (aside from itself) as composite.

If it has been filtered out already, it is already known to be composite so we do nothing and move to the next number. Every multiple of this number has already been eliminated as well.

The code below generates a lookup table in O(N log N) where N is the size of the table (in this case, 2E5). It will allow us to check the primality of numbers up to N in constant time. 
```
#define ERATSIZE 200'000
vector<bool> erat (ERATSIZE+1, true);
 
void sieve()
{
    erat[0] = false;
    erat[1] = false;
 
    for (int i = 2; i*i <= ERATSIZE; i++)
    {
        if (!erat[i]) continue;
 
        for (int j = 2*i; j <= ERATSIZE; j+=i)
        {
            erat[j] = false;
        }
    }
}
```

#### Checking larger numbers
However, it will also allow us to check the primality of numbers up to N^2 in O(N) time (we can check all primes in our sieve, if the number does not have any of them as factors, it is also prime). If we need to check multiple numbers that are betwen N and N^2, we can construct another vector with just the primes from our sieve (this takes O(N) time). This would make each query to numbers between N and N^2 take O(log N) time (after the vector of primes is constructed), as there are O(log N) primes in the first N numbers. Of course, make sure to account for integer overflow if N^2 exceeds INT_MAX (argument is long long in this case as 4E10 > INT_MAX).

```
#define ERATSIZE 200'000
vector<bool> erat (ERATSIZE+1, true);
vector<int> primes;
void sieve()
{
    erat[0] = false;
    erat[1] = false;
 
    for (int i = 2; i*i <= ERATSIZE; i++)
    {
        if (!erat[i]) continue;
        for (int j = 2*i; j <= ERATSIZE; j+=i) erat[j] = false;
    }

    for (int i = 0; i <= ERATSIZE; i++)
    {
        if (erat[i]) primes.push_back(i);
    }
}

// n should be less than or equal to N^2 (in this case, N^2 = 4E10)
bool check(ll n)
{
    for (int p : primes)
    {
        if (n == p) return true;
        if (n % p == 0) return false;
    }

    return true;
}
```
## Combinatorics

### n choose k
In combinatorics problems, we frequently have to compute `n choose k` (or `(n choose k) mod M`), which is equal to `n! / [k! * (n-k)!]`. However, without preprocessing, calculating this quotient numerous times across many test cases when `n = O(1E6)` can take a while.

The problem arises when we have to find the quotient, it is easy enough to compute `1!, 2!, 3!...n!` during preprocessing in `O(n)`. Then, we easily have the 3 components of the quotient: `n!, k!, (n-k)!`. This works well enough when `M` doesn't come into play and we can just multiply/divide to get the quotient. However, in modular arithmetic, in order to find `(a / b) mod M`, we need to take `(a mod M) * (inverse(b) modM)`, where `inverse(b)` is the modular inverse of `b` under `M`. To do this, we use the extended Euclidean algorithm.

#### Code

- Use this module to compute factorials and their inverses.
- Make sure to define `MAXN` and `MOD` appropriately.
- `nck_preprocess()` can be called in `main` to be executed once prior to all test cases.

```
#define MAXN ???
vector<ll> fact (MAXN+1);
vector<ll> invf (MAXN+1);

ll nck(ll n, ll k)
{
    if (n < k) return 0LL;
    
    return fact[n] * invf[k] % MOD * invf[n-k] % MOD;
}

void nck_preprocess()
{
    fact[0] = 1LL;
    invf[0] = 1LL;
 
    for (int i = 1; i <= MAXN; i++)
    {
        fact[i] = fact[i-1] * i % MOD;
        invf[i] = inv(fact[i], MOD);
    }

}
```

# Graph Concepts/Algorithms

## Bipartite Graphs
A graph is bipartite if all vertices can be assigned to exactly one of two sets, and no vertex is adjacent to another vertex in the same set.

### Bipartite Matching
TODO: relation to network flow

## Topological Sorting
A topological sorting is an ordering of a directed graph's vertices such that if there is an edge from vertex `u` to vertex `v`, then `u` precedes `v` in the ordering.

A topological sorting can only be generated for a DAG (directed, acyclic graph).

### Kahn's Algorithm
Kahn's Algorithm can be used to generate a topological ordering.

Begin by computing the in-degree (number of edges ending at a vertex) for each vertex.

Push all vertices with an in-degree of 0 onto the queue. These vertices will go first in the topological sorting as no edge leads to them, therefore no vertices precede them.

Until the queue is empty:
- pop a vertex `v` from the queue, add it to the sorted list
- decrement the in-degree of all of its children (processing `v` and its outward edges)
- if any of these children now have an in-degree of 0, push them onto the queue

#### C++ Implementation
TODO: code

#### Cycle Detection
Kahn's Algorithm can be used to detect cycles. Kahn's Algorithm will terminate without processing vertices that were part of a cycle. They will not be added into the queue or the sorted list. Therefore, upon termination, if the sorted list contains less nodes than the connected component Kahn's was run on, the connected component contained a cycle.