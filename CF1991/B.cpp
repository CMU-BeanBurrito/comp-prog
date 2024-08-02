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

void solve() {
    int n; cin >> n;
 
    vector<int> b (n-1);
    vector<int> a (n);
 
    for (int i = 0; i < n-1; i++)
    {
        cin >> b[i];
    }
 
    if (n == 2)
    {
        printf("%d %d\n", b[0], b[0]);
        return;
    }
 
    a[0] = b[0];
    a[n-1] = b[n-2];
 
    for (int i = 1; i < n-1; i++)
    {
        a[i] = b[i] | b[i-1];
 
        if ((a[i] & a[i-1]) != b[i-1])
        {
            printf("-1\n");
            return;
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    } printf("\n");
}

int main() {
    int t; scanf("%d\n", t);
    
    while(t--) {
        solve();
    }
    
    return 0;
}



