#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

bool saltysort(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second) return a.first >= b.first;
    
    return a.second > b.second;
}

bool sweetsort(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first) return a.second >= b.second;
    
    return a.first > b.first;
}

void solve() {
   int n; cin >> n;
   ll x, y; cin >> x >> y;
   
   vector<pair<int, int>> v (n);
   
   for (int i = 0; i < n; i++)
   {
       cin >> v[i].first;
   }
   
   for (int i = 0; i < n; i++)
   {
       cin >> v[i].second;
   }
   
   int sweet = 0;
   ll sweetsum = 0;
   int salty = 0;
   ll saltysum = 0;
   
   sort(v.begin(), v.end(), sweetsort);
   
   for (int i = 0; i < n; i++)
   {
       sweetsum += v[i].first;
       saltysum += v[i].second;
       
       if (sweetsum > x || saltysum > y)
       {
           sweet = i+1;
           break;
       }
   }
   
   if (sweetsum <= x && saltysum <= y) sweet = n;
   
   sweetsum = 0;
   saltysum = 0;
   
   sort(v.begin(), v.end(), saltysort);
   
   for (int i = 0; i < n; i++)
   {
       sweetsum += v[i].first;
       saltysum += v[i].second;
       
       if (sweetsum > x || saltysum > y)
       {
           salty = i+1;
           break;
       }
   }
   
   if (sweetsum <= x && saltysum <= y) salty = n;
   
   printf("%d\n", min(sweet, salty));
}

int main() {
    solve();
    
    return 0;
}