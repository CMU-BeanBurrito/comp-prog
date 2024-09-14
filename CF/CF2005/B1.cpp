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
    int n, m, q; cin >> n >> m >> q;

    vector<int> b (m);
    vector<int> a (q);

    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < q; i++) cin >> a[i];

    for (int i = 0; i < q; i++)
    {
        if (a[i] < b[0] && a[i] < b[1])
        {
            printf("%d\n", min(b[0], b[1])-1);
        }
        else if ((a[i] < b[0] && a[i] > b[1]) || (a[i] > b[0] && a[i] < b[1]))
        {
            printf("%d\n", abs(b[0]-b[1])/2);
        }
        else
        {
            printf("%d\n", n-max(b[0], b[1]));
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


