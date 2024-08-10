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
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;

    int games = 0;

    if (a1 > b1 && a2 > b2) // win a1b1, win a2b2
    {
        games += 2;
    }

    if (a2 > b1 && a1 > b2) // win a2b1, win a1b2
    {
        games += 2;
    }

    if (a1 == b1 && a2 > b2) // tie a1b1, win a2b2
    {
        games += 2;
    }

    if (a2 == b1 && a1 > b2) // tie a2b1, win a1b2
    {
        games += 2;
    }

    if (a1 > b1 && a2 == b2)
    {
        games += 2;
    }

    if (a2 > b1 && a1 == b2)
    {
        games += 2;
    }

    printf("%d\n", games);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



