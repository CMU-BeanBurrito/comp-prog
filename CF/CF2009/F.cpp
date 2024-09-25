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
    int n, q; cin >> n >> q;

    vector<int> a (n);
    vector<ll> pref (2*n);
    ll asum = 0;

    cin >> a[0];
    pref[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        asum += a[i];
        pref[i] = pref[i-1] + a[i];
    }

    for (int i = 0; i < n; i++) pref[i+n] = a[i] + pref[i+n-1];

    while(q--)
    {
        int l, r; cin >> l >> r;
        l--; r--; // convert to 0 indexing

        int lseg = l/n;
        int rseg = r/n;
        int lidx = (l+lseg)%n;
        int ridx = (r+rseg)%n;
        ll ans = 0;

        if (lseg == rseg)
        {
            if (lidx < ridx)
            {
                ans = pref[rseg+ridx]-pref[lseg+lidx];
            }
            else
            {
                ans = pref[lseg+lidx+n]-pref[rseg+ridx-1];
            }
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


