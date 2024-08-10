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
    int n; cin >> n;

    vector<int> a (n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mx = 0;
    int mx2 = 0;

    if (a[0] > a[1])
    {
        mx = 0;
        mx2 = 1;
    }
    else
    {
        mx2 = 0;
        mx = 1;
    }

    for (int i = 2; i < n; i++)
    {
        if (a[i] > a[mx])
        {
            mx2 = mx;
            mx = i;
        }
        else if (a[i] > a[mx2])
        {
            mx2 = i;
        }
    }

    // 1 indexing
    printf("%d\n", mx2+1);
}

int main() {
    solve();
    return 0;
}



