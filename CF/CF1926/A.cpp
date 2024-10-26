#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    string s; cin >> s;
    
    int a = 0; int b = 0;
    
    for (int i = 0; i < 5; i++) {
        if (s[i] == 'A') {
            a++;
        } else {
            b++;
        }
    }
    
    if (a > b) {
        cout << "A" << endl;
    } else {
        cout << "B" << endl;
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



