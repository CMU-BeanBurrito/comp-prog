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

ll gauss(ll n)
{
    return 1LL * n * (n+1) / 2;
}

void solve() {
    ll n, k; cin >> n >> k;

    ll c = (k+n-1)*(k+n)/2 + (k-1)*k/2;

    double cld = c;

    double a = 1.0;
    double b = 1.0;

    double rt = (-b + sqrt(b*b + 4*a*cld)) / (2.0);

    int i = (int)round(rt);

    ll left = abs((gauss(i)-gauss(k-1))-(gauss(k+n-1)-gauss(i)));
    ll right = abs((gauss(i+1)-gauss(k-1))-(gauss(k+n-1)-gauss(i+1)));

    printf("%lld\n", min(left, right));
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


