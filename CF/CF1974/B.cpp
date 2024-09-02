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

#define MOD 1'000'000'007

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> v;
    vector<bool> seen (26, false);
    map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (!seen[c-'a']) 
        {
            seen[c-'a'] = true;
            v.push_back(c);
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c", v[v.size()-mp[s[i]]-1]);
    } printf("\n");
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



