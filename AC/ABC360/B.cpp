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

#define MOD 998244353

void solve() {
    string s, t; cin >> s >> t;
    int n = s.length();
    int m = t.length();

    for (int w = 1; w < n; w++)
    {
        if (n/w > m) continue;
        if ((n+w-1)/w < m) break;
        for (int c = 0; c < w; c++)
        {
            bool good = true;

            if (m*w+c+1 <= n) // there are more than m cth chars
            {
                continue;
            }

            for (int i = 0; i < m; i++)
            {
                if (s[c+i*w] != t[i])
                {
                    good = false;
                    break;
                }
            }

            if (good)
            {
                printf("Yes\n");
                return;
            }
        }
    }

    printf("No\n");
}

int main() {
    solve();
    return 0;
}



