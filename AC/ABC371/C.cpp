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

int gcdExt(int a, int b, int* x, int* y);
int inv (int a, int m);

void solve() {
    int n; cin >> n;

    int mg; cin >> mg;
    vector<vector<bool>> g (n+1, vector<bool>(n+1, false));

    for (int i = 1; i <= mg; i++)
    {
        int u, v; cin >> u >> v;
        g[u][v] = true;
        g[v][u] = true;
    }

    int mh; cin >> mh;
    vector<vector<bool>> h (n+1, vector<bool>(n+1, false));

    for (int i = 1; i <= mh; i++)
    {
        int a, b; cin >> a >> b;
        h[a][b] = true;
        h[b][a] = true;
    }

    vector<vector<int>> a (n+1, vector<int> (n+1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    int best = INT_MAX;

    vector<int> p;

    for (int i = 1; i <= n; i++) p.push_back(i);

    while(next_permutation(p.begin(), p.end()))
    {
        int cost = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;

                if (g[i][j])
                {
                    if (!h[p[i-1]][p[j-1]])
                    {
                        cost += a[min(p[i-1], p[j-1])][max(p[i-1], p[j-1])];
                    }
                }
                else
                {
                    if (h[p[i-1]][p[j-1]])
                    {
                        cost += a[min(p[i-1], p[j-1])][max(p[i-1], p[j-1])];
                    }
                }
            }
        }
        cost /= 2;
        best = min(best, cost);
    }

    if (best == INT_MAX) // no edges in graph
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", best);
    }
}

int main() {
    solve();
    return 0;
}

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


