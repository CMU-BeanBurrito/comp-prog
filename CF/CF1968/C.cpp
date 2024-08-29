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

    vector<int> x (n);

    for (int i = 1; i < n; i++) cin >> x[i];

    vector<int> a (n);

    a[0] = x[1]+1;

    for (int i = 1; i < n-1; i++)
    {
        int y = x[i];

        if (x[i+1] >= y)
        {
            y += (x[i+1]-y)/a[i-1]*a[i-1] + a[i-1];
        }

        a[i] = y;
    }

    a[n-1] = x[n-1];

    for (int num : a)
    {
        printf("%d ", num);
    } printf("\n");
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



