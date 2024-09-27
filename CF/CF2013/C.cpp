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

    int len = 0;
    string s = "";

    while(len < n)
    {
        string s0 = s + "0";

        cout << "? " << s0 << endl;
        int resp; cin >> resp;

        if (resp == 1)
        {
            s = s0;
            len++;
            continue;
        }

        string s1 = s + "1";

        cout << "? " << s1 << endl;
        cin >> resp;

        if (resp == 1)
        {
            s = s1;
            len++;
        }
        else
        {
            break;
        }
    }

    string p = s;

    while(len < n)
    {
        string p0 = "0" + p;

        cout << "? " << p0 << endl;
        int resp; cin >> resp;

        if (resp == 1)
        {
            p = p0;
            len++;
        }
        else
        {
            p = "1" + p;
            len++;
        }
    }

    cout << "! " << p << endl;
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


