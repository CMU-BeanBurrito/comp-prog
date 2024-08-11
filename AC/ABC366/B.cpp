/*
    Author: BeanBurrito
*/

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

    vector<vector<char>> sv (n);

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            sv[i].push_back(s[j]);
        }
    }

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, (int)sv[i].size());

        int add = mx - sv[i].size();

        for (int j = 0; j < add; j++)
        {
            sv[i].push_back('*');
        }
    }

    for (int j = 0; j < sv[n-1].size(); j++)
    {
        for (int i = n-1; i >= 0; i--)
        {
            if (j >= sv[i].size()) break;
            printf("%c", sv[i][j]);
        } printf("\n");
    }
}

int main() {
    solve();
    return 0;
}



