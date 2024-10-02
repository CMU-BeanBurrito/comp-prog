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
    vector<int> powersk;
    ll n, k; cin >> n >> k;

    ll val = 1;

    if (k == 1 || k > n)
    {
        printf("%d\n", n);
        return;
    }
    
    while(val <= 1e9 && val <= n)
    {
        powersk.push_back(val);
        val *= k;
    }

    int ops = 0;
    int idx = powersk.size()-1;

    while(n > 0)
    {
        if (idx == 0)
        {
            ops += n;
            break;
        }
        if (n >= powersk[idx])
        {
            n -= powersk[idx];
            ops++;
        }
        else
        {
            idx--;
        }
    }

    printf("%d\n", ops);
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


