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
#define divceil(n, m) (n+m-1)/m

int gcdExt(int a, int b, int* x, int* y);
int inv (int a, int m);
ll kadane(vector<int>& a, int n);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

void solve() {
    ll n, x; cin >> n >> x;

    vector<int> a (n);
    vector<int> p (n);
    vector<int> b (n);
    vector<int> q (n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
        if (a[i]*q[i] < b[i]*p[i])
        {
            // make a[i] the higher value (production/yen) for simplicity
            swap(a[i], b[i]);
            swap(p[i], q[i]);
        }
    }

    ll right = INT_MAX; // at most, we can make 1E9 since machines can make 100 items/1 yen, with budget of 1E7 yen
    ll left = 0;

    while(left < right-1)
    {
        ll mid = (left+right)/2;
        ll budget = x;
        bool good = true;


        for (int i = 0; i < n; i++)
        {
            if (budget < 0)
            {
                good = false;
                break;
            }

            ll best = LLONG_MAX; // best possible cost for this step

            /**
             * Never buy 100 or more B machines.
             * At least some of that productivity could have been acquried via buying more A machines for cheaper.
             */
            for (int x = 0; x < 100; x++)
            {
                ll cost = 0;
                ll need = mid - b[i]*x;
                cost += x*q[i];
                cost += max(0LL, divceil(need, a[i])*p[i]);
                best = min(best, cost);
            }

            budget -= best;
        }

        if (budget < 0) good = false;

        if (good)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    printf("%lld\n", left);
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
