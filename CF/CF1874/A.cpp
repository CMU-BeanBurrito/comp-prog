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

void solve() {
    int n, m, k; cin >> n >> m >> k;

    map<int, int> a;
    map<int, int> b;
    ll asum = 0LL;
    ll bsum = 0LL;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a[x]++;
        asum += x;
    }

    for (int j = 0; j < m; j++)
    {
        int x; cin >> x;
        b[x]++;
        bsum += x;
    }

    // first move, A gives min(A) for max(B)
    // second move, B gives min(B) for max(A)
    // every move after, swap min(all) for max(all)

    int mina = (*(a.begin())).first;
    int maxb = (*(b.rbegin())).first;

    if (mina < maxb)
    {
        a[mina]--;
        b[mina]++;
        a[maxb]++;
        b[maxb]--;
        asum += maxb - mina;
        bsum += mina - maxb;
    }

    k--;

    if (k == 0)
    {
        printf("%lld\n", asum);
        return;
    }

    int minb;
    int maxa;

    for (auto it = b.begin(); it != b.end(); it++)
    {
        if ((*it).second > 0)
        {
            minb = (*it).first;
            break;
        }
    }

    for (auto it = a.rbegin(); it != a.rend(); it++)
    {
        if ((*it).second > 0)
        {
            maxa = (*it).first;
            break;
        }
    }

    if (minb < maxa)
    {
        a[maxa]--;
        b[maxa]++;
        a[minb]++;
        b[minb]--;
        asum += minb - maxa;
        bsum += maxa - minb;
    }

    k--;

    if (k == 0)
    {
        printf("%lld\n", asum);
        return;
    }

    if (k % 2 == 0)
    {
        printf("%lld\n", asum);
        return;
    }

    int minall;
    int maxall;

    for (auto it = a.begin(); it != a.end(); it++)
    {
        if ((*it).second > 0)
        {
            minall = (*it).first;
            break;
        }
    }

    for (auto it = b.rbegin(); it != b.rend(); it++)
    {
        if ((*it).second > 0)
        {
            maxall = (*it).first;
            break;
        }
    }

    printf("%lld\n", asum + maxall - minall);
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