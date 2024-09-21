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
    int n, q; cin >> n >> q;

    string s; cin >> s;

    int freq = 0;

    for (int i = 0; i < n-2; i++)
    {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C')
        {
            i += 2;
            freq++;
        }
    }

    while(q--)
    {
        int x; char c;
        cin >> x >> c;

        x--; // 0 indexing

        bool add = false;
        bool sub = false;

        if ((x < n-2 && s[x] == 'A' && s[x+1] == 'B' && s[x+2] == 'C') || (0 < x && x < n-1 && s[x-1] == 'A' && s[x] == 'B' && s[x+1] == 'C') || 
            1 < x && s[x-2] == 'A' && s[x-1] == 'B' && s[x] == 'C')
        {
            if (c != s[x]) sub = true;
        }
        
        if ((x < n-2 && c == 'A' && s[x+1] == 'B' && s[x+2] == 'C') || (0 < x && x < n-1 && s[x-1] == 'A' && c == 'B' && s[x+1] == 'C') || 
            (1 < x && s[x-2] == 'A' && s[x-1] == 'B' && c == 'C'))
        {
            if (c != s[x]) add = true;
        }

        s[x] = c;

        if (add) freq++;
        if (sub) freq--;

        printf("%d\n", freq);
    }
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


