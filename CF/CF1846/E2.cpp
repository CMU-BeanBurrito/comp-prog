/*
    Author: BeanBurrito
*/

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

#define MOD 1'000'000'007

int gcdExt(int a, int b, int* x, int* y);
int inv (int a, int m);
ll kadane(vector<int>& a, int n);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

/**
 * 1 + k + k^2 + k^3.....k^p = n
 * k + k^2 + k^3........k^(p+1) = n*k
 * 
 * subtract n from both sides
 * 
 * k^(p+1) - 1 = n*(k-1)
 */

void solve() {
    ll n; cin >> n;
    for (int p = 2; p < 63; p++)
    {
        double k = floor(pow(n, 1.0/p));

        int kint = (int)k;

        if (k < 2)
        {
            printf("NO\n");
            return;
        }

        ll powk = 1;
        for (int i = 1; i <= p+1; i++)
        {
            powk *= kint;
        }

        if (powk-1 == 1LL*n*(kint-1))
        {
            printf("YES\n");
            return;
        }
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}

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
ll kadane(vector<int>& a, int n)
{
    ll sum = 0;
    ll best = 0;

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

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a%b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
