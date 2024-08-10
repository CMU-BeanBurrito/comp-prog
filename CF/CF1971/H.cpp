#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define n(x) (x ^ 0x00000001)

vector<vector<int>> g (1005); // adj list version of graph for efficiency
vector<vector<int>> ginv (1005); // transposed version of this graph
vector<bool> vis (1005, false);
vector<int> finish; // stack, add node when it finishes DFS
vector<int> component (1005, -1); // table for which SCC each node is assigned to

void visit (vector<vector<int>>& gr, int s) {
    vis[s] = true; // mark as visited

    for (int v : gr[s]) // recursively call for any unvisited neighbors
    {
        if (!vis[v]) visit(gr, v);
    }
    
    finish.push_back(s); // add to stack
}

void assign (vector<vector<int>>& gr, int s, int comp_num) {
    component[s] = comp_num; // assign SCC number

    for (int v : gr[s]) // do the same for any unassigned neighbors
    {
        if (component[v] == -1) assign(gr, v, comp_num);
    }
}

void solve() {
    /*
    Strategy: Construct a 2-SAT problem.

    Solve the 2-SAT problem by seeing if any complementary variables
    are in the same strongly connected component.

    Construct graph using implications (see video).

    Kosaraju's Algorithm for finding SCCs:
    Run DFS on graph, push each node to stack when the search of its subtree is done.
    Transpose graph (reverse all edges).
    Until stack is empty: pop off a node. If it has not been assigned to an SCC,
    assign it and run a DFS, assigning all nodes encountered in this search.
    If it is assigned, do nothing and pop off next node.
    The group of nodes uncovered by each DFS is an SCC.

    Now go through each variable and its complement and see they are in the same SCC.
    */

    int rows = 3; int n; cin >> n; // n is cols

    // grid (in the game)
    vector<vector<int>> grid (3, vector<int> (n));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // routine for cleaning global data
    finish.clear();
    for (int i = 2; i < 1005; i++)
    {
        g[i].clear();
        ginv[i].clear();
        vis[i] = false;
        component[i] = -1;
    }


    // var i is node 2i, var ~i is node 2*(abs(i)) + 1
    // starting at var i with node 2, no node 0, 1

    for (int j = 0; j < n; j++)
    {
        int var1 = grid[0][j] > 0 ? 2*abs(grid[0][j]) : 2*(abs(grid[0][j]))+1;
        int var2 = grid[1][j] > 0 ? 2*abs(grid[1][j]) : 2*(abs(grid[1][j]))+1;
        int var3 = grid[2][j] > 0 ? 2*abs(grid[2][j]) : 2*(abs(grid[2][j]))+1;
        
        // (var1 or var2) and (var2 or var3) and (var3 or var1)
        // (~var1 -> var2) and (~var2 -> var1) and (~var2 -> var3) and (~var3 -> var2) and (~var3 -> var1) and (~var1 -> var3)
        
        // Construct graph
        if (n(var1) != var2) g[n(var1)].push_back(var2);
        if (n(var2) != var1) g[n(var2)].push_back(var1);
        if (n(var2) != var3) g[n(var2)].push_back(var3);
        if (n(var3) != var2) g[n(var3)].push_back(var2);
        if (n(var3) != var1) g[n(var3)].push_back(var1);
        if (n(var1) != var3) g[n(var1)].push_back(var3);

        // Construct transposed graph
        if (var2 != n(var1)) ginv[var2].push_back(n(var1));
        if (var1 != n(var2)) ginv[var1].push_back(n(var2));
        if (var3 != n(var2)) ginv[var3].push_back(n(var2));
        if (var2 != n(var3)) ginv[var2].push_back(n(var3));
        if (var1 != n(var3)) ginv[var1].push_back(n(var3));
        if (var3 != n(var1)) ginv[var3].push_back(n(var1));
    }
    
    // run DFS on graph
    for (int i = 2; i < 2*n+2; i++)
    {
        if (!vis[i]) visit(g, i);
    }

    // assign nodes to SCCs using the transposed graph
    int comp_num = 1;
    for (int i = finish.size()-1; i >= 0; i--)
    {
        int node = finish[i];

        if (component[node] == -1) // new SCC
        {
            assign(ginv, node, comp_num);
            comp_num++;
        }
    }

    // check if any complementary variables (x and ~x) are in the same SCC (this would be a contradiction)
    for (int i = 2; i < 2*n+2; i+=2)
    {
        if (component[i] == component[i+1]) // contradiction, Alice cannot win
        {
            printf("NO\n");
            return;
        }
    }

    printf("YES\n"); // There is a valid assignment such that Alice can win
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}




