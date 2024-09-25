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
    int n, d, k; cin >> n >> d >> k;

    vector<int> l (n);
    vector<int> r (n);

    vector<int> days (n+2, 0);

    for (int i = 0; i < k; i++)
    {
        cin >> l[i] >> r[i];
        l[i] = max(1, l[i]-d+1);
    }

    for (int i = 0; i < k; i++)
    {
        days[l[i]] += 1;
        days[r[i]+1] -= 1;
    }

    for (int i = 1; i <= n; i++)
    {
        days[i] += days[i-1];
    }

    int mx = 0;
    int mxi = 0;
    for (int i = 1; i <= n; i++)
    {
        if (days[i] > days[mxi])
        {
            mxi = i;
            mx = days[i];
        }
    }

    // brother visit
    printf("%d ", mxi);

    int mn = INT_MAX;
    int mni = 0;

    for (int i = 1; i <= n-d+1; i++)
    {
        if (days[i] < mn)
        {
            mni = i;
            mn = days[i];
        }
    }

    printf("%d\n", mni);
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


