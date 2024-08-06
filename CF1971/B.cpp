/*
    Author: BeanBurrito
*/

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

#define MOD 1000000007

void solve() {
    string s; cin >> s;
    
    /* 
    
    Strategy: compare each character to the first character.
    If they are all the same, answer is NO.
    
    Otherwise, when we find a character that is different from s[0], move this different character
    to the front, then print out the rest of the string while skipping this character.
    
    */
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[0]) { // found different char, answer is YES
            cout << "YES" << endl;
            
            // move s[i] to the front
            cout << s[i];
            for (int j = 0; j < s.length(); j++) {
                if (i == j) continue;
                cout << s[j];
            }
            
            cout << endl;
            return;
        }
    }
    
    // all chars are the same, answer is NO
    cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



