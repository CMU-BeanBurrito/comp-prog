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
    ll b, c, d; cin >> b >> c >> d;

    int bit = 0;

    ll ans = 0;

    while(bit <= 59)
    {
        ll val = 1LL << bit;

        bool bbit = ((b&val)==val);
        bool cbit = ((c&val)==val);
        bool dbit = ((d&val)==val);

        if (bbit && cbit && !dbit)
        {
            ans |= val;
        }
        else if (!bbit && !cbit && dbit)
        {
            ans |= val;
        }
        else if (bbit && !cbit && !dbit)
        {
            printf("-1\n");
            return;
        }
        else if (!bbit && cbit && dbit)
        {
            printf("-1\n");
            return;
        }

        bit++;
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


