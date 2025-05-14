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

#define MOD 998244353
#define divceil(n, m) (n+m-1)/m

int gcdExt(int a, int b, int* x, int* y);
int inv (int a, int m); // modular inverse of a mod m
ll kadane(vector<ll>& a, int start, int n); // maximum subarray sum
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
#define sen 1'000'000 // sentinel value, can't use INT_MAX as a[i] must be <= 1E9

void solve() {

    /**
     * Observation: if we start a new group with fish i, fish i and all the fish to the right of i have their value increased by 1.
     * 
     * Denote the number of fish at i or to the right of i caught by Alice as x
     * Denote the number of fish at i or to the right of i caught by Bob as y
     * 
     * If we start a new group with fish i, the difference between Bob and Alice's score increases by y-x.
     * 
     * Observation: starting new groups and their effects on the score as described above, are completely independent.
     * 
     * So, the general strategy is as follows:
     * - each index is a potential location to start a new group
     * - each index would change the difference (Bob score minus Alice score) by d[i] = y-x as described above
     * - we want to pick as few indices as possible to reach k
     * - so, we can sort these values of y-x, and greedily pick the largest ones.
     * - clearly, some of these values will be negative, so if we run out of positive values without reaching k, the answer is negative
     * - we can use prefix sum and binary search to quickly see whether we can reach k by only picking a certain number of start points
     */
    
    int n, k; cin >> n >> k;

    string s; cin >> s;

    vector<int> a (n);
    vector<int> suf (n); // suffix sum, s[i] = number of Bob fish - number of Alice fish in s[i...n-1]

    // if we make a cut in between i-1 and i, Bob will gain s[i] points relative to Alice

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0') a[i] = -1;
        if (s[i] == '1') a[i] = 1;
    }

    suf[n-1] = a[n-1];

    for (int i = n-2; i > 0; i--) suf[i] = suf[i+1] + a[i];
    suf[0] = 0; // can't end a group before 0

    sort(suf.begin()+1, suf.end(), greater<int>()); // we want to pick the highest scoring cuts first

    vector<ll> psuf (n+1, 0LL); // prefix sum, psuf[i] = best score we can have if we take the i best cuts (i+1 best groups)
    psuf[0] = 0; // no cuts, no score

    for (int i = 1; i < n; i++) psuf[i] = psuf[i-1] + suf[i];

    // if there is a cut that lowers the score, we ignore it since it lowers our score and increases number of cuts
    // to do this, we "fill in" psuf to make it non-decreasing. now we can use it for binary search
    for (int i = 1; i < n; i++)
    {
        if (psuf[i] < psuf[i-1]) psuf[i] = psuf[i-1];
    }

    // bin search on number of cuts
    int left = 1; // need at least 2 groups, or no fish are worth anything
    int right = n; // can't have more than n groups, right maintains the minimum number we know works

    while(left < right)
    {
        int mid = (left+right)/2;

        if (psuf[mid] >= k) // we can achieve goal score using mid cuts, any number above mid is not the answer. mid might be the answer
        {
            right = mid;
        }
        else // we cannot achieve goal score using mid cuts, mid and any numbers below mid are not the answer
        {
            left = mid+1;
        }
    }

    // if left == n, no number of cuts worked, no solution. otherwise we made left cuts, so there are left+1 groups
    printf("%d\n", left == n ? -1 : left+1);
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

ll kadane(vector<ll>& a, int start, int n)
{
    ll sum = 0;
    ll best = 0;

    for (int i = start; i < start+n; i++)
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
