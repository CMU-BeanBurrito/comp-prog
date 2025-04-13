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
int len(int x)
{
    int l = 0;
    while(x > 0)
    {
        l++;
        x /= 10;
    }

    return l;
}

int sum(int x)
{
    int s = 0;
    while(x > 0)
    {
        s += (x % 10);
        x /= 10;
    }

    return s;
}

void solve() {
    int n; cin >> n;

    vector<vector<int>> freq (6, vector<int> (46));
    vector<int> a (n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int x = a[i];
        int sum = 0;
        int len = 0;
        while(x > 0)
        {
            sum += (x % 10);
            len++;
            x /= 10;
        }
        freq[len][sum]++;
    }

    ll ans = 0LL;

    for (int i = 0; i < n; i++)
    {
        int l = len(a[i]);
        int s = sum(a[i]);

        if (l % 2 == 0)
        {
            if (l == 2)
            {
                // same length, same value
                ans += freq[2][s];
            }
            else // l == 4
            {
                // same length, same value
                ans += freq[4][s];

                // 2-length pieces that could go behind
                int front42 = sum(a[i]/10) - sum(a[i]%10); // first 3 digits - last digit
                if (front42 > 0) ans += freq[2][front42];

                // 2-length pieces that could go in front
                int back24 = sum(a[i]%1000) - sum(a[i]/1000); // last 3 digits - first digit
                if (back24 > 0) ans += freq[2][back24];
            }
        }
        else
        {
            if (l == 1)
            {
                // same length, same sum
                ans += freq[1][s];
            }
            else if (l == 3)
            {
                // same length, same sum
                ans += freq[3][s];

                // 1-length piece that could go behind
                int front31 = sum(a[i]/10) - sum(a[i]%10); // first 2 digits - last digit
                if (front31 > 0) ans += freq[1][front31];

                // 1-length piece that could go in front
                int back13 = sum(a[i]%100) - sum(a[i]/100); // last 2 digits - first digit
                if (back13 > 0) ans += freq[1][back13];
            }
            else // l == 5
            {
                // same length, same sum
                ans += freq[5][s];

                // 1-length piece that could go behind
                int front51 = sum(a[i]/100) - sum(a[i]%100); // first 3 digits - last 2 digits
                if (front51 > 0) ans += freq[1][front51];

                // 1-length piece that could go in front
                int back15 = sum(a[i]%1000) - sum(a[i]/1000); // last 3 digits - first 2 digits
                if (back15 > 0) ans += freq[1][back15];

                // 3-length piece that could go behind
                int front53 = sum(a[i]/10) - sum(a[i]%10); // first 4 digits - last digit
                if (front53 > 0) ans += freq[3][front53];

                // 3-length piece that could go in front
                int back35 = sum(a[i]%10000) - sum(a[i]/10000); // last 4 digits - first digit
                if (back35 > 0) ans += freq[3][back35];
            }
        }
    }

    printf("%lld\n", ans);
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