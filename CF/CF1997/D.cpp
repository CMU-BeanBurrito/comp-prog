/*
    Author: BeanBurrito
*/

#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long; 

vector<int> vals (200001, -1);
vector<vector<int>> g (200001, vector<int>());
 
void maximize(int root)
{
    int minchild = INT_MAX;
    for (int child : g[root])
    {
        maximize(child);
    }
 
    for (int child : g[root])
    {
        minchild = min(minchild, vals[child]);
    }
    
    if (root == 1)
    {
        if (minchild != INT_MAX && minchild > 0) // take all
        {
            vals[root] += minchild;
        }
    }
    else
    {
        if (minchild == INT_MAX) return;
        
        if (minchild < vals[root])
        {
            vals[root] = minchild;
        }
        else
        {
            vals[root] += (minchild - vals[root])/2;
        }
    }
    
}
 
void solve() {
    int n; cin >> n;
 
    for (int i = 1; i <= n; i++)
    {
        cin >> vals[i];
    }
 
    for (int i = 2; i <= n; i++)
    {
        int p; cin >> p;
        g[p].push_back(i);
    }
 
    maximize(1);
 
    cout << vals[1] << endl;
    
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }
}
 
int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



