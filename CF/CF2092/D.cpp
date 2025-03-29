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
    int n; cin >> n;
    string s; cin >> s;

    int numL = 0;
    int numI = 0;
    int numT = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L') numL++;
        if (s[i] == 'I') numI++;
        if (s[i] == 'T') numT++;
    }

    if (numL == numI && numI == numT)
    {
        printf("0\n");
        return;
    }

    if (numL == n || numI == n || numT == n)
    {
        printf("-1\n");
        return;
    }

    int mx = max(numL, max(numI, numT));
    int needa, needb;

    map<char, char> mp;

    // contruct char map
    if (numL == mx)
    {
        mp['c'] = 'L';
        if (numI > numT)
        {
            mp['b'] = 'I';
            mp['a'] = 'T';
            needa = mx - numT;
            needb = mx - numI;
        }
        else
        {
            mp['a'] = 'I';
            mp['b'] = 'T';
            needa = mx - numI;
            needb = mx - numT;
        }
    }
    else if (numI == mx)
    {
        mp['c'] = 'I';
        if (numL > numT)
        {
            mp['b'] = 'L';
            mp['a'] = 'T';
            needa = mx - numT;
            needb = mx - numL;
        }
        else
        {
            mp['a'] = 'L';
            mp['b'] = 'T';
            needa = mx - numL;
            needb = mx - numT;
        }
    }
    else
    {
        mp['c'] = 'T';
        if (numL > numI)
        {
            mp['b'] = 'L';
            mp['a'] = 'I';
            needa = mx - numI;
            needb = mx - numL;
        }
        else
        {
            mp['a'] = 'L';
            mp['b'] = 'I';
            needa = mx - numL;
            needb = mx - numI;
        }
    }

    // NUM OPERATIONS
    printf("%d\n", needa == needb ? needa+needb : 2*(needb)+4*(needa-needb));

    // EASY CASE
    if (needa == needb)
    {
        for (int i = 0; i < n-1; i++)
        {
            if (s[i] == mp['a'] && s[i+1] == mp['c'])
            {
                for (int j = i; j < i+needa+needb; j++) printf("%d\n", j+1);
                return;
            }
            else if (s[i] == mp['c'] && s[i+1] == mp['a'])
            {
                for (int j = i; j < i+needa+needb; j++) printf("%d\n", i+1);
                return;
            }
            else if (s[i] == mp['b'] && s[i+1] == mp['c'])
            {
                for (int j = i; j < i+needa+needb; j++) printf("%d\n", j+1);
                return;
            }
            else if (s[i] == mp['c'] && s[i+1] == mp['b'])
            {
                for (int j = i; j < i+needa+needb; j++) printf("%d\n", i+1);
                return;
            }
        }

        // IF WE WENT INTO ANY OF THESE IF STATEMENTS, DONE!
    }

    // HARD CASE
    // step 1. add needb a's and needb b's
    // step 2. add (needa - needb) a's, for each one, will need to add one of (abac/caba/acab/baca)
    
    // char array to construct the actual string in its state after step 1.
    vector<char> intermediate (n+needb+needb);

    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == mp['b'] && s[i+1] == mp['c']) // BC -> B[ABAB...AB]C
        {
            for (int j = i; j < i+needb+needb; j++) printf("%d\n", j+1); // insert forward
            for (int k = 0; k <= i; k++) intermediate[k] = s[k];
            for (int k = i+1; k < i+1+needb+needb; k+=2) intermediate[k] = mp['a'];
            for (int k = i+2; k < i+1+needb+needb; k+=2) intermediate[k] = mp['b'];
            for (int k = i+1+needb+needb; k < n+needb+needb; k++) intermediate[k] = s[k-needb-needb];
            break;
        }

        if (s[i] == mp['c'] && s[i+1] == mp['b']) // CB -> C[BABA...BA]B
        {
            for (int j = i; j < i+needb+needb; j++) printf("%d\n", i+1); // insert backwards
            for (int k = 0; k <= i; k++) intermediate[k] = s[k];
            for (int k = i+1; k < i+1+needb+needb; k+=2) intermediate[k] = mp['b'];
            for (int k = i+2; k < i+1+needb+needb; k+=2) intermediate[k] = mp['a'];
            for (int k = i+1+needb+needb; k < n+needb+needb; k++) intermediate[k] = s[k-needb-needb];
            break;
        }

        if (s[i] == mp['a'] && s[i+1] == mp['c']) // AC -> A[BABA...BA]C
        {
            for (int j = i; j < i+needb+needb; j++) printf("%d\n", j+1); // insert forwards
            for (int k = 0; k <= i; k++) intermediate[k] = s[k];
            for (int k = i+1; k < i+1+needb+needb; k+=2) intermediate[k] = mp['b'];
            for (int k = i+2; k < i+1+needb+needb; k+=2) intermediate[k] = mp['a'];
            for (int k = i+1+needb+needb; k < n+needb+needb; k++) intermediate[k] = s[k-needb-needb];
            break;
        }

        if (s[i] == mp['c'] && s[i+1] == mp['a']) // CA -> C[ABAB...AB]A
        {
            for (int j = i; j < i+needb+needb; j++) printf("%d\n", i+1); // insert backwards
            for (int k = 0; k <= i; k++) intermediate[k] = s[k];
            for (int k = i+1; k < i+1+needb+needb; k+=2) intermediate[k] = mp['a'];
            for (int k = i+2; k < i+1+needb+needb; k+=2) intermediate[k] = mp['b'];
            for (int k = i+1+needb+needb; k < n+needb+needb; k++) intermediate[k] = s[k-needb-needb];
            break;
        }
    }

    for (int i = 0; i < n+needb+needb; i++)
    {
        if (intermediate[i] == mp['b'] && intermediate[i+1] == mp['c'])
        {
            for (int j = 0; j < needa-needb; j++) printf("%d\n%d\n%d\n%d\n", i+1, i+2, i+3, i+1);
            return;
        }

        if (intermediate[i] == mp['c'] && intermediate[i+1] == mp['b'])
        {
            for (int j = 0; j < needa-needb; j++) printf("%d\n%d\n%d\n%d\n", i+1, i+2, i+3, i+1);
            return;
        }

        if (intermediate[i] == mp['a'] && intermediate[i+1] == mp['c'])
        {
            for (int j = 0; j < needa-needb; j++) printf("%d\n%d\n%d\n%d\n", i+1, i+2, i+1, i+2);
            return;
        }

        if (intermediate[i] == mp['c'] && intermediate[i+1] == mp['a'])
        {
            for (int j = 0; j < needa-needb; j++) printf("%d\n%d\n%d\n%d\n", i+1, i+1, i+3, i+3);
            return;
        }

        if (intermediate[i] == mp['a'] && intermediate[i+1] == mp['b'])
        {
            for (int j = 0; j < needa-needb; j++) printf("%d\n%d\n%d\n%d\n", i+1, i+2, i+1, i+2);
            return;
        }

        if (intermediate[i] == mp['b'] && intermediate[i+1] == mp['a'])
        {
            for (int j = 0; j < needa-needb; j++) printf("%d\n%d\n%d\n%d\n", i+1, i+1, i+3, i+3);
            return;
        }
    }
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