#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int b, c, h; cin >> b >> c >> h;
    
    if (b < c+h+1) {
        cout << (2*b)-1 << endl;
    } else {
        cout << (2*(c+h))+1 << endl;
    }
   
}

int main()
{
    int numc;
    cin >> numc;
    
    while(numc--) {
        solve();
    }
    
    return 0;
}
