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
    ll n, m; cin >> n >> m;

    vector<int> a (n);

    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum <= m)
    {
        printf("infinite\n");
        return;
    }

    sort(a.begin(), a.end());

    vector<ll> pref (n);

    pref[0] = a[0];

    for (int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];

    int ub = -1;
    for (int i = 0; i < n; i++)
    {
        // for elements that are <= x, sub is e
        // elements after elements, sub is x

        if (pref[i] + a[i]*(n-i-1) > m)
        {
            ub = i;
            break;
        }
    }

    // ub is an index. x is strictly less than the element at this index in a
    // but x is greater than or equal to the element a[ub-1]

    ll excess = pref[ub] + a[ub]*(n-ub-1) - m;

    ll x = a[ub] - ((excess+n-ub-1) / (n-ub));

    if (x < 0) x = 0;

    printf("%lld\n", x);
}

int main() {
    solve();
    return 0;
}



