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
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

void solve() {
    int n, s, t; cin >> n >> s >> t;

    vector<pair<int, int>> start (n);
    vector<pair<int, int>> finish (n);
    int ind[n];
    for (int i = 0; i < n; i++) ind[i] = i;

    for (int i = 0; i < n; i++)
    {
        cin >> start[i].first >> start[i].second >> finish[i].first >> finish[i].second;
    }

    double ans = (double)1e7;
    do
    {
        for (int seq = 0; seq < (1 << n); seq++)
        {
            double clock = 0.0;
            double posx = 0.0;
            double posy = 0.0;

            for (int i = 0; i < n; i++)
            {
                if (!(seq & (1 << i))) // start to finish
                {
                    int x1 = start[ind[i]].first;
                    int y1 = start[ind[i]].second;
                    int x2 = finish[ind[i]].first;
                    int y2 = finish[ind[i]].second;
                    clock += (sqrt((posx-x1)*(posx-x1) + (posy-y1)*(posy-y1)))/(double)s;
                    clock += (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)))/(double)t;
                    posx = x2;
                    posy = y2;
                }
                else // finish to start
                {
                    int x2 = start[ind[i]].first;
                    int y2 = start[ind[i]].second;
                    int x1 = finish[ind[i]].first;
                    int y1 = finish[ind[i]].second;
                    clock += (sqrt((posx-x1)*(posx-x1) + (posy-y1)*(posy-y1)))/(double)s;
                    clock += (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)))/(double)t;
                    posx = x2;
                    posy = y2;
                }
            }

            ans = min(ans, clock);
        }
    }
    while(next_permutation(ind, ind+n));

    printf("%.6f\n", ans);
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

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a%b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
