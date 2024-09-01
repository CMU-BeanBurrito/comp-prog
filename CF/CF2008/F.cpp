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

void solve() {
    int n; cin >> n;

    vector<int> v (n);

    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> pref (n);

    pref[0] = 0;

    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i-1] + v[i-1];
        pref[i] %= MOD;
    }

    ll num = 0;

    for (int i = 0; i < n; i++)
    {
        num += (1LL*pref[i]*v[i]);
        num %= MOD;
    }

    ll denom = 1LL * n * (n-1) / 2 % MOD;

    printf("%lld\n", 1LL* num * inv(denom, MOD) % MOD);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



