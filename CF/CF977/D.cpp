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


bool pfsort(const pair<pair<int, int>, ll>& a, const pair<pair<int, int>, ll>& b)
{
    if (a.first.first > b.first.first)
    {
        return true;
    }
    else if (b.first.first > a.first.first)
    {
        return false;
    }
    else
    {
        return a.first.second < b.first.second;
    }
}

void solve() {
    int n; cin >> n;

    vector<ll> a (n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<pair<int, int>, ll>> pf (n);

    for (int i = 0; i < n; i++)
    {
        ll x = a[i];

        while(x % 2 == 0)
        {
            x /= 2;
            pf[i].first.second++;
        }

        while(x % 3 == 0)
        {
            x /= 3;
            pf[i].first.first++;
        }

        pf[i].second = a[i];
    }

    sort(pf.begin(), pf.end(), pfsort);

    for (int i = 0; i < n; i++)
    {
        printf("%lld ", pf[i].second);
    }
}

int main() {
    solve();
    
    return 0;
}



