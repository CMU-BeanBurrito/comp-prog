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
    int n, s, m; cin >> n >> s >> m;

    int last = 0; // time when most recent task ended

    bool can = false;

    for (int i = 0; i < n; i++)
    {
        int l, r; cin >> l >> r;

        if (l - last >= s) can = true;

        last = r;
    }

    // shower after final task
    if (m-last >= s) can = true;

    if (can)
    {
        printf("YES\n");
    }
    else 
    {
        printf("NO\n");
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



