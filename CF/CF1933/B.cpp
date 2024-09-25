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
    
    vector<int> a (n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mod1 = 0;
    int mod2 = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        sum %= 3;

        if (a[i] % 3 == 1) mod1++;
        if (a[i] % 3 == 2) mod2++;
    }

    if (sum == 0)
    {
        printf("0\n");
    }
    else if (sum == 1)
    {
        if (mod1 > 0)
        {
            printf("1\n");
        }
        else
        {
            printf("2\n");
        }
    }
    else
    {
        printf("1\n");
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


