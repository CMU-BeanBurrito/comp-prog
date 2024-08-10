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
    int r, g, b; cin >> r >> g >> b;
    string c; cin >> c;
    
    int ans;
    
    if (c == "Red")
    {
        ans = min(g, b);
    }
    else if (c == "Green")
    {
        ans = min(r, b);
    }
    else
    {
        ans = min(r, g);
    }
    
    printf("%d\n", ans);
}

int main() {
    solve();
    
    return 0;
}



