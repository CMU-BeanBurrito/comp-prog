#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

int MAXN = 2000002;
vector<int> v (MAXN, 0);

void solve() {
    int n; cin >> n;
    
    cout << v[n] << endl;
}

int main() {
    int t; cin >> t;
    
    for (int i = 1; i <= MAXN; i++) {
        int x = i;
        v[x] = v[x-1];
        while(x > 0) {
            v[i] += x%10;
            x = x/10;
        }
    }
    
    while(t--) {
        solve();
    }
    
    return 0;
}




