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

int gcdExt(int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    else
    {
        int x1, y1;
        int gcd = gcdExt(b % a, a, &x1, &y1);

        *x = y1 - (b/a) * x1;
        *y = x1;

        return gcd;
    }
}
int inv (int a, int m) // modular inverse of a mod m
{
    int x, y;
    int g = gcdExt(a, m, &x, &y);

    return (x % m + m) % m;
}

vector<vector<int>> g (200001);
vector<bool> vis (200001, false);

// return true if component is cyclic
// return false if component is acyclic
bool dfs(int u)
{
    vis[u] = true;
    bool deg2 = true; // by this problem's definition of a cycle, no vertex in a cyclic component can have degree 3 or more

    if (g[u].size() != 2) deg2 = false;

    for (auto v : g[u])
    {
        // we will want to search this whole component so we don't come back to it later
        if (!vis[v]) deg2 &= dfs(v);
    }

    return deg2;
}

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        if (dfs(i)) ans++;
    }

    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}



