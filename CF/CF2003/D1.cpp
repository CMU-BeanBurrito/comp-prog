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

int mex(vector<int> &v, int start)
{
    int mn = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (mn == start) mn++;

        if (v[i] == mn)
        {
            mn++;
        }
        else if (v[i] > mn)
        {
            return mn;
        }
    }

    if (mn == start) mn++;

    return mn;
}

ll gauss(ll n)
{
    return 1LL*((n)*(n+1))/2;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> a (n);

    for (int i = 0; i < n; i++)
    {
        int l; cin >> l;

        for (int j = 0; j < l; j++)
        {
            int x; cin >> x;
            a[i].push_back(x);
        }

        sort(a[i].begin(), a[i].end());
    }

    int best = 0;

    for (int i = 0; i < n; i++)
    {
        int mex1 = mex(a[i], -1);
        int mex2 = mex(a[i], mex1);
        best = max(best, mex2);
    }

    ll ans = 0;

    if (m <= best)
    {
        ans = 1LL*(m+1)*best;
    }
    else
    {
        ans = 1LL*(best+1)*best;
        ans += gauss(m)-gauss(best);
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



