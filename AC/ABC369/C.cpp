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

ll nc2(int n)
{
    return 1LL * n * (n-1) / 2;
}

void solve() {
    int n; cin >> n;

    vector<int> runs;
    vector<int> a (n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        printf("1\n");
        return;
    }

    int diff = a[1]-a[0];
    int run = 1;

    for (int i = 2; i < n; i++)
    {
        int diff2 = a[i]-a[i-1];

        if (diff == diff2)
        {
            run++;
        }
        else
        {
            runs.push_back(run);
            diff = diff2;
            run = 1;
        }
    }

    runs.push_back(run);

    ll ans = n;

    for (int r : runs)
    {
        ans += nc2(r+1);
    }

    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}



