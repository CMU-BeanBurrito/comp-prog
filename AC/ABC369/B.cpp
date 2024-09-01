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

#define MOD 1'000'000'007

void solve() {
    int n; cin >> n;

    int ans = 0;
    int l = -1;
    int r = -1;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        char h; cin >> h;

        if (h == 'L')
        {
            if (l == -1)
            {
                l = x;
            }
            else
            {
                ans += abs(x-l);
                l = x;
            }
        }
        else
        {
            if (r == -1)
            {
                r = x;
            }
            else
            {
                ans += abs(x-r);
                r = x;
            }
        }
    }

    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}



