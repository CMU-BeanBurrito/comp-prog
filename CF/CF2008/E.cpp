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

void solve() {
    int n; cin >> n;

    string s; cin >> s;

    if (n % 2 == 0)
    {
        map<char, int> even;
        map<char, int> odd;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) even[s[i]]++;
            if (i % 2 == 1) odd[s[i]]++;
        }

        int ans = 0;
        int mx = 0;

        for (auto p : even)
        {
            mx = max(p.second, mx);
        }

        ans += (n/2)-mx;
        mx = 0;

        for (auto p : odd)
        {
            mx = max(p.second, mx);
        }

        ans += (n/2)-mx;

        printf("%d\n", ans);
        return;
    }

    if (n == 1 || n == 3)
    {
        printf("1\n");
        return;
    }

    int ans = 1;

    vector<vector<int>> preodd (26, vector<int> (n, 0));
    vector<vector<int>> preeven (26, vector<int> (n, 0));
    vector<vector<int>> postodd (26, vector<int> (n, 0));
    vector<vector<int>> posteven (26, vector<int> (n, 0));

    for (int i = 1; i < n; i++)
    {
        int cidx = s[i-1]-'a';
        for (int c = 0; c < 26; c++)
        {
            preeven[c][i] = preeven[c][i-1];
            if (i % 2 == 1 && c == cidx)
            {
                preeven[cidx][i]++;
            }

            preodd[c][i] = preodd[c][i-1];
            if (i % 2 == 0 && c == cidx)
            {
                preodd[cidx][i]++;
            }
        }
    }

    for (int i = n-2; i >= 0; i--)
    {
        int cidx = s[i+1]-'a';
        for (int c = 0; c < 26; c++)
        {
            posteven[c][i] = posteven[c][i+1];
            if (i % 2 == 1 && c == cidx)
            {
                posteven[cidx][i]++;
            }

            postodd[c][i] = postodd[c][i+1];
            if (i % 2 == 0 && c == cidx)
            {
                postodd[cidx][i]++;
            }

        }
    }

    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int codd = 0; codd < 26; codd++)
        {
            for (int ceven = 0; ceven < 26; ceven++)
            {
                int test = preeven[ceven][i] + preodd[codd][i] + posteven[codd][i] + postodd[ceven][i];
                if(mx < test)
                {
                    //printf("%d %d %d %d\n", ceven, codd, i, test);
                    mx = test;
                }

            }
        }
    }

    ans += (n-mx-1);

    printf("%d\n", ans);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



