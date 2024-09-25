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

void solve() {
    int n, q; cin >>n >> q;

    vector<int> a (n);

    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<ll> pref (2*n);

    pref[0] = 0LL;
    
    for (int i = 1; i <= 2*n; i++)
    {
        pref[i] = pref[i-1] + a[(i-1)%n + 1];
        printf("%lld ", pref[i]);
    } printf("\n");

    while(q--)
    {
        ll left, right; cin >> left >> right;

        //left--; // so we can do right-left and exclude left

        ll left_rot = (left-1)/n + 1;
        ll right_rot = (right-1)/n + 1;

        ll left_idx = ((left-1)%n + 1);
        ll right_idx = ((right-1)%n + 1);

        printf("%d %d %d %d\n", left_rot, left_idx, right_rot, right_idx);

        ll ans = 0LL;

        // no full rotations between left and right
        if (right_rot == left_rot)
        {
            ans =  pref[right_rot+right_idx-1] - pref[left_rot+left_idx-1] + a[(left_rot+left_idx-1)%n + 1];
        }
        else
        {
            // add any full rotations
            // add prefix of right_rot
            // add suffix of left_rot
            ans += (right_rot-left_rot-1)*pref[n];
            printf("%lld\n", ans);
            ans += pref[right_rot+right_idx]-pref[right_rot];
            printf("%lld\n", ans);
            ans += pref[left_rot-1+n]-pref[left_rot-1];
        }

        printf("%lld\n", ans);
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


