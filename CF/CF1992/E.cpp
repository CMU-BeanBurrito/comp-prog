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

int lg10(int n)
{
    int ans = 0;

    while(n > 0)
    {
        ans++;
        n /= 10;
    }

    return ans;
}

void solve() {
    int n; cin >> n;
    string sn = to_string(n);

    int cnt = 0;
    vector<pair<int, int>> ans;

    for (int a = 1; a <= 10000; a++)
    {
        int digits = a*lg10(n);

        for (int b = max(1, digits-6); b < digits; b++)
        {
            int right = n*a - b;

            string swrong = "";
            
            for (int i = 0; i < digits-b; i++)
            {
                swrong +=  sn[i%sn.length()];
            }

            int wrong = stoi(swrong);
        
            if (right == wrong)
            {
                cnt++;
                ans.push_back(make_pair(a, b));
            }
        }
    }

    printf("%d\n", cnt);
    
    for (auto p : ans)
    {
        printf("%d %d\n", p.first, p.second);
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}


