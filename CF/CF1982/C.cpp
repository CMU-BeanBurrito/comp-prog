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
    int n, l, r; cin >> n >> l >> r;

    vector<int> v (n);
    
    for (int i = 0; i < n; i++) cin >> v[i];

    ll sum = v[0];
    int lptr = 0; int rptr = 0;
    int wins = 0;

    while (lptr < n)
    {
        while(sum < l && rptr < n-1)
        {
            rptr++;
            sum += v[rptr];
        }

        if (sum > r || sum < l)
        {
            sum -= v[lptr];
            lptr++;
        }
        else
        {
            lptr = rptr+1;
            rptr = rptr+1;
            sum = v[rptr];
            wins++;
        }
    }

    printf("%d\n", wins);
    
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


