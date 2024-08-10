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
    ll n; cin >> n;

    ll ncpy = n;
    int bits = 0;

    while(ncpy > 0)
    {
        if (ncpy % 2 == 1) bits++;
        ncpy  = ncpy >> 1;
    }

    // sequence length is number of bits in n that are 1
    // unless only 1 bit is 1
    if (bits == 1)
    {
        printf("%d\n", 1);
        printf("%lld\n", n);
        return;
    }
    else 
    {
        printf("%d\n", bits+1);
    }

    // sequence is every number that is the same as n, but with exactly one 1 bit changed to a 0, there are "bits" distinct nubmers like this
    // end sequence with n itself, so bits+1 is the sequence length

    ll bit = 1LL << 62; // bit63 is the sign bit

    while(bit > 0)
    {
        ll x = ~bit & n;
        if (x != n)
        {
            printf("%lld ", x);
        }

        bit = bit >> 1;
    }

    printf("%lld\n", n);


}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



