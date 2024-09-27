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
    vector<ll> v (n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int even = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0) even++;
    }

    if (even == 0 || even == n)
    {
        printf("0\n");
        return;
    }

    // find largest odd, try to convert is ascending order or get the largest even asap

    ll odd = 1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 1) odd = max(odd, v[i]);
    }

    sort(v.begin(), v.end());

    int ops = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            if (v[i] < odd)
            {
                ops++;
                odd += v[i];
            }
            else // if we find an even that is too large to convert after taking the smallest ones, just go to the largest one
            {
                ops += 2;
                odd += 1000000000000;
            }
        }
    }
    
    printf("%d\n", ops);
}   

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



