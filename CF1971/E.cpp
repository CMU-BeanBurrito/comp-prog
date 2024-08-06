#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    ll n, k, q; cin >> n >> k >> q;
    
    vector<int> a (k);
    vector<int> b (k);
    
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    
    while(q--) {
        ll x; cin >> x;
        
        if (x <= a[0]) { // if the query is part of the first segment, no need to search
            cout << b[0]*x/a[0] << " ";
            continue;
        }
        
        if (x == a[k-1]) { // if the query is the final destination, no need to search
            cout << b[k-1] << " ";
            continue;
        }
        
        int l = 0;
        int r = k-1;
        bool done = false;
        
        while(l+1 < r) { // try to find the interval that contains x 
            int mid = l + (r-l)/2;
            
            if (a[mid] == x) { // x is exactly this point, so we know the exact time already
                cout << b[mid] << " ";
                done = true;
                break;
            } else if (a[mid] < x) { // start of x's interval is at least mid
                l = mid;
            } else { // a[mid] > x, end of x's interval is at most mid
                r = mid;
            }
        }
        
        if (!done) { // interpolate time for this interval
            ll t = (b[r]-b[l])*(x-a[l])/(a[r]-a[l]) + b[l];
            cout << t << " ";
        }
    }
    
    cout << endl;
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}




