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

    vector<int> a (n);
    vector<int> b (n, 0);
    vector<int> freq (n+1, 0);

    ll sum = 0;
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        freq[a[i]]++;
        if (a[i] > mx && freq[a[i]] > 1) mx = a[i];

        b[i] = mx;
    }

    mx = 0;
    freq = vector<int> (n+1, 0);

    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
        sum += a[i];
        freq[a[i]]++;
        if (a[i] > mx && freq[a[i]] > 1) mx = a[i];
        b[i] = mx;
    }

    for (int i = 0; i < n; i++)
    {
        sum += 1LL*b[i]*(n-i);
    }

    printf("%lld\n", sum);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



