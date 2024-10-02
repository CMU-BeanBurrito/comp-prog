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
    int n; cin >> n;

    vector<vector<int>> h (3, vector<int> (n+1));
    vector<vector<int>> dp (3, vector<int> (n+1));
    
    for (int i = 1; i <= n; i++)
    {
        cin >> h[0][i] >> h[1][i] >> h[2][i];
    }

    dp[0][1] = h[0][1];
    dp[1][1] = h[1][1];
    dp[2][1] = h[2][1];

    for (int i = 2; i <= n; i++)
    {
        int dp10 = dp[1][i-1];
        int dp20 = dp[2][i-1];
        dp[0][i] = max(dp10, dp20) + h[0][i];

        int dp01 = dp[0][i-1];
        int dp21 = dp[2][i-1];
        dp[1][i] = max(dp01, dp21) + h[1][i];

        int dp02 = dp[0][i-1];
        int dp12 = dp[1][i-1];
        dp[2][i] = max(dp02, dp12) + h[2][i];
    }

    printf("%d\n", max(dp[0][n], max(dp[1][n], dp[2][n])));
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


