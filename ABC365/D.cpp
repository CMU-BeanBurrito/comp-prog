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

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<vector<int>> dp (3, vector<int> (n+1, 0));

    // if no games, can't win any games
    dp[ROCK][0] = 0;
    dp[PAPER][0] = 0;
    dp[SCISSORS][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        char c = s[i-1]; // string is 0 indexed

        if (c == 'R') // Can play rock or paper. Playing rock would be a tie, playing paper would be a win.
        {
            // Play paper and win. Last turn we either played rock or scissors.
            // Take the best one and add a win.
            dp[PAPER][i] = max(dp[ROCK][i-1], dp[SCISSORS][i-1])+1;

            // Play rock and tie. Last turn we either played paper or scissors.
            // Take the best one but don't add a win.
            dp[ROCK][i] = max(dp[PAPER][i-1], dp[SCISSORS][i-1]);
        }
        else if (c == 'P')
        {
            // Play scissors and win. Last turn we either played rock or paper.
            // Take the best one and add a win.
            dp[SCISSORS][i] = max(dp[ROCK][i-1], dp[PAPER][i-1])+1;

            // Play paper and tie. Last turn we either played rock or scissors.
            // take the best one but don't add a win.
            dp[PAPER][i] = max(dp[ROCK][i-1], dp[SCISSORS][i-1]);
        }
        else
        {
            dp[ROCK][i] = max(dp[PAPER][i-1], dp[SCISSORS][i-1])+1;

            dp[SCISSORS][i] = max(dp[ROCK][i-1], dp[PAPER][i-1]);
        }
    }

    printf("%d\n", max(dp[ROCK][n], max(dp[PAPER][n], dp[SCISSORS][n])));
}

int main() {
    solve();
    return 0;
}



