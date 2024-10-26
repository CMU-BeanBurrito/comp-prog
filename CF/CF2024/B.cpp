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

    // PUT GLOBALS HERE

    void solve() {
        int n, k; cin >> n >> k;
        map<int, int> mp;
        int vend = n; // stocked slots remaining
        int mxtake = 0; // maximum taken from any single machine
        int ans = 0; // presses used so far

        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            mp[x]++;
        }

        for (auto p : mp)
        {
            // p.first is the minimum nonzero number of cans in any machine

            if (1LL*k <= 1LL*vend*(p.first-mxtake)) // if we hit each stocked slot p.first times, do we have enough
            {
                ans += k;
                break;
            }

            ans += vend*(p.first-mxtake); // we did hit each stocked slot min times (minimum cans aside from 0)
            k -= vend*(p.first-mxtake); // we got this many cans

            mxtake = p.first; // each stocked slot has fewer cans now
            ans += p.second; // p.second machines were emptied on this turn, we might hit each once more
            vend -= p.second; // p.second machines were emptied on this turn
        }

        printf("%d\n", ans);
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

