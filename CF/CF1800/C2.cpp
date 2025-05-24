/*
    Author: BeanBurrito
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    
    map<int, int> m;
    set<int> s;
    
    ll sum = 0;
    
    for (int i = 0; i < n; i++) {
        //cout << i << " " << n << endl;
        int x; cin >> x;
        if (x == 0) {
            if (s.empty()) continue;
            int max = *s.rbegin();
            m[max]--;
            if (!m[max]) {
                s.erase(max);
            }
            sum += max;
        } else {
            s.insert(x);
            m[x]++;
        }
        //cout << i << " " << n << endl;
    }
    
    cout << sum << endl;
}

int main()
{
    int t; cin >> t;
    
    while(t--) {
        //cout << t << endl;
        solve();
    }

    return 0;
}
