#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    ll n;
    cin >> n;
    vector<ll> k(n);
    for(ll i=0; i<n; i++) cin >> k[i];
    map<ll,ll> mpp;
    ll l=0, maxLen=0;
    for(ll i=0; i<n; i++) {
        if(mpp.count(k[i]) && mpp[k[i]]>=l) l = mpp[k[i]]+1;
        mpp[k[i]] = i;
        maxLen = max(maxLen,i-l+1);
    }
    cout << maxLen << endl;
    return 0;
}
