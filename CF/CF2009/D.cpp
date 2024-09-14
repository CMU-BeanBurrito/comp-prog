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

    vector<pair<int, int>> a (n);
    vector<vector<bool>> pts (n+1, vector<bool> (2, false));

    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        pts[x][y] = true;
    }

    ll ans = 0;

    for (int x = 0; x <= n; x++)
    {
        if (pts[x][0] && pts[x][1]) ans += (n-2);
    }

    for (int x = 0; x <= n-2; x++)
    {
        if (pts[x][0] && pts[x+1][1] && pts[x+2][0]) ans++;
        if (pts[x][1] && pts[x+1][0] && pts[x+2][1]) ans++;
    }

    printf("%lld\n", ans);
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


