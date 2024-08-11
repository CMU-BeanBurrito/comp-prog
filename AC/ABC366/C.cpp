/*
    Author: BeanBurrito
*/

#include <cstdio>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long; 

#define MOD 1'000'000'007

void solve() {
    int q; cin >> q;

    map<int, int> mp;
    int distinct = 0;

    while(q--)
    {
        int qu; cin >> qu;

        if (qu == 1)
        {
            int x; cin >> x;
            
            if (mp[x] == 0) distinct++;
            mp[x]++;
        }
        else if (qu == 2)
        {
            int x; cin >> x;
            if (mp[x] == 1) distinct--;
            mp[x]--;
        }
        else
        {
            printf("%d\n", distinct);
        }
    }

}

int main() {
    solve();
    return 0;
}



