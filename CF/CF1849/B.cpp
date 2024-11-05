#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
   
    vector<int> v (n);
    vector<pair<int, int>> p (n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    
    for (int i = 0; i < n; i++) {
        int ord = (v[i]%k);
        if (ord != 0) ord = k-ord;
        p[i].first = ord;
        p[i].second = i+1;
    }
    
    sort(p.begin(), p.end());
    
    
    for (int i = 0; i < n; i++) {
        cout << p[i].second << " ";
    } cout << endl;
    
    
}

int main()
{
    int numc;
    cin >> numc;
    
    while(numc--) {
        solve();
    }
    
    return 0;
}
