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

    vector<int> a (n);
    vector<bool> split (n, false);

    for (int i = 0; i < n; i++) cin >> a[i];

    if (a[0]/10 <= a[0]%10) split[0] = true;

    for (int i = 1; i < n; i++)
    {
        if (split[i-1])
        {
            if (a[i] < 10) // no choice to make
            {
                if (a[i] < a[i-1]%10) // fail
                {
                    printf("NO\n");
                    return;
                }
            }
            else if (a[i]/10 >= a[i-1]%10 && a[i]%10 >= a[i]/10) // try to split
            {
                split[i] = true;
            }
            else // can't split, do nothing
            {
                
            }
        }
        else
        {
            if (a[i] < a[i-1])
            {
                printf("NO\n");
                return;
            }
            else if (a[i]/10 >= a[i-1] && a[i]%10 >= a[i]/10) // try to split
            {
                split[i] = true;
            }
            else // can't split, do nothing
            {
                
            }
        }
    }

    printf("YES\n");
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


