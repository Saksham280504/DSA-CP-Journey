#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    map<ll,ll> mpp;
    for(ll i=0; i<n; i++) {
        ll nums;
        cin >> nums;
        mpp[nums-i]++;
    }
    ll ans = 0;
    for(auto it: mpp) {
        if(it.second>1) ans += (it.second)*(it.second-1)/2;
    }
 
    cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    // your code here
    int t;
    cin >> t;
    while(t--) solve();
 
    return 0;
}