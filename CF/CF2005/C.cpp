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
    int n, m; cin >> n >> m;

    vector<string> v (n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int score = 0;

    int cost = 0;
    vector<char> have;

    for (int i = 0; i < n; i++)
    {
        bool used = false;
        for (int j = 0; j < m; j++)
        {
            if (have.size() == 0 && v[i][j] == 'n')
            {
                have.push_back('n');
                used = true;
            }
            else if (have.size() == 1 && v[i][j] == 'a')
            {
                have.push_back('a');
                used = true;
            }
            else if (have.size() == 2 && v[i][j] == 'r')
            {
                have.push_back('r');
                used = true;
            }
            else if (have.size() == 3 && v[i][j] == 'e')
            {
                have.push_back('e');
                used = true;
            }
            else if (have.size() == 4 && v[i][j] == 'k')
            {
                have.push_back('k');
                used = true;
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


