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
    int x, y; cin >> x >> y;

    int ans = 0;
    int free = 0;
    
    if (y % 2 == 0)
    {
        ans += y/2;
        free = 7*ans;
        x = max(0, x-free);

        ans += (x+14)/15;
    }
    else
    {
        ans += y/2 + 1;
        free = 7*ans + 4;
        x = max(0, x-free);

        ans += (x+14)/15;
    }

    printf("%d\n", ans);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



