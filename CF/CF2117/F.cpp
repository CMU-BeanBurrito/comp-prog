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
#define MAXN 200'005
vector<vector<int>> g (MAXN, vector<int> ());
vector<bool> vis (MAXN, false);

void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        vis[i] = false;
    }
}

void solve() {
    int n; cin >> n;

    int fork = -1;

    for (int i = 0; i < n-1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // verify tree
    for (int i = 1; i <= n; i++)
    {
        if (fork == -1)
        {
            if (i == 1)
            {
                if (g[i].size() > 2)
                {
                    printf("0\n");
                    reset(n);
                    return;
                }
                else if (g[i].size() == 2)
                {
                    fork = i;
                }
            }
            else
            {
                if (g[i].size() > 3)
                {
                    printf("0\n");
                    reset(n);
                    return;
                }
                else if (g[i].size() == 3)
                {
                    fork = i;
                }
            }
        }
        else
        {
            if (i == 1)
            {
                if (g[i].size() > 1)
                {
                    printf("0\n");
                    reset(n);
                    return;
                }
            }
            else
            {
                if (g[i].size() > 2)
                {
                    printf("0\n");
                    reset(n);
                    return;
                }
            }
        }
    }

    if (fork == -1)
    {
        ll ans = 1LL;

        for (int i = 0; i < n; i++)
        {
            ans *= 2;
            ans %= MOD;
        }

        printf("%lld\n", ans);
        reset(n);
        return;
    }

    int u = 1;
    vis[u] = true;

    int x = 1; // nodes above fork

    while(u != fork)
    {
        for (int nb : g[u])
        {
            if (vis[nb]) continue;
            u = nb;
            vis[nb] = true;
            x++;
        }
    }

    int y = 0; // nodes in fork's left subtree

    while(g[u].size() > 1)
    {
        for (int nb : g[u])
        {
            if (vis[nb]) continue;
            u = nb;
            vis[nb] = true;
            y++;
            break;
        }
    }

    int z = n-x-y;

    ll ans = 1LL;

    while(x--)
    {
        ans *= 2;
        ans %= MOD;
    }

    if (y < z) swap(y, z);

    int d = y-z;
    
    if (d == 0)
    {
        ans *= 2;
        ans %= MOD;
    }
    else
    {
        ans *= 3;
        ans %= MOD;
        d--;

        while(d--)
        {
            ans *= 2;
            ans %= MOD;
        }
    }


    printf("%lld\n", ans);
    reset(n);
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