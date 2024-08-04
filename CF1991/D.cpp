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

#define MOD 1000000007

void solve() {
    int n; cin >> n;

    switch (n)
    {
        case 1:
            printf("1\n1\n");
            return;
        
        case 2:
            printf("2\n1 2\n");
            return;
        
        case 3:
            printf("2\n1 2 2\n");
            return;
        
        case 4:
            printf("3\n1 2 2 3\n");
            return;

        case 5:
            printf("3\n1 3 2 3 2\n");
            return;
        
        default: // 6 or greater
            printf("4\n");
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", (i%4)+1);

            }

            printf("\n");
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



