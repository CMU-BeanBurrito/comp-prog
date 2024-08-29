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

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b%a, a);
    }
}

void solve() {
    int x; cin >> x;

    int best = 1;

    for (int y = 2; y < x; y++)
    {
        if (gcd(x, y) + y > gcd(x, best) + best)
        {
            best = y;
        }
    }

    printf("%d\n", best);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



