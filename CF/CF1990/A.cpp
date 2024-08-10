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
    int n; cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }

   for (auto p : mp)
    {
        if (p.second % 2 == 1)
        {
            printf("YES\n");
            return;
        }
    }

   printf("NO\n");
    
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



