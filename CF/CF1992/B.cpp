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
    int n, k; cin >> n >> k;

    vector<int> a (k);

    for (int i = 0; i < k; i++) cin >> a[i];

    int mx = 0;
    int cuts = 0;

    for (int i = 0; i < k; i++)
    {
        cuts += a[i]-1;
        mx = max(mx, a[i]);
    }

    // we aren't cutting this piece up
    cuts -= mx-1;

    // merge all pieces of length 1 onto largest piece
    cuts += (n-mx);

    printf("%d\n", cuts);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



