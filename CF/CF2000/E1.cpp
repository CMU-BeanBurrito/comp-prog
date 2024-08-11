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

vector<bool> can (200002, false);
vector<ll> pref (200002);
vector<pair<int, int>> p (200002);
vector<int> a (200002);

bool psrt(const pair<int, int>& p1, const pair<int, int>& p2)
{
    if (p1.first > p2.first)
    {
        return true;
    }
    else if (p2.first > p1.first)
    {
        return false;
    }
    else
    {
        return p1.second < p2.second;
    }
}

void check(int l, int r, int mx)
{
    if (pref[r]-pref[l-1] >= mx)
    {
        
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            can[i] = false;
        }
    }
}

void solve() {
    int n, x; cin >> n >> x;

    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    a[0] = mx;
    a[n+1] = mx;

    pref[0]= mx;
    for (int i = 1; i < n+2; i++)
    {
        pref[i] = pref[i-1] + a[i];
    }

    for (int i = 0; i < n; i++)
    {
        p[i].first = a[i];
        p[i].second = i;
    }

    sort(p.begin(), p.end(), psrt);

    int submx = mx;

    for (int i = 1; i < n+2; i++)
    {
        if (p[i].first != submx) break;
        check(a, p[0].second+1, p[i].second-1, submx);
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



