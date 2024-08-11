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
    int n; cin >> n;
    vector<vector<vector<int>>> a (n, vector<vector<int>> (n, vector<int> (n, 0)));
    vector<vector<vector<int>>> p (n+1, vector<vector<int>> (n+1, vector<int> (n+1, 0)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0;  j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> a[i][j][k];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1;  j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {

                p[i][j][k] = p[i - 1][j][k] + p[i][j - 1][k] + p[i][j][k - 1] 
                           - p[i - 1][j - 1][k] - p[i][j - 1][k - 1] - p[i - 1][j][k - 1] 
                           + p[i - 1][j - 1][k - 1] + a[i - 1][j - 1][k - 1];
            }
        }
    }

    int q; cin >> q;

    while(q--)
    {
        int lx, rx, ly, ry, lz, rz; cin >> lx >> rx >> ly >> ry >> lz >> rz;

        if (lx != rx && ly != ry && lz != rz)
        {
            printf("%d\n", p[rx][ry][rz]-p[lx-1][ly-1][lz-1]);
        }
        else if (lx != rx && ly != ry && lz == rz)
        {
            printf("%d\n", p[rx][ry][rz]-p[lx-1][ly-1][lz-1]);
        }
        else if (lx != rx && ly == ry && lz != rz)
        {
            
        }
        else if (lx != rx && ly == ry && lz == rz)
        {
            
        }
        else if (lx == rx && ly != ry && lz != rz)
        {
            
        }
        else if (lx == rx && ly != ry && lz == rz)
        {
            
        }
        else if (lx == rx && ly == ry && lz != rz)
        {
            
        }
        else if (lx == rx && ly == ry && lz == rz)
        {
            
        }

        printf("%d\n", p[rx][ry][rz]-p[lx-1][ry][rz]-p[rx][ly-1][rz]-p[rx][ry][lz-1]);
    }
}

int main() {
    solve();
    return 0;
}



