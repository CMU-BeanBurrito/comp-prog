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
    int n, m; cin >> n >> m;

    vector<int> a (n);
    vector<int> z (n, 0); // trailing zeros
    int digits = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        int x = a[i];

        while(x > 0)
        {
            x /= 10;
            digits++;
        }

        x = a[i];

        while(x > 0)
        {
            if (x % 10 == 0)
            {
                z[i]++;
                x /= 10;
            }
            else
            {
                break;
            }
        }
    }

    if (digits <= m)
    {
        printf("Anna\n");
        return;
    }

    sort(z.begin(), z.end(), greater<int>());

    for (int i = 0; i < n; i += 2)
    {
        digits -= z[i];
    }

    if (digits > m)
    {
        printf("Sasha\n");
    }
    else
    {
        printf("Anna\n");
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


