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
    int n, m; cin >> n >> m;

    vector<vector<char>> board (n, vector<char> (m));

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = s[j];
        }
    }

    // need a cell in the first and last row, and a cell in the last row and column
    vector<bool> have (8, false);
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'W') have[0] = true;
        if (board[i][m-1] == 'W') have[1] = true;
        if (board[i][0] == 'B') have[4] = true;
        if (board[i][m-1] == 'B') have[5] = true;
    }

    for (int j = 0; j < m; j++)
    {
        if (board[0][j] == 'W') have[2] = true;
        if (board[n-1][j] == 'W') have[3] = true;
        if (board[0][j] == 'B') have[6] = true;
        if (board[n-1][j] == 'B') have[7] = true;
    }

    if (have[0] && have[1] && have[2] && have[3])
    {
        printf("YES\n");
        return;
    }

    if (have[4] && have[5] && have[6] && have[7])
    {
        printf("YES\n");
        return;
    }

    printf("NO\n");
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
