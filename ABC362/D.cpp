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

vector<ll> dist (200001, LLONG_MAX);
vector<vector<pair<int, ll>>> g (200001);
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

void dijkstra()
{
    while(!pq.empty())
    {
        pair<ll, int> p = pq.top(); // (dist[u], u)
        pq.pop();

        // is this value of dist updated?
        if (p.first > dist[p.second]) continue;

        int u = p.second;
        for (auto nb : g[u]) // nb is (neighbor of u, cost to go from u to neighbor)
        {
            int v = nb.first;

            if (dist[v] > dist[u]+nb.second)
            {
                dist[v] = dist[u]+nb.second;
                pq.push(make_pair(dist[u]+nb.second, v));
            }
        }
    }
}

void solve()
{
    int n; cin >> n;
    int m; cin >> m;
    
    vector<int> a (200001);
    
    cin >> a[1];
    dist[1] = a[1];
    pq.push(make_pair(dist[1], 1));

    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        pq.push(make_pair(dist[i], i));
    }
    
    for (int i = 1; i <= m; i++)
    {
        int u, v, b; cin >> u >> v >> b;
        g[u].push_back(make_pair(v, b + a[v]));
        g[v].push_back(make_pair(u, b + a[u]));
    }
    
    dijkstra();
    
    for (int i = 2; i <= n; i++)
    {
        printf("%lld ", dist[i]);
    } printf("\n");
    
    // clear global data
    pq = priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>();
    for (int i = 0; i <= n; i++)
    {
        dist[i] = LLONG_MAX;
        g[i].clear();
    }
}

int main()
{
    solve();
    
    return 0;
}