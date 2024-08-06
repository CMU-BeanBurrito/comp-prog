#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

// We are splitting the list into groups.
// Two numbers x, y are in the same group if and only if x/4 == y/4
// Grp struct contains all numbers in the list that are in the same group

struct Grp {
    int id = -1; // unique ID/key used for this group
    int idx = 0; // pointer to the next member that hasn't be inserted into the final list
    vector<int> members;
};

void solve() {
    int n; cin >> n;
    
    vector<int> v (n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // Key: id of Grp
    // Value: Grp that owns this index
    map<int, Grp> mp;
    
    for (int i = 0; i < n; i++) {
        int group = v[i]/4*4;
        if (mp[group].id == -1) { // this element's group doesn't exist yet
            Grp g;
            g.id = group;
            g.members.push_back(v[i]);
            mp[g.id] = g;
        } else { // group already exists, add this member to it
            mp[group].members.push_back(v[i]);
        }
    }
    
    
    for (auto p : mp) { // sort each group's members
        if (mp[p.first].id != -1) sort(mp[p.first].members.begin(), mp[p.first].members.end());
    }
    
    
    for (int i = 0; i < n; i++) {
        int group = v[i]/4*4; // id of group that owns this index
        
        v[i] = mp[group].members[mp[group].idx]; // member of group that belongs here
        
        mp[group].idx++; // increment index so next member is used next time we see an index owned by this group
    }
    
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    } cout << endl;
    
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}




