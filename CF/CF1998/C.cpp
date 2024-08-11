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
    int n, k; cin >> n >> k;

    vector<int> a (n);
    vector<int> b (n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> p (n);

    for (int i = 0; i < n; i++)
    {
        p[i].first = a[i];
        p[i].second = b[i];
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++)
    {
        a[i] = p[i].first;
        b[i] = p[i].second;
    }

    int mxmed = a[(n/2)+1];

    int mx1 = 0;
    int mx = 0;
    int mx1idx = -1;
    int mxidx = -1;

    for (int i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            if (a[i] > mx1)
            {
                mx1 = max(mx1, a[i]);
                mx1idx = i;
            }
        }

        if (a[i] > mx)
        {
            mx = a[i];
            mxidx = i;
        }

    }

    ll ans = 0;

    if (mx1idx == -1) k = 0;

    if (mx1 + k > mx)
    {
        ans += (mx1+k);
        a[mx1idx] = 0;
        sort(a.begin(), a.end());
        ans += a[n/2];
    }
    else
    {
        for (int i = n/2; i >= 0; i--)
        {
            if (b[i] == 0) continue;

            int add = min(k, mxmed-a[i]);
            a[i] += add;
            k -= add;

            if (k == 0) break;
        }

        
    }

    printf("%lld\n", ans);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



