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
#define divceil(n, m) (n+m-1)/m

int gcdExt(int a, int b, int* x, int* y);
int inv (int a, int m);
ll kadane(vector<int>& a, int n);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a (2*n);

    for (int i = 0; i < 2*n; i++) cin >> a[i];

    map<int, int> fh; //first half

    // track frequency for first half. we can compute second half frequency from first half.
    for (int i = 0; i < n; i++) fh[a[i]]++;

    vector<int> l;
    vector<int> r;

    for (int i = 1; i <= n; i++)
    {
        if (fh[i] == 2 && l.size() <= 2*k - 2)
        {
            l.push_back(i);
            l.push_back(i);
        }

        if (fh[i] == 0 && r.size() <= 2*k - 2)
        {
            r.push_back(i);
            r.push_back(i);
        }

        if (l.size() == 2*k && r.size() == 2*k) break;
    }

    for (int i = 1; i <= n; i++)
    {
        if (fh[i] == 1 && l.size() <= 2*k - 1 && r.size() <= 2*k - 1)
        {
            l.push_back(i);
            r.push_back(i);
        }

        if (l.size() == 2*k && r.size() == 2*k) break;
    }

    for (int i = 0; i < 2*k; i++)
    {
        printf("%d ", l[i]);
    } printf("\n");

    for (int i = 0; i < 2*k; i++)
    {
        printf("%d ", r[i]);
    } printf("\n");
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
