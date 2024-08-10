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
    string s; cin >> s;

    if (s[0] == 'R' || s[1] == 'R' && s[2] == 'M')
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



