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

/**
 * Strategy: 
 * 
 * Note: this description uses 0-indexing, the problem statement uses 1-indexing.
 * 
 * Observe that since our operations only affect indices i s.t. l < i < r, if x[0] == 1, or x[n-1] == 1, there is no solution.
 * 
 * Let a be the index such that x[a] = 1. Let b be the index such that x[b] = n.
 * 
 * Then, we can never make s[a] or s[b] equal to 1.
 * No matter what segment we choose, it will never be strictly within the bounds of the segment's endpoints.
 * 
 * So to determine if there is a solution or not, we simply check if x[0], x[n-1], x[a], and x[b]. 
 * If any of them are 1, there is no solution.
 * 
 * If there is a solution:
 * - use segments [l, r] (if l > r, then use [r, l]):
 *   - [a, b]
 *   - [0, a]
 *   - [0, b]
 *   - [a, n-1]
 *   - [b, n-1]
 * 
 * Proof: There are 3 cases:
 * 
 * Case 1: 1 and n are at endpoints (0 or n-1).
 * 
 * a = 0, b = n-1 (or vice versa). It is obvious [a, b] (or [b, a]) will cover all the indices we need.
 * 
 * Case 2: 1 or n is at an endpoint, but the other is not.
 * 
 * Suppose a = 0, and b != n-1. Then we can use 3 segments:
 * - [a, b]: covers all indices in (0, b)
 * - [a, n-1]: covers all indices i in (b, n-1) such that 1 < p[i] < p[n-1]
 * - [b, n-1]: covers all indices i in (b, n-1) such that p[n-1] < p[i] < n
 * 
 * So, all necessary elements are covered.
 * Without loss of generality, this process can be used if a = n-1, or if b is at an endpoint but a is not.
 * 
 * Case 3: Neither 1 or n are at endpoints. We need all 5 operations.
 * - [a, b]: covers all indices (a, b)
 * - [0, a]: covers all indices i in (0, a) such that 1 < p[i] < p[0]
 * - [0, b]: covers all indices i in (0, b) such that p[0] < p[i] < n-1
 * - [a, n-1]: covers all indices i in (a, n-1) such that 1 < p[i] < p[n-1]
 * - [b, n-1]: covers all indices i in (b, n-1) such that p[n-1] < p[i] < n
 * 
 * So, all necessary elements are covered.
 * 
 * Since we do not have to minimize operations, we can use the Case 3 strategy every time (after checking that a solution exists).
 */

// PUT GLOBALS HERE

void solve() {
    int n; cin >> n;
    vector<int> p (n);
    for (int i = 0; i < n; i++) cin >> p[i];
    string x; cin >> x;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == 1) a = i;
        if (p[i] == n) b = i;
    }

    if (x[0] == '1' || x[n-1] == '1' || x[a] == '1' || x[b] == '1')
    {
        printf("-1\n");
        return;
    }

    a++; b++; // problem uses 1-indexing
    printf("5\n");
    printf("%d %d\n", min(a, b), max(a, b));
    printf("%d %d\n", 1, a);
    printf("%d %d\n", 1, b);
    printf("%d %d\n", a, n);
    printf("%d %d\n", b, n);
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
