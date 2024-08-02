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
 
    int best = 0;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        
        /*
            Need to have an even number of elements to the left, or
            an even number of elements to the right in order for this
            element to be a candidate for last remaining.
        */
        if (i % 2 == 0 || n-i-1 % 2 == 0)
        {
            best = max(best, x);
        }
    }
 
    printf("%d\n", best);
}

int main() {
    int t; scanf("%d\n", t);
    
    while(t--) {
        solve();
    }
    
    return 0;
}



