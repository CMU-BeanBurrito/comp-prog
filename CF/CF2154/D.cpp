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

/**
 * Strategy:
 * 
 * Big picture: 
 * Corral the cat onto the shortest path between 1 and n by eliminating all other nodes.
 * Corral the cat to the destination by trimming the shortest path.
 * 
 * Useful concepts:
 * - Using property that all trees are bipartite, always ensure:
 *   - cat is on a red node (even depth) when destroying a blue node
 *   - cat is on a blue node (odd depth) when destroying a red node
 * - this will guarantee that cat is never killed
 * - this greatly simplifies tracking where the cat is, we do not care what specific level it is on
 * 
 * Note: "higher" depth = closer to root. numerically lesser depth.
 *       "lower" depth = further from root. numerically greater depth.
 * 
 * Phase 1: Mark graph with necessary metadata
 * - Use BFS to mark depth of each node
 * - Use DFS to find shortest path between 1 and n
 * 
 * Phase 2: Destroy all nodes, ignoring those that lie on the shortest path.
 * - Begin with the deepest nodes, move upwards towards root.
 *   - this prevents the cat from being trapped by being on a lower depth while a higher depth node is destroyed
 * - Move upwards to higher depth (towards root) if:
 *   - current depth is empty
 *   - current depth contains only a node from the shortest path
 * - Upon conclusion of this phase, only the shortest path remains.
 * 
 * Phase 3: Destroy all descendants of the destination.
 * - Begin with the deepest node, move upwards towards destination.
 * - Note that each depth in this phase (deeper than d[n]) has only 1 remaining node.
 * 
 * Phase 4: Destroy all ancestors of the destination.
 * - Begin with the root, move downwards towards destination.
 * - Note that each depth in this phase (less deep than d[n]) has only 1 remaining node.
 * 
 * Proof of operation bound:
 * - All nodes are destroyed except the destination (node n). This requires n-1 operations.
 * - Before each destruction, a move operation might be required. This requires at most n-1 operations.
 * - After each destruction, a move operation is required. This requires n-1 operations.
 */

// PUT GLOBALS HERE
#define MAXN 200'005
vector<vector<int>> g (MAXN); // adjacency list
vector<bool> vis (MAXN, false); // node visited?
vector<int> d (MAXN, 0); // depth
vector<set<int>> dmap (MAXN); // dmap[i] = set of all nodes at this depth
queue<int> q; // for BFS
stack<int> p; // for DFS
set<int> path; // contains all nodes on shortest path
int deepest = 0; // deepest level prior to any destruction

void bfs()
{
    d[1] = 0;
    vis[1] = true;
    q.push(1);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (!vis[v])
            {
                d[v] = d[u]+1;
                deepest = max(deepest, d[v]);
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs(int u, int dest)
{
    vis[u] = true;
    p.push(u);

    if (u == dest)
    {
        while(!p.empty())
        {
            int x = p.top();
            p.pop();
            path.insert(x);
        }

        return;
    }

    for (int v : g[u])
    {
        if (!vis[v]) dfs(v, dest);
    }

    if (!p.empty()) p.pop();
}

bool checklvl(int h)
{
    // level is empty
    if ((int)dmap[h].size() == 0) return false;

    // level contains 1 node and it is on the path
    if (((int)dmap[h].size() == 1) && (path.find(*dmap[h].begin()) != path.end())) return false;

    return true;
}

void solve() {
    int n; cin >> n;

    // construct graph
    for (int i = 0; i < n-1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // mark distance of nodes, construct dmap
    bfs();
    for (int i = 1; i <= n; i++) dmap[d[i]].insert(i);

    // find shortest path
    vis = vector<bool> (MAXN, false);
    dfs(1, n);

    // all move operations are stored as (1, 0)
    // this allowed all operations to be represented by pairs.
    // the 0 is simply discarded and is just a placeholder.
    vector<pair<int, int>> ans;

    int lvl = 0; // is the cat currently on an odd or even depth node?
    int h = deepest; // depth at which we are destroy nodes
    int numdel = 0; // number of destroyed nodes

    // Phase 2: Prune tree down to shortest path.
    while(numdel < n-(int)path.size()) 
    {
        // if the current depth is done, move up
        while(!checklvl(h)) h--;

        // pick an arbitrary node at this level to destroy. if it is on the shortest path, pick a different one.
        int del = *dmap[h].begin();
        if (path.find(del) != path.end()) del = *dmap[h].rbegin();

        // move cat, as it is on a node with the same color as the node we want to destroy
        if (lvl % 2 == h % 2)
        {
            ans.push_back(make_pair(1, 0));
            lvl = (lvl == 0 ? 1 : 0);
        }

        // destroy a node on the lowest depth
        ans.push_back(make_pair(2, del));
        dmap[h].erase(dmap[h].find(del));
        numdel++;

        // move cat, as we cannot have 2 destroy operations consecutively.
        ans.push_back(make_pair(1, 0));
        lvl = (lvl == 0 ? 1 : 0);
    }

    // Phase 3: Destroy all of the destination's descendants.

    h = (int)path.size()-1; // lowest depth in shortest path
    while(h > d[n])
    {
        // move cat, as it is on a node with the same color as the node we want to destroy
        if (lvl % 2 == h % 2)
        {
            ans.push_back(make_pair(1, 0));
            lvl = (lvl == 0 ? 1 : 0);
        }

        // destroy the node on the lowest depth
        int del = *dmap[h].begin();
        ans.push_back(make_pair(2, del));
        dmap[h].erase(dmap[h].find(del));
        numdel++;
        h--;

        // move cat, as we cannot have 2 destroy operations consecutively.
        ans.push_back(make_pair(1, 0));
        lvl = (lvl == 0 ? 1 : 0);
    }

    // Phase 4: Destroy all of the destination's ancestors.

    h = 0; // the root, the highest point in the tree (and shortest path)
    while(h < d[n])
    {
        // move cat, as it is on a node with the same color as the node we want to destroy
        if (lvl % 2 == h % 2)
        {
            ans.push_back(make_pair(1, 0));
            lvl = (lvl == 0 ? 1 : 0);
        }

        // delete the node on the highest depth
        int del = *dmap[h].begin();
        ans.push_back(make_pair(2, del));
        dmap[h].erase(dmap[h].find(del));
        numdel++;
        h++;

        // move cat, as we cannot have 2 destroy operations consecutively.
        ans.push_back(make_pair(1, 0));
        lvl = (lvl == 0 ? 1 : 0);
    }

    // Print answer
    printf("%d\n", (int)ans.size());

    for (auto p : ans)
    {
        if (p.first == 1) // move operation
        {
            printf("1\n");
        }
        else // destroy operation
        {
            printf("2 %d\n", p.second);
        }
    }

    // Clean up global data for next test case.
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        vis[i] = false;
        d[i] = 0;
        dmap[i].clear();
    }

    while(!p.empty()) p.pop();
    while(!q.empty()) q.pop();
    path.clear();
    deepest = 0;
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
