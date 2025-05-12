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
#define MAXN 4'000'005
vector<ll> fact (MAXN+1);
vector<ll> invf (MAXN+1);

ll nck(ll n, ll k)
{
    if (n < k) return 0LL;
    
    return fact[n] * invf[k] % MOD * invf[n-k] % MOD;
}

void nck_preprocess()
{
    fact[0] = 1LL;
    invf[0] = 1LL;
 
    for (int i = 1; i <= MAXN; i++)
    {
        fact[i] = fact[i-1] * i % MOD;
        invf[i] = inv(fact[i], MOD);
    }

}

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int n = a + b + c + d;

    /**
     * Rules as defined in problem statement:
     * Every A must be left of all Cs
     * Every A must be left of all Ds
     * Every B must be left of all Ds
     */

    /**
     * explanation using 1 indexing
     * observe that to uniquely define a lineup, we just need to pick positions for A's and C's
     * the last A cannot be beyond A+B, otherwise a C or D would be to the left of the last A
     * so, of the first A+B spots, we need to choose A of them for the A's
     * of the remaining N-A-B spots, we need to choose C of them for the C's (Rule 1 satisfied)
     * now we go left to right using all the B's to fill in empty spots, then all the D's (Rule 2 satisfied)
     * there are at most B gaps to the left of the rightmost A, and we fill gaps with Bs first, so can't be any Ds to the left of any A (Rule 3 satisfied)
     */

    /**
     * last A can be anywhere in [A, A+B] (B+1 choices), for each of these B+1 choices X, we need to:
     *  - choose A-1 spots among [1, X-1] for the other As, "(X-1) choose (A-1)"
     *  - choose C spots among [X+1, N] for the Cs, "(N-X) choose C"
     * 
     * clearly, those 2 steps are independent so they can be multiplied. answer is sum of these products when iterating over X from A to A+B
     */

    ll ans = 0LL;

    for (int i = a; i <= a+b; i++)
    {
        ll chooseA = nck(i-1, a-1);
        ll chooseC = nck(n-i, c);
        ans += (chooseA * chooseC);
        ans %= MOD;
    }

    printf("%lld\n", ans);

    //printll(fact);
    //printll(invf);
}

int main() {
    nck_preprocess();
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
