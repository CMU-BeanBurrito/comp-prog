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

void solve() {
    int n, k; cin >> n >> k;

    vector<int> v (n);

    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    if (k == 0)
    {
        if (v[0] == 1)
        {
            printf("-1\n");
            return;
        }
        printf("1\n");
        return;
    }
    else if (k == n)
    {
        printf("1000000000\n");
        return;
    }

    if (v[k-1] == v[k])
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", v[k-1]);
    }
}

int main() {
    solve();
    
    return 0;
}



