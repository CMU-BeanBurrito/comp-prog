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
    ll k; cin >> k;

    ll left = 1; ll right = 1LL*INT_MAX;

    while(left < right)
    {
        ll mid = (left+right)/2;

        //printf("MID %lld %lld %lld\n", mid, left, right);

        if (mid*mid == k)
        {
            left = mid;
            right = mid;
        }
        else if (mid*mid > k)
        {
            right = mid-1;
        }
        else
        {
            left = mid;
        }

        if (left + 1 == right)
        {
            if (right*right > k)
            {
                right = left;
            }
            else
            {
                left = right;
            }

        }
    }

    ll ans = left+k;

    if ((left+1)*(left+1) <= k+left) ans++;

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


