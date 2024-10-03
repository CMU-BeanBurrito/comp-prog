/**
 * Author: BeanBurrito
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> a (200);
int n, m; 
map<int, int> mp1;
map<int, int> mp2;

void donothing() { // discard nothing
    cout << "- 0" << endl;
    cout.flush();
}

void point(int x) { // give our answer
    cout << "! " << x << endl;
    cout.flush();
}

void readroom(int mp_num) { // scan room
    if (mp_num == 1) mp1.clear();
    if (mp_num == 2) mp2.clear();
    
    for (int i = 0; i < n-m; i++) {
        cin >> a[i];
        if (mp_num == 1) {
            mp1[a[i]]++;
        } else {
            mp2[a[i]]++;
        }
    }
}

void discard(int typeB) { // discard objects that are not typeB
    m = 0;
    vector<int> discards;
    for (int i = 0; i < n; i++) {
        if (a[i] != typeB) {
            m++;
            discards.push_back(i+1); // elements are 1 indexed
        } 
    }
    
    cout << "- " << m << " ";
    for (int i = 0; i < m; i++) {
        cout << discards[i] << " ";
    } cout << endl;
    cout.flush();
    
    mp1.clear();
    mp2.clear();
    
    mp1[typeB] = n-m;
    mp2[typeB] = n-m;
}

void solve() {
    cin >> n;
    m = 0;
    
    mp1.clear();
    mp2.clear();
    
    // first visit
    readroom(1);
    donothing();
    
    // second visit
    readroom(2);
    
    int typeB = -1;
    for (int i = 1; i <= 9; i++) { // check if mimic changed
        if (mp2[i] > mp1[i]) {
            typeB = i;
        }
    }
    
    if (typeB != -1) { // mimic changed form
        discard(typeB);
    } else {
        donothing();
    }
    
    // third visit
    readroom(1);
    
    int typeC = -1;
    
    if (typeB == -1) { // still have not discarded
        for (int i = 1; i <= 9; i++) { // check if mimic changed
            if (mp1[i] > mp2[i]) {
                typeB = i;
            }
        }
        discard(typeB);
    } else { // did discard
        for (int i = 1; i <= 9; i++) { // check if mimic changed
            if (mp1[i] > mp2[i]) { // found mimic, find index and return
                typeC = i;
                for (int j = 0; j < n-m; j++) {
                    if (a[j] == typeC) {
                        point(j+1);
                        return;
                    }
                }
            }
        }
        
        donothing();
    }
    
    // fourth visit
    readroom(2);
    
    for (int i = 1; i <= 9; i++) { // check if mimic changed
        if (mp2[i] > mp1[i]) { // found mimic, find index and return
            typeC = i;
            for (int j = 0; j < n-m; j++) {
                if (a[j] == typeC) {
                    point(j+1);
                    return;
                }
            }
        }
    }
    
    donothing();
    
    // fifth visit
    readroom(1);
    
    for (int i = 1; i <= 9; i++) { // check if mimic changed
        if (mp1[i] > mp2[i]) { // found mimic, find index and return
            typeC = i;
            for (int j = 0; j < n-m; j++) {
                if (a[j] == typeC) {
                    point(j+1);
                    return;
                }
            }
        }
    }
    
}

int main()
{
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}