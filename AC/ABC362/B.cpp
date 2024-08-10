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
    int xa, ya; cin >> xa >> ya;
    int xb, yb; cin >> xb >> yb;
    int xc, yc; cin >> xc >> yc;
    
    // take the 3 slopes, see if any are perpendicular
    
    int riseab = yb-ya;
    int runab = xb-xa;
    
    int risebc = yc-yb;
    int runbc = xc-xb;
    
    int riseca = ya-yc;
    int runca = xa-xc;
    
    if (runab == 0 || runbc == 0 || runca == 0)
    {
        if (riseab == 0 || risebc == 0 || riseca == 0)
        {
            printf("Yes\n");
            return;
        }
    }
    
    bool ans = false;
    
    if (runab*runbc == -1*riseab*risebc)
    {
        ans = true;
    }
    else if (runbc*runca == -1*risebc*riseca)
    {
        ans = true;
    }
    else if (runca*runab == -1*riseca*riseab)
    {
        ans = true;
    }
    
    if (ans)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

int main() {
    solve();
    
    return 0;
}



