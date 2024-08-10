/*
    Author: BeanBurrito
*/

#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long; 

void solve() {
    int n; cin >> n;
    string s; cin >> s;
 
    vector<int> v (n);
    int left = 0;
    int right = 0;
    int leftfs = 0;
    int rightfs = 0;
 
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            v[i] = 0;
            left++;
        }
        else if (s[i] == ')')
        {
            v[i] = 1;
            right++;
        }
        else
        {
            v[i] = 2;
        }
    }
 
    v[0] = 0;
    left++;
    leftfs++;
    
    //cout << left << " " << right << endl;
 
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1)
        {
            if (v[i] == 0)
            {
                leftfs++;
            }
            else
            {
                rightfs++;
            }
            continue;
        }
 
        if (left == n/2)
        {
            v[i] = 1;
            right++;
            rightfs++;
        }
        else if (right == n/2)
        {
            v[i] = 0;
            left++;
            leftfs++;
        }
        else
        {
            if (v[i-1] == 0)
            {
                v[i] = 1;
                right++;
                rightfs++;
            }
            else if (v[i+1] == 1)
            {
                v[i] = 0;
                left++;
                leftfs++;
            }
            else
            {
                if (leftfs > rightfs)
                {
                    v[i] = 1;
                    right++;
                    rightfs++;
                }
                else
                {
                    v[i] = 0;
                    left++;
                    leftfs++;
                }
            }
        }
    }
    
    vector<int> lefts;
    ll cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            lefts.push_back(i);
        }
        else
        {
            cost += i-lefts.back();
            lefts.pop_back();
        }
    }   
 
    cout << cost << endl;
}
 
int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



