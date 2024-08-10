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
    int n, k, x;
    scanf("%d %d %d\n", &n, &k, &x);

    vector<int> a (n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", a[i]);
    }

    printf("%d ", x);

    for (int i = k; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int main() {
    solve();
    return 0;
}



