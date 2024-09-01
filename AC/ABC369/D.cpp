/*
    Author: BeanBurrito
*/

#include <cstdio>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long; 

#define MOD 1'000'000'007

void solve() {
    int n; cin >> n;

    vector<int> a (n+1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<ll>> dp (2, vector<ll> (n+1, 0LL));

    dp[0][0] = 0LL;
    dp[1][0] = LLONG_MIN;

    for (int i = 1; i <= n; i++)
    {
        /**
         * 3 options, "mode" refers to 1x exp (0) or 2x exp (1)
         * 1) keep what we have currently (dp[mode][i]) 
         * 2) let the current monster go (dp[mode][i-1])
         * 3) defeat the current monster and switch modes (dp[!mode][i-1] + exp)
         */
        dp[0][i] = max(dp[1][i-1] + 2*a[i], max(dp[0][i], dp[0][i-1]));
        dp[1][i] = max(dp[0][i-1] +   a[i], max(dp[1][i], dp[1][i-1]));
    }

    printf("%lld\n", max(dp[0][n], dp[1][n]));
}

int main() {
    solve();
    return 0;
}



