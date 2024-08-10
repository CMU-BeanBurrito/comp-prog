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

vector<int> path(int x, int y)
{
    vector<int> left, right;

    // one side of the path to the LCA
    while(__lg(x) > __lg(y))
    {
        left.push_back(x);
        x /= 2;
    }

    // other side
    while(__lg(y) > __lg(x))
    {
        right.push_back(y);
        y /= 2;
    }

    // x and y at the same level, now find the LCA
    while(x != y)
    {
        left.push_back(x);
        right.push_back(y);
        x /= 2;
        y /= 2;
    }
    left.push_back(x);

    reverse(right.begin(), right.end());
    
    // merge into one path
    for (int r : right) 
    {
        left.push_back(r);
    }

    return left;
}

void solve()
{
    int n; cin >> n;

    vector<int> a (n);

    for (int i = 0; i < n; i++) cin >> a[i];

    // special cases

    int first = -1; // first index that is not -1
    int last = -1; // last index that is not -1

    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1 && first == -1)
        {
            first = i;
            last = i;
        }
        else if (a[i] != -1)
        {
            last = i;
        }
    }

    if (first == -1) // all -1
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", 1 + (i%2)); // 1, 2, 1, 2....
        } printf("\n");
        return;
    }

    // fill in before first
    for (int i = first-1; i >= 0; i--)
    {
        if ((first-i)%2 == 1)
        {
            a[i] = a[i+1]*2;
        }
        else
        {
            a[i] = a[i+1]/2;
        }
    }

    // fill in after last
    for (int i = last+1; i < n; i++)
    {
        if ((i-last)%2 == 1)
        {
            a[i] = a[i-1]*2;
        }
        else
        {
            a[i] = a[i-1]/2;
        }
    }

    int left = first;
    for (int i = first+1; i <= last; i++)
    {
        if (a[i] == -1) continue;
        int right = i;

        vector<int> pathres = path(a[left], a[right]);

        // path is too large or has the wrong parity, no solution
        if (pathres.size() % 2 != (right-left+1) % 2 || pathres.size() > right-left+1)
        {
            printf("-1\n");
            return;
        }

        // augment path to be the right size
        while(pathres.size() < right-left+1)
        {
            int last = pathres.back();
            pathres.push_back(last*2);
            pathres.push_back(last);
        }

        memcpy(&a[left], &pathres[0], (right-left+1)*sizeof(int));

        left = right;

    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    } printf("\n");
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



