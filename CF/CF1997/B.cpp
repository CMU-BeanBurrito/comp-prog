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
    int n; cin >> n;
 
    vector<vector<int>> v (2, vector<int> (n));
 
    for (int i = 0; i < 2; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '.') v[i][j] = 0;
            if (s[j] == 'x') v[i][j] = 1;
        }
    }
    
    int count = 0;
 
    for (int i = 1; i < n-1; i++)
    {
        if (!v[0][i-1] && v[1][i-1] && !v[0][i] && !v[1][i] && !v[0][i+1] && v[1][i+1])
        {
            count++;
        }
        
        if (v[0][i-1] && !v[1][i-1] && !v[0][i] && !v[1][i] && v[0][i+1] && !v[1][i+1])
        {
            count++;
        }
    }
    
    cout << count << endl;
}
 
int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}
 



