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
    int n, k, pb, ps; cin >> n >> k >> pb >> ps;

    vector<int> p (n+1);
    vector<int> a (n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> b (n);
    vector<int> s (n);

    b[0] = a[pb];
    s[0] = a[ps];

    for (int i = 1; i < n; i++)
    {
        pb = p[pb];
        ps = p[ps];
        b[i] = a[pb];
        s[i] = a[ps];
    }

    vector<ll> bpref (n);
    vector<ll> spref (n);

    bpref[0] = b[0];
    spref[0] = s[0];

    for (int i = 1; i < n; i++)
    {
        bpref[i] = bpref[i-1] + b[i];
        spref[i] = spref[i-1] + s[i];
    }

    ll maxbscore = 0;
    ll maxsscore = 0;

    for (int i = 0; i < min(n, k); i++)
    {
        maxbscore = max(bpref[i]+1LL*(k-i-1)*b[i], maxbscore);
        maxsscore = max(spref[i]+1LL*(k-i-1)*s[i], maxsscore);
    }

    if (maxbscore > maxsscore)
    {
        printf("Bodya\n");
    }
    else if (maxbscore == maxsscore)
    {
        printf("Draw\n");
    }
    else 
    {
        printf("Sasha\n");
    }
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}



