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

bool fn (int l1, int r1, int l2, int r2)
{
    return !(r1 <= l2 || r2 <= l1);
}

void solve() {
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;

    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);

    if (fn(a, d, g, j) && fn(b, e, h, k) && fn(c, f, i, l))
    {
        printf("Yes\n");
        return;
    }

    printf("No\n");
}

int main() {
    solve();
    return 0;
}


