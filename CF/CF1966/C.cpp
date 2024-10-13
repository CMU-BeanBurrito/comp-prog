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
    int n; cin >> n;

    map<int, int> mp;
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
        mx = max(mx, x);
    }

    int mex = 1;

    for (int i = 1; i <= n+1; i++)
    {
        if (mp[mex] == 0) break;
        mex++;
    }

    if (mex > mx) // case where piles are 1, 2, 3...mx
    {
        if (mx % 2 == 0) // Bob eliminates the last pile (when mx is the last pile and is 1), he wins
        {
            printf("Bob\n");
        }
        else
        {
            printf("Alice\n");
        }
    }
    else
    {
        if (mex % 2 == 1) // Alice's turn once smallest pile is > 1, she wins
        {
            printf("Alice\n");
        }
        else
        {
            printf("Bob\n");
        }
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

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a%b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
