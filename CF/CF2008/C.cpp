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

int gauss(int n)
{
    return n * (n+1) / 2;
}

void solve() {
    int l, r; cin >> l >> r;

    int left = 0;
    int right = 44721;

    while(left < right)
    {
        int mid = left + (right-left)/2;

        if (gauss(mid) == r-l)
        {
            printf("%d\n", mid+1);
            return;
        }
        else if (gauss(mid) > r-l)
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }
    }

    printf("%d\n", left);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



