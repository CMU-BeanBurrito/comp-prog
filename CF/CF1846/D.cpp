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

void solve() {
    ll n, d, h; cin >> n >> d >> h;

    vector<ll> y (n);
    vector<ll> u (n, h);

    for (int i = 0; i < n; i++) cin >> y[i];

    for (int i = 0; i < n-1; i++)
    {
        if (y[i+1] - y[i] < h) u[i] = y[i+1]-y[i];
    }

    double ans = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (u[i] == h)
        {
            ans += d*h/2.0;
            continue;
        }

        double full = d*h/2.0;

        double covh = h-u[i]; // height of covered area
        double covd = d*(h-u[i])/((double)h); // base of covered area

        full -= (covh*covd/2.0);

        ans += full;
    }

    printf("%.6f\n", ans);
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

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a%b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}