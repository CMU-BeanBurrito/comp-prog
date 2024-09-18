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

// 0 = CW, 1 = CCW
int toss(int start, int dist, int dir, int n)
{
    if (dir == 0)
    {
        int ans = start + dist - 1;
        ans %= n;
        ans++;
        return ans;
    }
    else
    {
        int ans = start - dist - 1;
        ans += n;
        ans %= n;
        ans++;
        return ans;
    }
}

void solve() {
    set<int> s;

    int n, m, x; cin >> n >> m >> x;

    s.insert(x);

    while(m--)
    {
        int dist; char dir;
        cin >> dist >> dir;

        set<int> t;

        for (int i : s)
        {
            if (dir == '?')
            {
                t.insert(toss(i, dist, 0, n));
                t.insert(toss(i, dist, 1, n));
            }
            else
            {
                t.insert(toss(i, dist, dir == '0' ? 0 : 1, n));
            }
        }

        s.swap(t);
    }

    printf("%d\n", s.size());

    for (int i : s)
    {
        printf("%d ", i);
    } printf("\n");
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


