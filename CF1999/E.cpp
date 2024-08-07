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

vector<int> power3; // power3[i] = 3^(i-1), number of operations it takes this number to get to 0

void solve() {
    int l, r; cin >> l >> r;
    int power = 0;

    int ops = 0;
    int x = l;

    while(x > 0)
    {
        ops += 2;
        x /= 3;
        power++;
    }

    for (int i = l+1; i <= r; i++)
    {
        x = i;

        if (x == power3[power+1])
        {
            power++;
            ops += power;
            continue;
        }

        ops += power;

    }

    printf("%d\n", ops);
}

int main() {
    int t; cin >> t;

    power3.push_back(0);
    int x = 1;

    while(x <= 600000)
    {
        power3.push_back(x);
        x *= 3;
    }
    
    while(t--) {
        solve();
    }
    
    return 0;
}



