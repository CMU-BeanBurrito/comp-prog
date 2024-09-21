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
    int n; cin >> n;

    vector<int> h (n+1);

    for (int i = 1; i <= n; i++) cin >> h[i];

    vector<int> maxes (n);
    maxes[0] = h[n];
    int front = 0;
    int back = 1;

    vector<int> dp (n+1);

    dp[n] = 0;
    dp[n-1] = 1;

    int mx = h[n];

    for (int i = n-2; i > 0; i--)
    {
        if (h[i+1] < maxes[back-1])
        {
            maxes[back] = h[i+1];
            back++;
            dp[i] = back;
            
        }
        else
        {
            int l = front;
            int r = back;

            while(l < r)
            {
                int mid = (l+r)/2;

                if (maxes[mid] > h[i+1])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid;
                }
            }

            back = l+1;
            maxes[l] = h[i+1];
            dp[i] = back;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dp[i]);
    } printf("\n");
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


