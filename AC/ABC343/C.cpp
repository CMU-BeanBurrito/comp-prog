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

bool isPalindrome(ll n)
{
    vector<int> digits;

    while(n > 0)
    {
        digits.push_back(n%10);
        n /= 10;
    }

    for (int i = 0; i < (digits.size()+1)/2; i++)
    {
        if (digits[i] != digits[digits.size()-i-1]) return false;
    }

    return true;
}

void solve() {
    ll n; cin >> n;

    ll best = 1;

    for (int i = 1; 1LL*i*i*i <= n; i++)
    {
        ll x = 1LL*i*i*i;
        if (isPalindrome(x)) best = x;
    }

    printf("%lld\n", best);
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


