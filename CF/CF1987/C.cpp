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

void solve() {
    int n; cin >> n;

    vector<int> h (n+1);

    for (int i = 1; i <= n; i++) cin >> h[i];

    vector<ll> dp (n+1);
    dp[n] = h[n];

    for (int i = n-1; i > 0; i--)
    {
        if (h[i] >  h[i+1]) dp[i] = max(1LL*h[i], dp[i+1]+1);
        if (h[i] == h[i+1]) dp[i] = dp[i+1] + 1;
        if (h[i] <  h[i+1]) dp[i] = dp[i+1] + 1;
    }

    printf("%lld\n", dp[1]);
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


