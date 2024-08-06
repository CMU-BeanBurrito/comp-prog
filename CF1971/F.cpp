#include<iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void solve() {
    ll r; cin >> r;
    
    int cnt = 0;
    
    /**
     * Strategy: 
     * 
     * First of all, only count points in Quadrant 1 (and then multiply by 4).
     * 
     * To do this, we have to choose whether to include all points on +y axis
     * or all points on +x axis. This is required so we maintain symmetry and 
     * can multiply by 4 at the end.
     * 
     * This implementation will include the +y axis and exclude the +x axis.
     * 
     * We now have an inner and outer arc and need to search the space between them.
     * 
     * Method for the search:
     * - for each x coordinate:
     *      - start at the height of the outer arc (which is considered out of bounds)
     *      - walk downwards, counting the number of steps that are "in bounds"
     *      - stop walking when we are below the inner arc (at which point we are out of bounds)
     *      - move one x coordinate to the right
     * 
     * Optimization: The starting height for coordinate x+1 is at most the starting
     * height for coordinate x. So before we begin walking downwards for coordinte x,
     * save the height so we can start there when we move to x+1
     * 
     */
     
     
    /**
     * Starting height for x=0. We know this is the only valid height for x=0
     * because we are standing on the inner arc. If we step down we will clearly be 
     * out of bounds. If we step upwards, we will be on the outer arc which is out of bounds.
     */ 
    ll hstart = r;
    
    for (int i = 0; i <= r; i++) {
        ll x = i;
        ll h = hstart; // start wherever the search along the previous x coordinate started
        
        while(h > 0 && (r+1)*(r+1) <= x*x + h*h) { // move downwards until we are in bounds
            h--;
        }
        
        hstart = h; // save the height at which we are first in bounds
        
        // walk downwards until we are inside the inner arc, counting how many steps
        while(h > 0 && r*r <= x*x + h*h && x*x + h*h < (r+1)*(r+1)) {
            cnt++;
            h--;
        }
    }
    
    // we counted the number of valid points in Quadrant 1, total is all 4 quadrants
    cnt *= 4;
    
    cout << cnt << endl;
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}




