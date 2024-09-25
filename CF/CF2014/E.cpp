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
ll kadane(vector<int>& a, int n);

vector<vector<pair<int, int>>> g(200001);
vector<bool> horse (200001, false);
vector<ll> marian(200001, LLONG_MAX);
vector<ll> robin(200001, LLONG_MAX);
set<pair<ll, int>> pqm;
set<pair<ll, int>> pqr;

void dfsm(int start, bool ride)
{
    ll t = marian[start];

    for (auto nbr : g[start])
    {
        if (vism[nbr.first] < 2)
        {
            vism[nbr.first]++;
            if (ride)
            {
                marian[nbr.first] = t + nbr.second/2;
                printf("%lld %d\n", nbr.first, marian[nbr.first]);
                dfsm(nbr.first, true);
            }
            else
            {
                marian[nbr.first] = t + nbr.second;
                printf("%lld %d\n", nbr.first, marian[nbr.first]);
                if (horse[nbr.second])
                {
                    dfsm(nbr.first, true);
                }
                else
                {
                    dfsm(nbr.first, false);
                }
            }
        }
    }
}

void dfsr(int start, bool ride)
{
    ll t = robin[start];

    for (auto nbr : g[start])
    {
        if (visr[nbr.first] < 2)
        {
            visr[nbr.first]++;
            if (ride)
            {
                robin[nbr.first] = t + nbr.second/2;
                dfsr(nbr.first, true);
            }
            else
            {
                robin[nbr.first] = t + nbr.second;
                if (horse[nbr.second])
                {
                    dfsr(nbr.first, true);
                }
                else
                {
                    dfsr(nbr.first, false);
                }
            }
        }
    }
}

void dijkm()
{
    int u = *pqm.begin();

    for (auto nbr : g[u])
    {
        marian[nbr.first] = min(marian[nbr.first], marian[u]+)
    }
}

void solve() {
    int n, m, h; cin >> n >> m >> h;

    for (int i = 0; i < h; i++)
    {
        int x; cin >> x;
        horse[x] = true;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    pqm.insert(make_pair(0LL, 1));
    for (int i = 2; i <= n; i++) pqm.push(make_pair(LLONG_MAX, i));

    pqr.insert(make_pair(0LL, N));
    for (int i = 1; i <= n-1; i++) pqr.push(make_pair(LLONG_MAX, i));

    marian[1] = 0;
    dfsm(1, horse[1]);

    robin[n] = 0;
    dfsr(n, horse[n]);

    if (marian[n] == LLONG_MAX)
    {
        printf("-1\n");
        return;
    }

    ll best = LLONG_MAX;

    for (int i = 1; i <= n; i++)
    {
        //printf("%lld %lld\n", marian[i], robin[i]);
        best = max(marian[i], robin[i]);
    }

    printf("%lld\n", best);

    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        marian[i] = LLONG_MAX;
        robin[i] = LLONG_MAX;
        horse[i] = false;
        vism[i] = 0;
        visr[i] = 0;
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
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
ll kadane(vector<int>& a, int n)
{
    ll sum = 0;
    ll best = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum > 0)
        {
            sum += a[i];
        }
        else
        {
            sum = a[i];
        }

        best = max(best, sum);
    }

    return best;
}


