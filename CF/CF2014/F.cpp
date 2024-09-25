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

    vector<int> a (2*n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i < 2*n; i++) a[i] = a[i-n];

    vector<ll> pref (2*n);
    pref[0] = a[0];
    
    for (int i = 1; i < 2*n; i++) pref[i] = pref[i-1] + a[i];

    while(q--)
    {
        ll left, right; cin >> left >> right;

        left--; right--;

        ll left_rot = left/n;
        ll right_rot = right/n;

        ll left_idx = left%n;
        ll right_idx = right%n;

        ll ans = 0LL;

        // no full rotations between left and right
        if (right_rot == left_rot)
        {
            ans = pref[right_rot+right_idx] - pref[left_rot+left_idx] + a[left_rot+left_idx];
        }
        else
        {
            // add any full rotations
            // add prefix of right_rot
            // add suffix of left_rot
            ans += (right_rot-left_rot-1)*pref[n-1];
            ans += pref[right_rot+right_idx]-pref[right_rot]+a[right_rot];
            ans += pref[left_rot+n-1]-pref[left_rot+left_idx]+a[left_rot+left_idx];
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


