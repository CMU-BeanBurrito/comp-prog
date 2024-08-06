#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    string s; cin >> s;
    
    int n = s.length();
    
    /*
    Clearly, we never need to cut a string of consecutive 0s or consecutive 1s.
    
    With our pieces, we need to be able to  construct a string that looks like:
    
    00000000011111111111111.
    
    So, we are allowed to have 1 occurrence of "01", but we can't have any "10"s.
    
    Therefore our strategy is to cut all 01s except 1. And cut all 10s.
    */
    
    int cut01 = 0;
    int cut10 = 0;
    
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == '0' && s[i+1] == '1') {
            cut01++;
        } else if (s[i] == '1' && s[i+1] == '0') {
            cut10++;
        }
    }
    
    if (cut01 > 0) cut01--; // since we are allowed one 01
    
    cout << 1 + cut01 + cut10 << endl; // number of pieces is the number of cuts + 1
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}




