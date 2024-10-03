/**
 * Author: BeanBurrito
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int g[1024][1024];
vector<int> dist (1024);
vector<bool> vis (1024);
set<pair<int, int>> unvis;

void djikstra(int s, int dest, int nodes) {
    // set distance of initial node to 0
    dist[s] = 0;
    auto start = unvis.find({INT_MAX, s});
    unvis.erase(start);
    unvis.insert({0, s});
    
    while(!unvis.empty()) {
        for (int i = 0; i < nodes; i++) {
		
        	if (g[s][i] == INT_MAX) continue; // not neighbors
			
            int nb = i; // neighbor's ID
            
            if (!vis[nb]) { // if neighbor is visited, do nothing
            
                auto it = unvis.find({dist[nb], nb}); 
                
                dist[nb] = min(dist[nb], dist[s]+g[s][nb]); // update neighbor distance in table
                
                unvis.erase(it); // update neighbor distance in unvis set
                unvis.insert({dist[nb], nb});
                
            }
        }
        
        // done with s, mark it visited and remove it from unvis
        vis[s] = true;
        auto it = unvis.find({dist[s], s});
        unvis.erase(it);
        
        // next vertex to explore from
        pair<int, int> p = *(unvis.begin());
        
        if (vis[dest] == true) { // we found the shortest path to dest, a.k.a the shortest possible time Rudolph can be completely cured
            cout << dist[dest] << endl;
            return;
        } else if (p.first == INT_MAX) { // this vertex is unreachable, we have explored all states possible from Rudolph's initial condition
            cout << -1 << endl;
            return;
        }
        
        // update s and run Dijkstra's from there
        s = p.second;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    
    int nodes = (1 << n);
    
    //reset globals
    unvis.clear();
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) g[i][j] = INT_MAX;
        dist[i] = INT_MAX;
        vis[i] = false;
        unvis.insert({INT_MAX, i});
    }
    
    string s; cin >> s;
    int start = 0;
    
    for (int i = 0; i < n; i++) { // initial condition
        if (s[i] == '1') start += (1 << (n-i-1));
    }
    
    for (int i = 0; i < m; i++) { // build graph
        int d; cin >> d;
        string srem; cin >> srem;
        string sadd; cin >> sadd;
        
        int rem = 0; int add = 0;
        
        for (int i = 0; i < n; i++) { // convert medicine's bitstring to number
            if (srem[i] == '1') rem += (1 << (n-i-1));
            if (sadd[i] == '1') add += (1 << (n-i-1));
        }
        
        for (int u = 0; u < nodes; u++) { // if we take this medicine, we will go from u to v
            int v = (u & ~rem) | add;
            g[u][v] = min(g[u][v], d);
        }
    }
   
    djikstra(start, 0, nodes);
}

int main()
{
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}