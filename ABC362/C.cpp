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
    
    vector<pair<int, int>> a (n);
    vector<int> ans (n);
    
    ll lsum = 0;
    ll rsum = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
        ans[i] = a[i].first;
        lsum += a[i].first;
        rsum += a[i].second;
    }
    
    if (lsum > 0 || rsum < 0)
    {
        printf("No\n");
        return;
    }
    
    printf("Yes\n");
    
    for (int i = 0; i < n; i++)
    {
        if (lsum == 0) break;
        ll incr = min(1LL*a[i].second-ans[i], abs(lsum));
        ans[i] += incr;
        lsum += incr;
    }
    
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    solve();
    
    return 0;
}



