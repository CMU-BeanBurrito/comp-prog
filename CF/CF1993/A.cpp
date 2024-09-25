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

    string s; cin >> s;

    map<char, int> mp;

    for (int i = 0; i < 4*n; i++)
    {
        mp[s[i]]++;
    }

    int ans = 0;

    for (auto p : mp)
    {
        if (p.first == '?') continue;
        ans += min(p.second, n);
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



