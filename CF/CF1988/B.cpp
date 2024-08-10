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
    int n; cin >> n;
    string s; cin >> s;

    vector<int> w;

    if (s[0] == '0')
    {
        w.push_back(0);
    }
    else
    {
        w.push_back(1);
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1')
        {
            w.push_back(1);
        }
        else if (s[i-1] == '1')
        {
            w.push_back(0);
        }
    }

    int wn = w.size();
    int c1 = 0;

    for (int i = 0; i < wn; i++)
    {
        if (w[i] == 1) c1++;
    }

    if (c1 > wn/2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



