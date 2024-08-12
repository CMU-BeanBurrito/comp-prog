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

    vector<int> x (n);
    vector<int> y (n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    
    int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;

    // shortest path to the target squared
    ll dist2 = 1LL*abs(xt-xs)*abs(xt-xs) + 1LL*abs(yt-ys)*abs(yt-ys);

    for (int i = 0; i < n; i++)
    {
        // distance to the target squared for this circle
        ll cdist2 = 1LL*abs(xt-x[i])*abs(xt-x[i]) + 1LL*abs(yt-y[i])*abs(yt-y[i]);

        if (cdist2 <= dist2)
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



