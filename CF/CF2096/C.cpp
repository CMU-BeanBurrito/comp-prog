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
void printiimp(map<int, int>& mp); // print int, int map
void printcimp(map<int, int>& mp); // print char, int map
bool sort2nd(const pair<ll, ll> &p1, const pair<ll, ll> &p2);
bool sortpairsum(const pair<ll, ll> &p1, const pair<ll, ll> &p2);
ll fastexp(ll base, ll exp, ll m); // quickly find base^exp mod m

// PUT GLOBALS HERE
#define INF 1e18

int n;
vector<vector<int>> h (1000, vector<int> (1000));
vector<int> a (1000);
vector<int> b (1000);
vector<vector<ll>> dp (1000, vector<ll> (2, INF));

ll calcdp()
{
    // clean dp
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++) dp[i][j] = INF;
    }

    dp[0][0] = 0; // zeroth row automatically satisfied even if we do nothing
    dp[0][1] = a[0]; // zeroth row still satisfied if we take row 0 operation

    for (int i = 1; i < n; i++)
    {
        // we did not perform the previous row operation
        if (dp[i-1][0] != INF)
        {
            bool must = false;
            bool cant = false;
            for (int j = 0; j < n; j++)
            {
                if (h[i][j] == h[i-1][j]) must = true;
                if (h[i][j] == h[i-1][j]-1) cant = true;
            }

            if (!(must && cant)) // if we must and cannot, then we have to take the previous row's operation
            {
                if (must) // we are forced to do this row's operation if we didn't do the previous row's operation
                {
                    dp[i][1] = min(dp[i][1], dp[i-1][0] + a[i]);
                }
                else if (cant) // we cannot do this row's operation if we didn't do the previous row's operation
                {
                    dp[i][0] = min(dp[i][0], dp[i-1][0]);
                }
                else // we can do this row's operation is if we didn't do the previous row's operation, but we don't have to
                {
                    dp[i][0] = min(dp[i][0], dp[i-1][0]);
                    dp[i][1] = min(dp[i][1], dp[i-1][0] + a[i]);
                }
            }
        }

        // we did the previous row operation
        if (dp[i-1][1] != INF)
        {
            bool must = false;
            bool cant = false;
            for (int j = 0; j < n; j++)
            {
                if (h[i][j] == h[i-1][j]+1) must = true;
                if (h[i][j] == h[i-1][j]) cant = true;
            }

            if (!(must && cant)) // if we must and cannot, then we cannot take the previous row's operation
            {
                if (must) // we are forced to do this row's operation if we did the previous row's operation
                {
                    dp[i][1] = min(dp[i][1], dp[i-1][1] + a[i]);
                }
                else if (cant) // we cannot do this row's operation if we did do the previous row's operation
                {
                    dp[i][0] = min(dp[i][0], dp[i-1][1]);
                }
                else // we can do this row's operation is if we did the previous row's operation, but we don't have to
                {
                    dp[i][0] = min(dp[i][0], dp[i-1][1]);
                    dp[i][1] = min(dp[i][1], dp[i-1][1] + a[i]);
                }
            }
        }

        if (dp[i][0] == INF && dp[i][1] == INF) // can't satisfy the first i rows, regardless of path taken
        {
            return -1;
        }
    }

    return 0;
}

void solve() {
    bool good = true;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cin >> h[i][j];
    }

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // satisfy rows first (no vertical neighbors with same height)
    // dp[i][0] = minimum cost to satisfy first i rows if we did not do row operation i
    // dp[i][1] = minimum cost to satisfy first i rows if we did row operation i
    if (calcdp() == -1) good = false;

    ll ans = min(dp[n-1][0], dp[n-1][1]);

    // transpose grid, so we can do columns using same code as rows
    // also copy column costs into row costs since dp code uses row cost vector
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int x = h[i][j];
            h[i][j] = h[j][i];
            h[j][i] = x;
        }

        a[i] = b[i];
    }

    // satisfy columns next, same logic as rows
    if (calcdp() == -1) good = false;

    ans += min(dp[n-1][0], dp[n-1][1]);

    printf("%lld\n", good ? ans : -1);
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

void printiimp(map<int, int>& mp)
{
    for (auto p : mp) printf("%d %d\n", p.first, p.second);
}

void printcimp(map<char, int>& mp)
{
    for (auto p : mp) printf("%c %d\n", p.first, p.second);
}

bool sort2nd(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
    return p1.second < p2.second;
}

bool sortpairsum(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
    return p1.first+p1.second < p2.first+p2.second;
}

ll fastexp(ll base, ll exp, ll m)
{
    ll res = 1LL;
    base %= m;
    while(exp > 0)
    {
        if (exp % 2 == 1) res *= base;
        exp /= 2;
        base *= base;
        base %= m;
        res %= m;
    }
    return res;
}