#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

void solve() {
   bool prevsweet = false;
   
   int n; cin >> n;
   
   for (int i = 0; i < n; i++)
   {
       string s; cin >> s;
       
       if (s == "sweet" && prevsweet && i != n-1)
       {
           printf("No\n");
           return;
       }
       else if (s == "sweet")
       {
           prevsweet = true;
       }
       else 
       {
           prevsweet = false;
       }
   }
   
   printf("Yes\n");
}

int main() {
    solve();
    
    return 0;
}
