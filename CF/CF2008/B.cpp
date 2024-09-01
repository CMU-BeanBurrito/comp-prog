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

int rt(int n)
{
    int l = 1;
    int r = 447;

    while(l <= r)
    {
        int mid = l + (r-l)/2;

        if (mid*mid == n)
        {
            return mid;
        }
        else if (mid*mid < n)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }

    return -1;
}

void solve() {
    int n; cin >> n;

    int sq = rt(n);

    string s; cin >> s;

    if (sq == -1)
    {
        printf("No\n");
        return;
    }

    for (int i = 0; i < sq; i++)
    {
        for (int j = 0; j < sq; j++)
        {
            if (i == 0 || i == sq-1 || j == 0 || j == sq-1)
            {
                if (s[(i*sq)+j] == '0')
                {
                    printf("No\n");
                    return;
                }
            }
            else
            {
                if (s[(i*sq)+j] == '1')
                {
                    printf("No\n");
                    return;
                }
            }
        }
    }

    printf("Yes\n");
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



