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
    int n, m, q; cin >> n >> m >> q;

    vector<int> b (m);
    vector<int> a (q);

    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < q; i++) cin >> a[i];

    sort(b.begin(), b.end());

    for (int i = 0; i < q; i++)
    {
        //printf("B %d\n", a[i]);
        int l = 0;
        int r = m;

        while(l < r)
        {
            int mid = (l+r)/2;
            //printf("MID %d\n", mid);

            if (b[mid] == a[i])
            {
                // cant happen
            }
            else if (b[mid] > a[i])
            {
                if (mid == 0)
                {
                    printf("%d\n", b[mid]-1);
                    break;
                }

                if (b[mid-1] < a[i])
                {
                    printf("%d\n", (b[mid]-b[mid-1])/2);
                    break;
                }
                else
                {
                    r = mid;
                }
            }
            else // b[mid] < a[i]
            {
                if (mid == m-1)
                {
                    printf("%d\n", n-b[m-1]);
                    break;
                }

                if (b[mid+1] > a[i])
                {
                    printf("%d\n", (b[mid+1]-b[mid])/2);
                    break;
                }
                else
                {
                    l = mid+1;
                }
            }
        }


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


