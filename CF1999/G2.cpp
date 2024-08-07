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
        int mid1 = l + (r-l)/3;
        int mid2 = l + 2*(r-l)/3;

        cout << "? " << mid1 << " " << mid2 << endl;

        int x; cin >> x;

        if (x == (mid1+1)*(mid2+1))
        {
            r = mid1;
        }
        else if (x == (mid1)*(mid2+1))
        {
            l = mid1+1;
            r = mid2;
        }
        else if (x == (mid1)*(mid2))
        {
            l = mid2+1;
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



