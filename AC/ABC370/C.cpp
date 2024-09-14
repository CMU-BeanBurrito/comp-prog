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
    string s, t; cin >> s >> t;

    vector<string> x;

    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] > t[i])
        {
            s[i] = t[i];
            x.push_back(s);
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] < t[i])
        {
            s[i] = t[i];
            x.push_back(s);
        }
    }

    printf("%d\n", x.size());

    for (string a : x)
    {
        cout << a << endl;
    }
}

int main() {
    solve();
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


