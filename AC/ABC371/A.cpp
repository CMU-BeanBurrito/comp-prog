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
    char ab, ac, bc; cin >> ab >> ac >> bc;

    if (ab == '>')
    {
        if (bc == '>')
        {
            printf("B\n");
        }
        else if (ac == '>')
        {
            printf("C\n");
        }
        else
        {
            printf("A\n");
        }
    }
    else
    {
        if (ac == '>')
        {
            printf("A\n");
        }
        else if (bc == '>')
        {
            printf("C\n");
        }
        else
        {
            printf("B\n");
        }
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


