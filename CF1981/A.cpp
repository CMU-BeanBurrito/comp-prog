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

vector<bool> erat (200001, true);

void sieve()
{
    erat[0] = false;
    erat[1] = false;
    erat[2] = true;

    for (int i = 2; i*i <= 200000; i++)
    {
        if (!erat[i]) continue;

        for (int j = 2*i; j <= 200000; j+=i)
        {
            erat[i] = false;
        }
    }
}

void solve() {
    int l, r; cin >> l >> r;

    int mxpw2 = 1;
    int score = 0;

    while(mxpw2*2 <= r)
    {
        mxpw2 *= 2;
        score++;
    }

    printf("%d\n", score);
}

int main() {
    int t; cin >> t;

    sieve();
    
    while(t--) {
        solve();
    }
    
    return 0;
}



