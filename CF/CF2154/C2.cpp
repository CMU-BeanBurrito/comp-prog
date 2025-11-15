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
 * Strategy: suppose x is the lowest cost, and y is the second lowest cost (they may be the same).
 * 
 * Answer can never exceed x and y, since we can just make both of the corresponding elements even.
 * 
 * If we perform operations on two elements, it will be one operation each, as no more are required to get them both even.
 * 
 * Otherwise, we are performing operations on only 1 element. However, it may be many operations.
 * 
 * Can use code from "easy solution" to determine if the answer is 0.
 * 
 * If answer is not 0, try 1 operation on all x-cost elements, and try 1 operation on all y-cost elements.
 * 
 * If that does not work, then the answer must be some number of x-cost operations on the first element. 
 * Iterate through all seen prime factors (except its own).
 * 
 * If there are multiple elements tied for the lowest cost, why don't we have to try all of them?
 * Our cost should never exceed 2x. We already tried doing 1 operation on each element, and none succeeded.
 * Therefore, we can safely operate on any x-cost element, we choose the first.
 * 
 * Of course, if there is only element with cost x, it may require many more operations.
 */

// PUT GLOBALS HERE
#define PFSIZE 200'005 
vector<vector<int>> pf (PFSIZE+1);
 
void genpf()
{
    for (int i = 2; i <= PFSIZE; i++)
    {
        if (!pf[i].empty()) continue;

        for (int j = i; j <= PFSIZE; j += i)
        {
            pf[j].push_back(i);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a (n); // a[i].first is element, a[i].second is cost

    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;

    sort(a.begin(), a.end(), sort2nd);

    map<int, int> seen;

    for (int i = 0; i < n; i++)
    {
        for (int p : pf[a[i].first])
        {
            if (seen[p] > 0)
            {
                printf("0\n");
                return;
            }

            seen[p]++;
        }
    }

    ll ans = a[0].second + a[1].second;

    for (int i = 0; i < n; i++)
    {
        for (int p : pf[a[i].first+1])
        {
            if (seen[p] > 0)
            {
                ans = min(ans, 1LL*a[i].second);
            }
        }
    }

    for (auto p : seen)
    {
        if (a[0].first % p.first == 0) continue; // this is a factor of the number of we're checking, so it doesn't count
        if (p.second <= 0) continue; // this factor was checked for, but not a part of any number in a

        ll need = p.first - (a[0].first % p.first);
        if (need == 0) need = p.first;
        ans = min(ans, need*a[0].second);
    }

    printf("%lld\n", ans);
}

int main() {
    genpf();
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