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
    int n; string s;
    cin >> n; cin >> s;

    vector<char> t (n);

    map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }

    vector<pair<int, char>> pairs;

    for (auto p : mp)
    {
        pairs.push_back(make_pair(p.second, p.first));
    }

    sort(pairs.begin(), pairs.end(), greater<pair<int, char>>());

    int idx = 0;

    for (int i = 0; i < n; i += 2)
    {
        if (pairs[idx].first == 0) idx++;

        t[i] = pairs[idx].second;
        pairs[idx].first--;
    }

    for (int i = 1; i < n; i += 2)
    {
        if (pairs[idx].first == 0) idx++;

        t[i] = pairs[idx].second;
        pairs[idx].first--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c", t[i]);
    } printf("\n");
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



