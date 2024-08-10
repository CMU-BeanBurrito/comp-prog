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
    vector<int> w (n);

    ll ans = 0;

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        int b; cin >> b;
        mp[b].push_back(i);
    }

    for (int i = 0; i < n; i++) cin >> w[i];

    for (auto p : mp)
    {
        ll tot = 0;
        int wtmx = 0;

        for (int item : p.second)
        {
            wtmx = max(wtmx, w[item]);
            tot += w[item];
        }

        ans += tot-wtmx;
    }

    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}



