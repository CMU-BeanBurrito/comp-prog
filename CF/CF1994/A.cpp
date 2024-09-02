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

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> a (n, vector<int> (m));
    vector<vector<int>> b (n, vector<int> (m));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    if (n == 1 && m == 1)
    {
        printf("-1\n");
        return;
    }

    if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", a[(i+1)%n][0]);
        }

        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][(j+1)%m]);
        } printf("\n");
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



