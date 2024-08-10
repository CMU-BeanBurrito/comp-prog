/*
    Author: BeanBurrito
*/

#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long; 

void solve() {
    string s; cin >> s;
    int n = s.length();
    int insert = n-1;
 
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == s[i+1])
        {
            insert = i;
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
        if (i == insert)
        {
            if (s[insert] == 'a')
            {
                cout << 'b';
            }
            else
            {
                cout << 'a';
            }
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



