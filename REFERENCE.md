REFERENCE FOR COMPETITIVE PROGRAMMING:

# Basic Competitive Programming Concepts

## Prefix Sums
Useful for many things, too many to list here. As a general idea, they are used as precomputation so we can check the total value of a segment in an array in constant time as opposed to time proportional to the length of the segment.

To build it, create another array. Depending on the situation, it might useful to pad with an initial 0. Otherwise, just add the prefix sum from the previous index and the current element to get the current prefix sum. For example, `prefix_sum[i] = prefix_sum[i-1] + array[i]`

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

If we add the red and yellow squares that have an 'x', we will have the sum of the orange squares times two, plus the sum of the red squares and yellow squares. So, we need to subtract the sum of the orange squares which is the orange square with the 'x'.

![image info](images/2D%20Prefix%20Sum%20Building.png)

##### Extracting a sum from a prefix sum:

We want to get the sum of the green cells, but the green cell with x contains the sum of the green, red, blue, and purple cells. So, we subtract the prefix sum of the blue cells (blue cell with 'x'), and subtract the prefix sum of the red cells (red cell with 'x'). However, both the blue cell with the 'x' and the red cell with 'x' contain the sum of the purple cells as well. Since we subtracted the blue and red, we also subtracted the purple twice. However, we only want to subtract it once. So, we we need to add it back once. So we add the prefix sum of the purple cells (purple cell with an 'x'). 

![image info](images/2D%20Prefix%20Sum%20Extracting.png)

### 3D Prefix Sum

# Basic Algorithms

## Binary Search

## Depth-First Search

## Breadth-First Search

## Dijkstra's Algorithm

# Number Theory and Primality

## Consecutive Numbers
- Consecutive numbers are coprime.

gcd(x+1, x) must also divide x+1-x = 1. Trivially, only 1 can divide 1. So gcd(x+1, x) = 1. 

Therefore x and x+1 are coprime.

## Extended Euclidean Algorithm
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
## Sieve of Eratosthenes

Used to quickly generate a lookup table for prime numbers (precomputed and used many times across many tests). The general idea is to slowly filter/sieve out composite numbers by taking a prime number p and eliminating all other numbers that have p as a factor.

Iterate over all numbers starting with 2 (the first prime). If it has not been filtered out yet, it is prime. If it was composite, it would have been filtered out already because there would be at least one less number that is a factor. Since this number is prime, mark all multiples of it (aside from itself) as composite.

If it has been filtered out already, it is already known to be composite so we do nothing and move to the next number. Every multiple of this number has already been eliminated as well.

The code below generates a lookup table in O(N log N) where N is the size of the table (in this case, 2E5). It will allow us to check the primality of numbers up to N in constant time. 
```
vector<bool> erat (200001, true);
 
void sieve()
{
    erat[0] = false;
    erat[1] = false;
 
    for (int i = 2; i*i <= 200000; i++)
    {
        if (!erat[i]) continue;
 
        for (int j = 2*i; j <= 200000; j+=i)
        {
            erat[i] = false;
        }
    }
}
```

## Checking larger numbers
However, it will also allow us to check the primality of numbers up to N^2 in O(N) time (we can check all primes in our sieve, if the number does not have any of them as factors, it is also prime). If we need to check multiple numbers that are betwen N and N^2, we can construct another vector with just the primes from our sieve. This would make each query to numbers between N and N^2 take O(N / logN) time. Of course, make sure to account for integer overflow if N^2 exceeds INT_MAX (argument is long long in this case as 4E10 > INT_MAX).

```
vector<bool> erat (200001, true);
vector<int> primes;
void sieve()
{
    erat[0] = false;
    erat[1] = false;
 
    for (int i = 2; i*i <= 200000; i++)
    {
        if (!erat[i]) continue;
        for (int j = 2*i; j <= 200000; j+=i) erat[i] = false;
    }

    for (int i = 0; i < 200001; i++)
    {
        if (erat[i]) primes.push_back(i);
    }
}

// n should be less than or equal to N^2 (in this case, N^2 = 4E10)
bool check(ll n)
{
    for (int p : primes)
    {
        if (n % p == 0) return false;
    }

    return true;
}
```
