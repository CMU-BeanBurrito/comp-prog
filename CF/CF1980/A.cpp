#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    int m, n; cin >> n >> m;
    
    string s; cin >> s;

    vector<int> cnt (7);

    for (int i = 0; i < n; i++)
    {
        int idx = s[i] - 'A';
        cnt[idx]++;
    }

    int ans = 0;

    for (int i = 0; i < 7; i++)
    {
        if (cnt[i] < m) ans += (m-cnt[i]);
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



