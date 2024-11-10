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
    int n, m; cin >> n >> m;
    vector<vector<int>> a (n, vector<int> (m));

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '.')
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = -1;
            }
        }
    }

    int elbow = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0) continue;

            // elbows do not have any diagonal neighbors
            if (i > 0 && j > 0 && a[i-1][j-1] != 0) continue;
            if (i > 0 && j < m-1 && a[i-1][j+1] != 0) continue;
            if (i < n-1 && j > 0 && a[i+1][j-1] != 0) continue;
            if (i < n-1 && j < m-1 && a[i+1][j+1] != 0) continue;

            bool up = false; bool down = false; bool left = false; bool right = false;
            if (i > 0 && a[i-1][j] != 0) up = true;
            if (i < n-1 && a[i+1][j] != 0) down = true;
            if (j > 0 && a[i][j-1] != 0) left = true;
            if (j < m-1 && a[i][j+1] != 0) right = true;

            if (up && right && !down && !left)
            {
                if (a[i][j] != -1 || a[i-1][j] != -1 || a[i][j+1] != -1)
                {
                    printf("NO\n");
                    return;
                }

                elbow++;
                a[i][j] = elbow;
                a[i-1][j] = elbow;
                a[i][j+1] = elbow;
            }

            if (!up && right && down && !left)
            {
                if (a[i][j] != -1 || a[i][j+1] != -1 || a[i+1][j] != -1)
                {
                    printf("NO\n");
                    return;
                }

                elbow++;
                a[i][j] = elbow;
                a[i][j+1] = elbow;
                a[i+1][j] = elbow;
            }

            if (!up && !right && down && left)
            {
                if (a[i][j] != -1 || a[i+1][j] != -1 || a[i][j-1] != -1)
                {
                    printf("NO\n");
                    return;
                }

                elbow++;
                a[i][j] = elbow;
                a[i+1][j] = elbow;
                a[i][j-1] = elbow;
            }

            if (up && !right && !down && left)
            {
                if (a[i][j] != -1 || a[i-1][j] != -1 || a[i][j-1] != -1)
                {
                    printf("NO\n");
                    return;
                }

                elbow++;
                a[i][j] = elbow;
                a[i-1][j] = elbow;
                a[i][j-1] = elbow;
            }
        }
    }

    vector<pair<int, int>> nb = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0) continue;

            if (a[i][j] == -1)
            {
                printf("NO\n");
                return;
            }

            for (auto move : nb)
            {
                int r = i + move.first;
                int c = j + move.second;

                if (0 <= r && r < n && 0 <= c && c < m)
                {
                    if (a[r][c] != 0 && a[r][c] != a[i][j])
                    {
                        printf("NO\n");
                        return;
                    }
                }
            }
        }
    }

    printf("YES\n");
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