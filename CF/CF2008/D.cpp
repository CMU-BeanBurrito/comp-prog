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
    int n; cin >> n;

    vector<bool> vis (n+1, false);
    vector<int> group (n+1);
    vector<int> gsize (n+1, 0);
    vector<int> a (n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    string s; cin >> s;

    int gp = 1;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;

        while(!vis[i])
        {
            vis[i] = true;
            group[i] = gp;
            if (s[i-1] == '0')
            {
                gsize[gp]++;
            }

            i = a[i];
        }

        gp++;
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", gsize[group[i]]);
    } printf("\n");
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



