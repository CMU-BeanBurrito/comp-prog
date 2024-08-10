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
    int n, x, y; cin >> n >> x >> y;

    x--; y--; // to 0 indexing

    vector<int> v (n);

    v[y] = 1;
    v[x] = 1;
    for (int i = y-1; i >= 0; i--) v[i] = -1*v[i+1];
    for (int i= x+1; i < n; i++) v[i] = -1*v[i-1];
    for (int i = y+1; i < x; i++) v[i] = 1;
    
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



