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
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<char> v (n+1);
    v[0] = 'L';

    for (int i = 1; i <= n; i++) v[i] = s[i-1];

    int d = 0;

    while (true)
    {
        // froze
        if (k < 0)
        {
            printf("NO\n");
            return;
        }

        // on a surface
        if (v[d] == 'L')
        {
            // can jump to bank
            if (n+1-d <= m)
            {
                printf("YES\n");
                return;
            }

            // find furthest surface to jump to
            // if none exist, find furthest water to jump to
            int mxl = d;
            int mxw = d;

            for (int i = d+1; i <= d+m; i++)
            {
                if (v[i] == 'L') mxl = max(mxl, i);
                if (v[i] == 'W') mxw = max(mxw, i);
            }

            if (mxl != d)
            {
                d = mxl;
            }
            else if (mxw != d)
            {
                d = mxw;
                k--;
            }
            else
            {
                // no water or surface to jump to, can't make it
                printf("NO\n");
                return;
            }
        }
        else // in water
        {
            if (d == n) // swim to shore
            {
                printf("YES\n");
                return;
            }

            if (v[d+1] == 'C')
            {
                printf("NO\n");
                return;
            }
            else if (v[d+1] == 'W')
            {
                d++;
                k--;
            }
            else
            {
                d++;
            }
        }
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}


