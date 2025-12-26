#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

void solve() {
    ll n,x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];

    ll min_v = -x + arr[0];
    ll max_v = x + arr[0];
    int cnt = 0;
    for(ll i=1; i<n; i++) {
        min_v = max(min_v,-x+arr[i]);  // For overlapping intervals, we always try to take the maximum of minimum of both the intervals.
        max_v = min(max_v,x+arr[i]);   // For overlapping intervals, we always try to take the minimum of maximum of both the intervals.
        if(min_v>max_v) { // If overlapping would have occured, then min_v<=max_v otherwise no overlapping
            cnt++;
            min_v = -x+arr[i];
            max_v = x+arr[i];
        }
    }
    // TC -> O(2N)
    // SC -> O(1) (excludi gthe input array)

    cout << cnt << endl;
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
    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}
