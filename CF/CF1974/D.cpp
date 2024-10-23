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
void printcimp(map<char, int>& mp); // print char, int map
bool sort2nd(const pair<ll, ll> &p1, const pair<ll, ll> &p2);

// PUT GLOBALS HERE

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (n == 2 && (s[0] != s[1]))
    {
        printf("NO\n");
        return;
    }
    else if (n == 2)
    {
        printf("RH\n");
        return;
    }

    int x = 0; int y = 0;
    int xx = 0; int yy = 0;
    map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N') {y++; yy++;}
        if (s[i] == 'S') {y--; yy++;}
        if (s[i] == 'W') {x--; xx++;}
        if (s[i] == 'E') {x++; xx++;}
        mp[s[i]]++;
    }

    if (abs(mp['N']-mp['S']) % 2 == 1 || abs(mp['W']-mp['E']) % 2 == 1)
    {
        printf("NO\n");
        return;
    }

    map<char, int> R;
    map<char, int> H;

    if (mp['N'] != mp['S'])
    {
        R['N'] = min(mp['N'], mp['S']);
        R['S'] = min(mp['N'], mp['S']);
        mp['N'] -= R['N'];
        mp['S'] -= R['S'];
        R['N'] += mp['N']/2;
        R['S'] += mp['S']/2;
        H['N'] += mp['N']/2;
        H['S'] += mp['S']/2;

        R['E'] = min(mp['E'], mp['W']);
        R['W'] = min(mp['E'], mp['W']);
        mp['E'] -= R['E'];
        mp['W'] -= R['W'];
        R['W'] += mp['W']/2;
        R['E'] += mp['E']/2;
        H['W'] += mp['W']/2;
        H['E'] += mp['E']/2;
    }
    else if (mp['N'] > 0)
    {
        R['N'] = 1;
        R['S'] = 1;
        H['N'] = mp['N']-1;
        H['S'] = mp['S']-1;

        H['E'] = min(mp['E'], mp['W']);
        H['W'] = min(mp['E'], mp['W']);
        mp['E'] -= H['E'];
        mp['W'] -= H['W'];
        R['W'] += mp['W']/2;
        R['E'] += mp['E']/2;
        H['W'] += mp['W']/2;
        H['E'] += mp['E']/2;
    }
    else if (mp['W'] != mp['E'])
    {
        R['W'] = min(mp['W'], mp['E']);
        R['E'] = min(mp['W'], mp['E']);
        mp['W'] -= R['W'];
        mp['E'] -= R['E'];
        R['W'] += mp['W']/2;
        R['E'] += mp['E']/2;
        H['W'] += mp['W']/2;
        H['E'] += mp['E']/2;
    }
    else
    {
        R['W'] = 1;
        R['E'] = 1;
        H['W'] = mp['W']-1;
        H['E'] = mp['E']-1;
    }

    for (char c : s)
    {
        if (R[c] > 0)
        {
            printf("R");
            R[c]--;
        }
        else
        {
            printf("H");
            H[c]--;
        }
    } printf("\n");
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

