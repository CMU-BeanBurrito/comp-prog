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
#define GRASS_MAX 1'000'000'001

typedef struct {
    char dir;
    int x;
    int y;
    int grass = GRASS_MAX;
} cow;

typedef struct {
    int cowa;
    int cowb;
    int meet = GRASS_MAX;
} cowpair;

bool sortcowpair (const cowpair &cpa, const cowpair &cpb)
{
    return cpa.meet < cpb.meet;
}


void solve() {
    int n; cin >> n;
    vector<cow> cows (n);
    vector<cowpair> pairs (n*(n-1)/2);

    for (int i = 0; i < n; i++) cin >> cows[i].dir >> cows[i].x >> cows[i].y;

    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            idx++;
            pairs[idx].cowa = i;
            pairs[idx].cowb = j;
            
            if (cows[i].dir == cows[j].dir) continue;

            if (cows[i].dir == 'N' && cows[j].dir == 'E')
            {
                if (cows[i].y > cows[j].y || cows[i].x < cows[j].x) continue;

                pairs[idx].meet = min(abs(cows[i].x-cows[j].x), abs(cows[i].y-cows[j].y));
            }
            else // cows[i].dir == 'E' && cows[j].dir == 'N'
            {
                if (cows[i].x > cows[j].x || cows[i].y < cows[j].y) continue;

                pairs[idx].meet = min(abs(cows[i].x-cows[j].x), abs(cows[i].y-cows[j].y));
            }
        }
    }

    sort(pairs.begin(), pairs.end(), sortcowpair);

    for (cowpair c : pairs)
    {
        if (cows[c.cowa].dir == cows[c.cowb].dir) continue;
        
        if (cows[c.cowa].dir == 'E' && cows[c.cowb].dir == 'N')
        {
            int meetx = cows[c.cowb].x;
            int meety = cows[c.cowa].y;

            // no intersection of paths
            if (cows[c.cowa].y < cows[c.cowb].y || cows[c.cowa].x > cows[c.cowb].x) continue;

            // they would intersect, but at least one is stopped before the would-be intersection
            if (cows[c.cowa].x + cows[c.cowa].grass < meetx || cows[c.cowb].y + cows[c.cowb].grass < meety) continue;

            if (cows[c.cowa].y > cows[c.cowb].y && cows[c.cowa].x < cows[c.cowb].x && cows[c.cowa].y+cows[c.cowa].x == cows[c.cowb].x+cows[c.cowb].y) // reach intersection at same time
            {
                cows[c.cowa].grass = min(cows[c.cowa].grass, GRASS_MAX);
                cows[c.cowb].grass = min(cows[c.cowb].grass, GRASS_MAX);
            }
            else if (cows[c.cowa].y - cows[c.cowb].y > cows[c.cowb].x - cows[c.cowa].x) // cow i reaches intersection first, cow j is stopped
            {
                cows[c.cowa].grass = min(cows[c.cowa].grass, GRASS_MAX);
                cows[c.cowb].grass = min(cows[c.cowb].grass, cows[c.cowa].y - cows[c.cowb].y);
            }
            else                                                    // cow j reaches intersection first, cow i is stopped
            {
                cows[c.cowa].grass = min(cows[c.cowa].grass, cows[c.cowb].x-cows[c.cowa].x);
                cows[c.cowb].grass = min(cows[c.cowb].grass, GRASS_MAX);
            }
        }
        else
        {
            int meetx = cows[c.cowa].x;
            int meety = cows[c.cowb].y;

            if (cows[c.cowa].y > cows[c.cowb].y) // no intersection
            {
                cows[c.cowa].grass = min(cows[c.cowa].grass, GRASS_MAX);
                cows[c.cowb].grass = min(cows[c.cowb].grass, GRASS_MAX);
                continue;
            }
            else if (cows[c.cowa].x < cows[c.cowb].x) // no intersection
            {
                cows[c.cowa].grass = min(cows[c.cowa].grass, GRASS_MAX);
                cows[c.cowb].grass = min(cows[c.cowb].grass, GRASS_MAX);
                continue;
            }

            // they would intersect, but at least one is stopped before the would-be intersection
            if (cows[c.cowa].y + cows[c.cowa].grass < meety || cows[c.cowb].x + cows[c.cowb].grass < meetx) continue;

            if (cows[c.cowa].y < cows[c.cowb].y && cows[c.cowa].x > cows[c.cowb].x && cows[c.cowa].y+cows[c.cowa].x == cows[c.cowb].x+cows[c.cowb].y) // reach interesection at same time
            {
                cows[c.cowa].grass = min(cows[c.cowa].grass, GRASS_MAX);
                cows[c.cowb].grass = min(cows[c.cowb].grass, GRASS_MAX);
            }
            else if (cows[c.cowb].y - cows[c.cowa].y > cows[c.cowa].x - cows[c.cowb].x) // cow j reaches intersection first, cow i is stopped
            {
                cows[c.cowa].grass = min(cows[c.cowa].grass, cows[c.cowb].y - cows[c.cowa].y);
                cows[c.cowb].grass = min(cows[c.cowb].grass, GRASS_MAX);
            }
            else                                                    // cow i reaches intersection first, cow j is stopped
            {
                cows[c.cowa].grass = min(cows[c.cowa].grass, GRASS_MAX);
                cows[c.cowb].grass = min(cows[c.cowb].grass, cows[c.cowa].x-cows[c.cowb].x);
            }
        }
    }

    for (cow c : cows)
    {
        if (c.grass == GRASS_MAX)
        {
            printf("Infinity\n");
        }
        else
        {
            printf("%d\n", c.grass);
        }
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
