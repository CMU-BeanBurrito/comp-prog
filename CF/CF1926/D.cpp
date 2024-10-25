#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    int n; cin >> n;
    
    map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    
    int ans = 0;
    
    for (auto p : mp) {
        ans += max(p.second, mp[(~p.first) & ~(1 << 31)]);
        mp[p.first] = 0;
        mp[(~p.first) & ~(1 << 31)] = 0;
    }
    
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}




