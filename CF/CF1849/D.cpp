#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    
    vector<int> v (n);
    
    for (int i = 0; i < n; i++) cin >> v[i];
    
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    
    int ans = 0;
    
    // first element
    if (!v[0]) {
        if (v[1]) { // can be spread from next element
            v[1]--;
        } else { // can't be spread from next, pay
            ans++;
        }
    } else { // pay for this one to spread
        ans++;
    }
    
    for (int i = 1; i < n-1; i++) {
        if (v[i-1]) { // spread from prev if possible
            v[i-1]--;
        } else if (!v[i] && v[i+1]) { // spread from next if necessary
            v[i+1]--;
        } else { // pay
            ans++;
        }
        
    }
    
    // last element
    if (!v[n-2]) { // cannot be spread from previous, pay
        ans++;
    }
    
    cout << ans << endl;
}

int main()
{
    solve();
    
    return 0;
}
