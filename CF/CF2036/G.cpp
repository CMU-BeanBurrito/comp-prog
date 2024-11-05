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
    ll n; cin >> n;

    int m = 60;
    ll resp;

    ll a = -1;

    ll total;
    printf("xor 1 %lld\n", n);
    cin >> total;

    for (int i = m; i >= 0; i--) // find top bit
    {
        if ((1LL << i) & n)
        {
            m = i;
            break;
        }
    }

    while(m > 0)
    {
        printf("xor %lld %lld\n", (1LL << m), min((1LL << (m+1))-1, n)); // check top bit = 1
        cin >> resp;

        if (resp == 0LL) // all 3 tomes in 1 <= x < 2^m
        {
            m--;
            continue;
        }

        if (resp == total) // all 3 tomes in 2^m <= x <= min(n, 2^(m+1)-1)
        {
            ll left = 1LL << m;
            ll right = min((1LL << (m+1))-1, n);

            while(left < right)
            {
                ll mid = (right+left)/2;
                printf("xor %lld %lld\n", left, mid);
                cin >> resp;

                if (resp == 0) // all 3 tomes in (mid+1, right)
                {
                    left = mid+1;
                }
                else if (resp == total) // all 3 tomes in (left, mid)
                {
                    right = mid;
                }
                else
                {
                    if ((resp & (1LL << m)) == 0) // 2 tomes in (left, mid)
                    {
                        a = total ^ resp; // 3rd tome

                        right = mid;

                        while(left < right) // try to separate the reamining 2
                        {
                            mid = (right+left)/2;
                            printf("xor %lld %lld\n", left, mid);
                            cin >> resp;

                            if (resp == 0)
                            {
                                left = mid+1;
                            }
                            else if (resp == (total ^ a))
                            {
                                right = mid;
                            }
                            else
                            {
                                printf("ans %lld %lld %lld\n", a, resp, total ^ resp ^ a);
                                return;
                            }
                        }
                    }
                    else // 1st tome alone in (left, mid)
                    {
                        a = resp; // 1st tome

                        left = mid+1;

                        while(left < right) // try to separate other 2
                        {
                            mid = (right+left)/2;
                            printf("xor %lld %lld\n", left, mid);
                            cin >> resp;

                            if (resp == 0)
                            {
                                left = mid+1;
                            }
                            else if (resp == (total ^ a))
                            {
                                right = mid;
                            }
                            else
                            {
                                printf("ans %lld %lld %lld\n", a, resp, total ^ resp ^ a);
                                return;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if ((resp & (1LL << m)) == 0) // 2 tomes in (left, mid)
            {
                a = total ^ resp; // 3rd tome

                ll left = 1LL << m;
                ll right = min((1LL << (m+1))-1, n);

                while(left < right) // try to separate other 2 tomes
                {
                    ll mid = (right+left)/2;
                    printf("xor %lld %lld\n", left, mid);
                    cin >> resp;

                    if (resp == 0)
                    {
                        left = mid+1;
                    }
                    else if (resp == (total ^ a))
                    {
                        right = mid;
                    }
                    else
                    {
                        printf("ans %lld %lld %lld\n", a, resp, total ^ a ^ resp);
                        return;
                    }
                }
            }
            else
            {
                a = resp; // 1st tome

                ll left = 1LL;
                ll right = (1LL << m) - 1;

                while(left < right) // try to separate other 2 tomes
                {
                    ll mid = (right+left)/2;
                    printf("xor %lld %lld\n", left, mid);
                    cin >> resp;

                    if (resp == 0)
                    {
                        left = mid+1;
                    }
                    else if (resp == (total ^ a))
                    {
                        right = mid;
                    }
                    else
                    {
                        printf("ans %lld %lld %lld\n", a, resp, total ^ a ^ resp);
                        return;
                    }
                }
            }
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