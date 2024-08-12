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

void solve() {
    int n; cin >> n;

    vector<int> a (n);
    vector<int> b (n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if (a == b)
    {
        printf("Bob\n");
    }
    else
    {
        reverse(b.begin(), b.end());
        
        if (a == b)
        {
            printf("Bob\n");
        }
        else
        {
            printf("Alice\n");
        }
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



