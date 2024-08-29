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

    printf("1 1\n");
    printf("1 2\n");

    for (int i = 3; i <= n; i++)
    {
        printf("%d %d\n", i, i);
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



