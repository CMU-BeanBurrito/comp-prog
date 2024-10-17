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
    int n; cin >> n;
    vector<vector<int>> cake (3, vector<int> (n+1));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++) cin >> cake[i][j];
    }

    vector<vector<ll>> pref (3, vector<ll> (n+1));
    pref[0][0] = 0LL;
    pref[1][0] = 0LL;
    pref[2][0] = 0LL;    

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++) pref[i][j] = pref[i][j-1] + cake[i][j];
    }

    vector<int> ans;
    int idx = 0;
    ll third = divceil(pref[0][n], 3); // need to give each person this amount of cake

    vector<int> perm = {0, 1, 2};

    do
    {
        // set up permutation
        vector<int> ans (6);
        int start = 1; // start of the current person's slice
        int idx = 1;
        bool good = true;

        // check prefix sums
        for (int i = 0; i < 3; i++)
        {
            int a = perm[i]; // which person are we currently serving

            while (idx < n && pref[a][idx]-pref[a][start-1] < third) // try to give them enough cake
            {
                idx++;
            }

            if (pref[a][idx]-pref[a][start-1] >= third) // we gave them enough
            {
                ans[2*a] = start; // add to ans vector based on which person this is
                ans[2*a+1] = idx;
            }
            else // we weren't able to give them enough cake
            {
                good = false;
                break;
            }

            start = idx+1; // next person's slice starts after this person's slice ends
        }

        if (good) // we were able to serve everyone enough cake
        {
            for (auto x : ans)
            {
                printf("%d ", x);
            } printf("\n");

            return;
        }
        
    } while (next_permutation(perm.begin(), perm.end()));
    
    printf("-1\n"); // went through all permutations, none allowed to serve everyone enough cake

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

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a%b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
