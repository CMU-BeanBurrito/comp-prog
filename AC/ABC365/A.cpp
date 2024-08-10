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

void solve() {
    int y; cin >> y;

    if (y % 4 != 0)
    {
        printf("365\n");
    }
    else if (y % 100 != 0)
    {
        printf("366\n");
    }
    else if (y % 400 != 0)
    {
        printf("365\n");
    }
    else
    {
        printf("366\n");
    }
}

int main() {
    solve();
    return 0;
}



