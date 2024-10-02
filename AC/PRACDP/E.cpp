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
#define VSUM_MAX 100'000
#define W_MAX 1'000'000'001

int gcdExt(int a, int b, int* x, int* y);
int inv (int a, int m);
ll kadane(vector<int>& a, int n);

void solve() {
    int n, wt; cin >> n >> wt;

    vector<int> w (n+1);
    vector<int> v (n+1);

    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    // dp[i][j] is the lowest total weight with
    // which we can get j value from the first i items
    // max value is 100k, 100 items, each 1k value
    vector<vector<int>> dp (n+1, vector<int> (VSUM_MAX+1, W_MAX+1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= VSUM_MAX; j++)
        {
            if (j == 0) dp[i][j] = 0; // don't need any weight to get to 0 value
            if (i == 0) continue;

            
            if (j >= v[i]) // item does not exceed the value we are going for, consider take
            {
                int take = w[i] + dp[i-1][j-v[i]];
                int notake = dp[i-1][j];
                dp[i][j] = min(notake, take);
            }
            else // item exceeds target value, do not take
            {
                dp[i][j] = dp[i-1][j]; 
            }

            // if we took an item with value greater than the target, we would go out of bounds
            // also, we will end up taking it later when its value is the target
        }
    }

    int best = 0;
    for (int j = 0; j <= VSUM_MAX; j++)
    {
        if (dp[n][j] <= wt) best = max(best, j);
    }

    printf("%d\n", best);
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


