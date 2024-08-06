#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    
    // For simplicity (and without loss of generality), make a < b and c < d.
    
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    if (c > d) {
        int tmp = c;
        c = d;
        d = tmp;
    }
    
    /*
    In order for an intersection to exist, exactly one of the endpoints a or b must be
    between c and d. If neither or both are within the interval (c, d), the answer is NO.
    
    If exactly one of a, b is in that interval, the answer is YES.
    */
    
    
    if ((c < a && a < d) ^ (c < b && b < d)) { // use XOR operation to see if one is true and one is false
        cout << "YES" << endl;
        return;
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




