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
    int l = 2;
    int r = 999;

    bool found = false;
    int ans = 0;

    while(!found)
    {
        int mid = (l+r)/2;

        cout << "? " << 1 << " " << mid << endl;

        int x; cin >> x;

        if (x != mid)
        {
            r = mid;
        }
        else
        {
            l = mid+1;
        }

        if (l == r)
        {
            found = true;
            ans = l;
        }
    }

    cout << "! " << ans << endl;
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



