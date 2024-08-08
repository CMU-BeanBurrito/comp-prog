REFERENCE FOR COMPETITIVE PROGRAMMING:

# Prefix Sums

# Binary Search

# Depth-First Search

# Breadth-First Search

# Extended Euclidean Algorithm
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
# Sieve of Eratosthenes

Used to quickly generate a lookup table for prime numbers. The general idea is to slowly filter/sieve out composite numbers by taking a prime number p and eliminating all other numbers that have p as a factor.

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
However, it will also allow us to check the primality of numbers up to N^2 in O(N) time (we can check all primes in our sieve, if the number does not have any of them as factors, it is also prime). If we need to check multiple numbers that are betwen N and N^2, we can construct another vector with just the primes from our sieve. This would make each query to numbers between N and N^2 take O(N / logN) time. Of course, make sure to account for integer overflow.

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
 
        for (int j = 2*i; j <= 200000; j+=i)
        {
            erat[i] = false;
        }
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
