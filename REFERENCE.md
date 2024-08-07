REFERENCE FOR COMPETITIVE PROGRAMMING:

# Prefix Sums

# Binary Search

# Depth-First Search

# Breadth-First Search

# Extended Euclidean Algorithm
- Inputs: integers a, b
- Outputs: integers x, y s.t. $a*x + b*y = gcd(a, b)$

Can be used to find modular inverse of a under M (find x s.t. a*x mod M = 1)

Note that it contains the Euclidean GCD algorithm.

- Set b = M, then $a*x + M*y = 1 mod M$
- $M*y = 0 mod M$
- $a*x = 1 mod M$

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

int inv (int a, int m) // modular inverse of a mod M
{
    int x, y;
    int g = gcdExt(a, m, &x, &y);

    return (x % m + m) % m;
}

```