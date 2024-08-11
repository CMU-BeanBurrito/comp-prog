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
    int xc, yc, k; cin >> xc >> yc >> k;

    if (k % 2 == 1)
    {
        printf("%d %d\n", xc, yc);
        k--;
    }

    for (int i = 0; i < k; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d %d\n", xc, yc-(i+2)/2);
        }
        else
        {
            printf("%d %d\n", xc, yc+(i+1)/2);
        }
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



