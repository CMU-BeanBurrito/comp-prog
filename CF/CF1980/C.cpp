#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    int n, m;

    map<int, int> need;
    map<int, int> have;

    cin >> n;
    vector<int> a (n);
    vector<int> b (n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != a[i]) need[b[i]]++;
    }
    
    cin >> m;
    vector<int> d (m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
        have[d[i]]++;
    }

    for (auto p : need) {
        if (p.second > have[p.first]) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == d[m-1]) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



