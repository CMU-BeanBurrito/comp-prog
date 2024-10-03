#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

void solve() {
   int h, w; cin >> h >> w;
   
   int sr, sc; cin >> sr >> sc;
   
   // 0 indexing
   sr--;
   sc--;
   
   // false is empty, true is blocked
   vector<vector<bool>> board (h, vector<bool> (w, false));
   
   for (int i = 0; i < h; i++)
   {
       string s; cin >> s;
       for (int j = 0; j < w; j++)
       {
           if (s[j] == '#')
           {
               board[i][j] = true;
           }
       }
   }
   
   string x; cin >> x;
   
   for (char c : x)
   {
       if (c == 'U')
       {
           if (sr > 0 && !board[sr-1][sc])
           {
               sr--;
           }
       }
       else if (c == 'D')
       {
           if (sr < h-1 && !board[sr+1][sc])
           {
               sr++;
           }
       }
       else if (c == 'L')
       {
           if (sc > 0 && !board[sr][sc-1])
           {
               sc--;
           }
       }
       else if (c == 'R')
       {
           if (sc < w-1 && !board[sr][sc+1])
           {
               sc++;
           }
       }
   }
   
   // back to 1-indexing
   printf("%d %d\n", sr+1, sc+1);
}

int main() {
    solve();
    
    return 0;
}
