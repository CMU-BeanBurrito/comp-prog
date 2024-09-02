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
    int n, m, k; cin >> n >> m >> k;

    vector<int> p (n);

    for (int i = 0; i < n-m; i++)
    {
        p[i] = n-i;
    }

    for (int i = n-m; i < n; i++)
    {
        p[i] = i-(n-m)+1;
    }

    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



