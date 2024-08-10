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

// return lowest index s.t. a[i] >= key
int bin(vector<ll>& a, ll key)
{
    int l = 0;
    int r = a.size();

    while(l < r)
    {
        int mid = l + (r-l)/2;

        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            r = mid;
        }
        else
        {
            l = mid+1;
        }
    }

    return l;
}

void solve() {
    int n, t; cin >> n >> t;

    string s; cin >> s;

    vector<ll> x (n);
    vector<ll> sl (n);
    vector<ll> pos;
    vector<int> prefcnt (n); // how many ants walking in the positive direction started to the left of this ant (including this ant)

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0') sl[i] = 0;
        if (s[i] == '1') sl[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    vector<pair<ll, int>> pv (n);

    for (int i = 0; i < n; i++)
    {
        pv[i].first = x[i];
        pv[i].second = sl[i];
    }

    sort(pv.begin(), pv.end());

    for (int i = 0; i < n; i++)
    {
        x[i] = pv[i].first;
        sl[i] = pv[i].second;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        if (sl[i] == 0)
        {
            x[i] -= 2*t;
            if (i == 0)
            {
                prefcnt[i] = 0;
            }
            else
            {
                prefcnt[i] = prefcnt[i-1];
            }
        }
        else
        {
            pos.push_back(x[i]);
            if (i == 0)
            {
                prefcnt[i] = 1;
            }
            else
            {
                prefcnt[i] = prefcnt[i-1] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (sl[i] == 0)
        {
            int end = bin(pos, x[i]);
            ans += prefcnt[i]-end;
        }
    }

    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}



