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

    int left = max(0, n-m);
    int right = n+m;

    int ans = n;

    for (int i = 0; i < 31; i++)
    {
        int bit = 1 << i;

        if ((left % bit) + (right-left) >= bit) ans |= bit;
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



