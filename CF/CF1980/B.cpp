#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    int n, f, k; cin >> n >> f >> k;

    f--; // change to 0-indexing

    int fav;

    vector<int> v (n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i == f) fav = v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int left = -1;
    int right = n;

    for (int i = 0; i < n; i++)
    {
        if (left == -1 && v[i] == fav) left = i;
        if (v[i] < fav) 
        {
            right = i;
            break;
        }
    }

    if (k <= left)
    {
        cout << "NO" << endl;
    }
    else if (k < right)
    {
        cout << "MAYBE" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



