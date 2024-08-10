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

#define MOD 1000000007

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> init (n, vector<int> (m));
    vector<vector<int>> final (n, vector<int> (m));

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
        {
            init[i][j] = (int)s[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
        {
            final[i][j] = (int)s[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int col = 0; // number of cols changed in this row
        for (int j = 0; j < m; j++)
        {
            col += final[i][j]-init[i][j];
        }

        if (col % 3 != 0)
        {
            printf("NO\n");
            return;
        }
    }

    for (int j = 0; j < m; j++)
    {
        int row = 0; // number of rows changed in this col
        for (int i = 0; i < n; i++)
        {
            row += final[i][j]-init[i][j];
        }

        if (row % 3 != 0)
        {
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



