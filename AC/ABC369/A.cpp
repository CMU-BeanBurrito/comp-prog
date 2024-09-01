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
    int a, b; cin >> a >> b;

    int diff = abs(a-b);

    if (diff == 0)
    {
        printf("1\n");
    }
    else if (diff % 2 == 1)
    {
        printf("2\n");
    }
    else
    {
        printf("3\n");
    }
}

int main() {
    solve();
    return 0;
}



