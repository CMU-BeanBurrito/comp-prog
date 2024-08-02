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
    int n, k; scanf("%d %d", &n, &k);

    vector<int> a (n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    if (k == n-1)
    {
        printf("0\n");
        return;
    }

    sort(a.begin(), a.end());

    int best = INT_MAX;

    for (int i = 0; i <= k; i++)
    {
        best = min(best, a[n-k-1+i]-a[i]);
    }

    printf("%d\n", best);
}

int main() {
    solve();
    return 0;
}