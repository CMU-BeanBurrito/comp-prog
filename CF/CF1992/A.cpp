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
    int a, b, c; cin >> a >> b >> c;

    for (int i = 0; i < 5; i++)
    {
        if (a <= b && a <= c)
        {
            a++;
        }
        else if (b <= a && b <= c)
        {
            b++;
        }
        else if (c <= a && c <= b)
        {
            c++;
        }
    }

    printf("%d\n", a*b*c);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



