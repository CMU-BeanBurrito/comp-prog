#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

int gcd(int a, int b){
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

void solve() {
    int n; cin >> n;

    vector<int> v (n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int down = -1;

    for (int i = 1; i < n-1; i++)
    {
        if (gcd(v[i], v[i+1]) < gcd(v[i-1], v[i]))
        {
            down = i;
        }
    }
    
    if (down == -1) {
        cout << "YES" << endl;
        return;
    }

    vector<int> a (n-1);
    vector<int> b (n-1);
    vector<int> c (n-1);

    memcpy(a.data(), v.data(), sizeof(int)*(down-1));
    memcpy(&a.data()[down-1], &v.data()[down], sizeof(int)*(n-down));
    
    memcpy(b.data(), v.data(), sizeof(int)*(down));
    memcpy(&b.data()[down], &v.data()[down+1], sizeof(int)*(n-down-1));
    
    memcpy(c.data(), v.data(), sizeof(int)*(down+1));
    memcpy(&c.data()[down+1], &v.data()[down+2], sizeof(int)*(n-down-2));

    bool good = true;
    
    for (int i = 1; i < n-2; i++)
    {
        if (gcd(a[i], a[i+1]) < gcd(a[i-1], a[i]))
        {
            good = false;
            break;
        }
    }
    
    if (good) {
        cout << "YES" << endl;
        return;
    } else {
        good = true;
    }

    
    for (int i = 1; i < n-2; i++)
    {
        if (gcd(b[i], b[i+1]) < gcd(b[i-1], b[i]))
        {
            good = false;
            break;
        }
    }

    if (good) {
        cout << "YES" << endl;
        return;
    } else {
        good = true;
    }

    for (int i = 1; i < n-2; i++)
    {
        if (gcd(c[i], c[i+1]) < gcd(c[i-1], c[i]))
        {
            good = false;
            break;
        }
    }

    if (good) {
        cout << "YES" << endl;
        return;
    }
    
    cout << "NO" << endl;
    
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    return 0;
}



