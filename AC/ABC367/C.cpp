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
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int n, k;
int r[8];
int a[8];

void solve(int lv) {
    if (lv == n) // we have a fully constructed array
    {
        int sum = 0; // sum
        for (int i = 0; i < n; i++) sum += a[i];
        if (sum % k == 0) // is it valid?
        {
            for (int i = 0; i < n; i++) // print it
            {
                printf("%d ", a[i]);
            } printf("\n");
        }
    }
    else
    {
        // iterate through options for this index
        for (int i = 1; i <= r[lv]; i++)
        {
            a[lv] = i;
            solve(lv+1); // move to next index
        }
    }
    
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> r[i];
    solve(0);
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

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a%b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
