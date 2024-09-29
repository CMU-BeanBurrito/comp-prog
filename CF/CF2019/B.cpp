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

void solve() {
    int n, q; cin >> n >> q;

    vector<int> x (n+1);
    map<ll, int> mp;

    for (int i = 1; i <= n; i++) cin >> x[i];

    for (int i = 1; i <= n-1; i++)
    {
        // left endpoint
        ll segments = 1LL*i*(n-i) + (i-1); // same as endpoint, but also all segments from endpoint 1, 2....i-1 to endpoint i
        mp[segments]++;

        // interior points
        int points = x[i+1]-x[i]-1;
        mp[1LL*i*(n-i)] += points; // each endpoint prior to this point is paired with each endpoint after this point
    }

    // last endpoint
    mp[n-1]++;

    while(q--)
    {
        ll k; cin >> k;
        printf("%d ", mp[k]);
    } printf("\n");
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


