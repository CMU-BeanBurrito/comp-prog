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

pair<int, int> from(int n, int r, int c, int rot)
{
    if (rot == 0) return make_pair(r, c);

    if (rot == 1)
    {
        return make_pair(n-c+1, r);
    }

    if (rot == 2) return make_pair(n-r+1, n-c+1);

    if (rot == 3)
    {
        return make_pair(c, n-r+1);
    }

    return make_pair(-1, -1);
}

void solve() {
    int n; cin >> n;

    vector<vector<char>> a (n+1, vector<char> (n+1));

    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = s[j-1];
        }
    }

    vector<vector<char>> b (n+1, vector<char> (n+1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int row = min(i, n-i+1);
            int col = min(j, n-j+1);
            int ops = min(row, col);
            pair<int, int> p = from(n, i, j, ops%4);
            b[i][j] = a[p.first][p.second];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%c", b[i][j]);
        } printf("\n");
    }
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
