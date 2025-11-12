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
 * Each valid path can be uniquely determined by one parameter: the column where we move from the top to bottom row.
 * 
 * Iterate over this column, maintaining a multiset of all cells in the path that we are considering.
 * 
 * For a given path to be valid, the chosen range must span at least the min (L) and max (R) values along the path.
 * Record best[L] = min(best[L], R). If best[L] < R, it means another path will exist under more input pairs.
 * best should be initialized to sentinel value 2n+1 to mark that no valid R was found yet.
 * 
 * After we have recorded data from all paths, compute answer:
 * 
 * Iterate over L backwards (2n to 1), tracking the minimum best[L] value (k) seen so far.
 * If best[L] > k, it means that there was some path with range [L', k] with L' > L.
 * So, (L, k) would be a valid range, even if no path with minimum L and maximum k exists.
 * This also covers the case where no path with minimum L exists, and therefore best[L] = 2n+1.
 * 
 * For example:
 * - Suppose we found paths with minimum value 1 and 3, and that best[1] = 4, best[3] = 6.
 * - Suppose k = 6 when we reach L = 2.
 * - best[2] = 2n+1, but clearly, (2, 6), and (2, 7), (2, 8), are all valid as they contain [3, 6] (if they exist).
 * - however, (2, 5) is not valid. there are no paths containing minimum value 2. so (2, 5) would yield the same paths as (3, 5).
 * - if k = 6, then (3, 5) wasn't a valid pair, so (2, 5) is not valid either.
 */

// PUT GLOBALS HERE

void solve() {
    int n; cin >> n;
    vector<vector<int>> a (2, vector<int> (n));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    // contains all cell values for the path we are currently examining.
    multiset<int> s;

    /**
     * Begin with inserting all bottom row cells.
     * 
     * We iterate over the "transition column", which is initially 0.
     * So our path will be going down immediately and following the bottom row.
     * As we iterate, we will remove bottom row cells from the prefix and add top row cells.
     */
    for (int i = 0; i < n; i++) s.insert(a[1][i]);

    /**
     * best[L] is the smallest value for which (L, best[L]) was the range of a valid path.
     * however, best[L] is not necessarily the smallest value for which (L, best[L]) would be a valid pair.
     * why? best[L+1] can be less than best[L]. In that case, (L, best[L+1]) is still a valid pair.
     */
    vector<int> best (2*n+1, 2*n+1);

    for (int i = 0; i < n; i++)
    {
        // add top row value, as we are moving the transition to this column
        s.insert(a[0][i]);

        int L = *s.begin(); // min value on path
        int R = *s.rbegin(); // max value on path
        best[L] = min(best[L], R);
        
        // remove bottom row value. it will not be on the next path as the transition will move to the right.
        s.erase(s.find(a[1][i]));
    }

    ll ans = 0LL;
    int k = 2*n+1;
    for (int L = 2*n; L >= 1; L--)
    {
        k = min(k, best[L]);
        ans += (2*n+1)-k; // (i, k), (i, k+1), (i, k+2)....(i, 2n) are all valid
    }

    printf("%lld\n", ans);
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
