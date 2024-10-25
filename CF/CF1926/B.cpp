#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    int n; cin >> n;
    
    vector<vector<bool>> v (n, vector<bool> (n));
    
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '0') {
                v[i][j] = false;
            } else {
                v[i][j] = true;
            }
        }
    }
    
    // The number of 1's we see in the first row that is not blank.
    // If the shape is a square, all non empty rows should have the same number of 1s.
    // Otherwise it's a triangle.
    int side = 0;
    
    for (int i = 0; i < n; i++) {
        int row1s = 0; // number of 1s in this row
        for (int j = 0; j < n; j++) {
            if (v[i][j]) row1s++;
        }
        
        if (side == 0) {
            side = row1s;
        } else if (side != row1s && row1s != 0) { // 2 rows have different number of 1s, triangle
            cout << "TRIANGLE" << endl; 
            return;
        }
    }
    
    cout << "SQUARE" << endl; // all rows are empty of have same number of 1s, square
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



