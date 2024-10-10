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
    int n, x; cin >> n >> x;

    vector<int> a (n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> mod (x, vector<int>());
    
    for (int i = 0; i < n; i++) mod[a[i]%x].push_back(a[i]);
    for (int i = 0; i < x; i++) sort(mod[i].begin(), mod[i].end());

    int mn = n;

    for (int i = 0; i < x; i++)
    {
        if (mod[i].size() == 0)
        {
            mn = min(mn, i);
            continue;
        }

        int lowest = i;

        for (int j = 0; j < mod[i].size(); j++)
        {
            if (mod[i][j] > i + j*x)
            {
                mn = min(mn, i + j*x);
                lowest += x;
                break;
            }
        }

        mn = min(mn, lowest);
    }

    printf("%d\n", mn);
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
