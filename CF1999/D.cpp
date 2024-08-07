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

#define MOD 1000000007

void solve() {
    string s, t;
    cin >> s;
    cin >> t;

    
    int n = s.length();
    int m = t.length();

    int sptr = 0;

    for (int i = 0; i < m; i++) // for each char in t
    {
        bool good = false; // is t[i] fulfilled

        while(sptr < n) // look for the earliest ? or match in s
        {
            if (s[sptr] == t[i] || s[sptr] == '?')
            {
                if (s[sptr] == '?') s[sptr] = t[i];

                sptr++;
                good = true; // t[i] fulfilled
                break;
            }

            sptr++;
        }

        if (!good) // t[i] not fulfilled, don't need to check rest of t
        {
            printf("NO\n");
            return;
        }
    }

    // all of t[i] was fulfilled

    while(sptr < n) // fill in remaining ? with any letter
    {
        if (s[sptr] == '?') s[sptr] = 'x';
        sptr++;
    }

    printf("YES\n");
    cout << s << endl;
    
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



