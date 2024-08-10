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
    int n, k; cin >> n >> k;

    if (n == 1)
    {
        printf("0\n");
    }
    else
    {
        // can just split off k-1 1s each operation
        printf("%d\n", (n+k-3)/(k-1));
    }

}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



