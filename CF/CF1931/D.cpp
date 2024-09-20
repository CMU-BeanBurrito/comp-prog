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
    int n, x, y; cin >> n >> x >> y;

    vector<int> a (n+1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    map<pair<int, int>, int> mp;

    ll same = 0;
    ll diff = 0;

    for (int i = 1; i <= n; i++)
    {
        mp[make_pair(a[i]%x, a[i]%y)]++;
    }

    for (auto p : mp)
    {
        pair<int, int> other;
        other.first = x-p.first.first;
        other.second = p.first.second;

        if (other.first == x) other.first = 0;

        if (other == p.first)
        {
            same += 1LL*p.second*(p.second-1)/2;
        }
        else
        {
            diff += 1LL*p.second*mp[other];
        }
    }

    diff /= 2;

    printf("%lld\n", same+diff);
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


