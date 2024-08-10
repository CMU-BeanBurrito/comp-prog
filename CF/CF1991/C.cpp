#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;

    int odd = 0;
    int even = 0;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        if (x % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    
    if (odd > 0 && even > 0)
    {
        printf("-1\n");
        return;
    }

    int power = 1 << 29;

    cout << (even > 0 ? 31 : 30) << endl;

    for (int i = 0; i < 30; i++, power /= 2)
    {
        cout << power << " " ;
    } 
    
    if (even > 0) cout << 1 << " ";

    cout << endl;
}

int main() {
    int t; cin >> t;

    while(t--)
    {
        solve();
    }
}