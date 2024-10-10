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
    vector<vector<char>> b (3, vector<char> (3));

    for (int i = 0; i < 3; i++)
    {
        string s; cin >> s;

        for (int j = 0; j < 3; j++)
        {
            b[i][j] = s[j];
        }
    }

    // rows
    for (int i = 0; i < 3; i++)
    {
        if (b[i][0] != '.' && b[i][0] == b[i][1] && b[i][1] == b[i][2])
        {
            printf("%c\n", b[i][0]);
            return;
        }
    }

    // cols
    for (int j = 0; j < 3; j++)
    {
        if (b[0][j] != '.' && b[0][j] == b[1][j] && b[1][j] == b[2][j])
        {
            printf("%c\n", b[0][j]);
            return;
        }
    }

    // diag
    if (b[0][0] != '.' && b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        printf("%c\n", b[0][0]);
        return;
    }

    if (b[0][2] != '.' && b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        printf("%c\n", b[0][2]);
        return;
    }

    printf("DRAW\n");
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
