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
    int n, m; cin >> n >> m;

    string a, b; cin >> a >> b;

    int aptr = 0;
    int bptr = 0;

    int k = 0;

    bool good = true;

    while(aptr < n && bptr < m)
    {
        while(b[bptr] != a[aptr] && bptr < m)
        {
            bptr++;
        }

        if (bptr >= m)
        {
            good = false;
            break;
        }

        k++;
        aptr++;
        bptr++;
    }

    printf("%d\n", k);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



