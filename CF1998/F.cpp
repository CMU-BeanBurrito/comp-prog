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
#define MAXN 200'000

vector<ll> fact (MAXN+1);
vector<ll> invf (MAXN+1);

ll gcdExt(ll a, ll b, ll* x, ll* y)
{
    if (a == 0LL)
    {
        *x = 0LL;
        *y = 1LL;
        return b;
    }
    else
    {
        ll x1, y1;
        ll gcd = gcdExt(b % a, a, &x1, &y1);

        *x = y1 - (b/a) * x1;
        *y = x1;

        return gcd;
    }
}

ll inv (ll a, ll m) // modular inverse of a mod M
{
    ll x, y;
    ll g = gcdExt(a, m, &x, &y);

    return (x % m + m) % MOD;
}

ll nck(ll n, ll k)
{
    if (n < k) return 0LL;
    
    return fact[n] * invf[k] % MOD * invf[n-k] % MOD;
}

void solve() {
    ll n, k; cin >> n >> k;

    vector<int> v (n);
    int ones = 0;
    int zeroes = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1) ones++;
    }

    zeroes = n-ones;

    ll total = 0;

    for (int i = 0; i < (k+1)/2 && i <= zeroes; i++)
    {
        total += nck(zeroes, i) * nck(ones, k-i);
        total %= MOD;
    }

    printf("%lld\n", total);
}

int main() {
    int t; cin >> t;

    fact[0] = 1LL;
    invf[0] = 1LL;

    for (int i = 1; i <= MAXN; i++)
    {
        fact[i] = fact[i-1] * i % MOD;
        invf[i] = inv(fact[i], MOD);
    }
    
    while(t--) {
        solve();
    }
    
    return 0;
}



