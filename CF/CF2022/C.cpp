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
int inv (int a, int m); // modular inverse of a mod m
ll kadane(vector<int>& a, int n); // maximum subarray sum
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll merge(vector<int>& v, int l, int mid, int r); // l and r are inclusive (e.g. 0, n-1)
ll mergesort(vector<int>& v, int l, int r); // l and r are inclusive (e.g. 0, n-1), returns inversion count
void printi(vector<int>& v); // print vector of ints
void printll(vector<ll>& v); // print vector of long long ints
void printc(vector<char>& v); // print vector of chars
bool sort2nd(const pair<ll, ll> &p1, const pair<ll, ll> &p2);

// PUT GLOBALS HERE

/**
 *          *** "row" district
 * 
 *          **
 *          *   "r" district
 * 
 *          *
 *          **  "L" district
 * 
 *          **
 *           *  "flip r" district
 * 
 *           *
 *          **  "flip l" district
 */

void solve() {
    int n; cin >> n;
    vector<vector<int>> board (2, vector<int>(n+1));

    for (int i = 0; i < 2; i++)
    {
        string s; cin >> s;
        for (int j = 1; j <= n; j++)
        {
            if (s[j-1] == 'A') board[i][j] = 1;
            if (s[j-1] == 'J') board[i][j] = 0;
        }
    }

    vector<vector<int>> dp (3, vector<int> (n+10, -1));
    dp[0][0] = 0; // subproblem of 2 rows with 3*k, i = 3k
    dp[1][0] = -1; // subproblem of top row with 3*k+2 and bottom row of 3*k+1, i=3k+1
    dp[2][0] = -1; // subproblem of top row with 3*k+1 and bottom row of 3*k+2, i=3k+1

    for (int i = 0; i <= n; i++)
    {
        int vote;

        for (int c = 0; c < 3; c++)
        {
            if (dp[c][i] == -1) continue;

            if (c == 0)
            {
                /**
                 * Considering dp[0]
                 */

                // row district in top row + row district in bottom row
                vote = (board[0][i+1]+board[0][i+2]+board[0][i+3])/2;
                vote += (board[1][i+1]+board[1][i+2]+board[1][i+3])/2;
                dp[0][i+3] = max(dp[0][i+3], dp[0][i]+vote);

                // r district
                vote = (board[0][i+1]+board[0][i+2]+board[1][i+1])/2;
                dp[1][i+1] = max(dp[1][i+1],dp[0][i]+vote);

                // L district
                vote = (board[0][i+1]+board[1][i+1]+board[1][i+2])/2;
                //printf("%d vote %d\n", i, vote);
                dp[2][i+1] = max(dp[2][i+1], dp[0][i]+vote);
            }

            if (c == 1)
            {
                /**
                 * Considering dp[1]
                 */

                // row district in top row + row district in bottom row
                vote = (board[0][i+2]+board[0][i+3]+board[0][i+4])/2;
                vote += (board[1][i+1]+board[1][i+2]+board[1][i+3])/2;
                dp[1][i+3] = max(dp[1][i+3], dp[1][i]+vote);

                // flip L district
                vote = (board[0][i+2]+board[1][i+1]+board[1][i+2])/2;
                dp[0][i+2] = max(dp[0][i+2], dp[1][i]+vote);
            }

            if (c == 2)
            {
                /**
                 * Considering dp[2]
                 */

                // row district in top row + row district in bottom row
                vote = (board[0][i+1]+board[0][i+2]+board[0][i+3])/2;
                vote += (board[1][i+2]+board[1][i+3]+board[1][i+4])/2;
                dp[2][i+3] = max(dp[2][i+3], dp[2][i]+vote);

                // flip r district
                vote = (board[0][i+1]+board[0][i+2]+board[1][i+2])/2;
                dp[0][i+2] = max(dp[0][i+2], dp[2][i]+vote);
            }
        }
        //printf("AFTER %d\n", i);
        //for (int k = 0; k < 3; k++) printi(dp[k]);
    }

    printf("%d\n", dp[0][n]);
}

int main() {
    int t; cin >> t;
    while(t--) solve();
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

int inv (int a, int m)
{
    int x, y;
    gcdExt(a, m, &x, &y);

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

ll merge(vector<int>& v, int l, int mid, int r) {
    int lidx = l;
    int ridx = mid; // mid+1 from mergesort, first elem of right side
    int residx = 0;
    vector<int> res (r-l+1);
    
    ll ans = 0;
    
    while(lidx <= mid-1 && ridx <= r) {
        if (v[lidx] <= v[ridx]) {
            res[residx] = v[lidx];
            lidx++; residx++;
        } else { // inversion
            res[residx] = v[ridx];
            ridx++; residx++;
            
            ans += (mid-lidx); // elements lidx to mid-1 are all greater than v[ridx]
        }
    }
    
    while(lidx <= mid-1) {
        res[residx] = v[lidx];
        lidx++; residx++;
    }
    
    while(ridx <= r) {
        res[residx] = v[ridx];
        ridx++; residx++;
    }
    
    for (int i = l; i <= r; i++) {
        v[i] = res[i-l];
    }
    
    return ans;
}
 
ll mergesort(vector<int>& v, int l, int r) {
    ll ans = 0;
    
    if (l < r) {
        int mid = l + (r-l)/2; //mid is part of the left subarray
        
        ans += mergesort(v, l, mid);
        ans += mergesort(v, mid+1, r);
        
        ans += merge(v, l, mid+1, r);
    }
    
    return ans;
}

void printi(vector<int>& v)
{
    for (int x : v)
    {
        printf("%d ", x);
    } printf("\n");
}

void printll(vector<ll>& v)
{
    for (ll x : v)
    {
        printf("%lld ", x);
    } printf("\n");
}

void printc(vector<char>& v)
{
    for (char x : v)
    {
        printf("%c ", x);
    } printf("\n");
}

bool sort2nd(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
    return p1.second < p2.second;
}

