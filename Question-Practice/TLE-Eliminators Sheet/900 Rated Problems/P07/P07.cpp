#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
using ll = long long;
void solve() {
    ll n,k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    ll maxLength = 0;
    ll cnt = 1;
    for(ll i=1; i<n; i++) {
        if(arr[i]-arr[i-1]<=k) cnt++;
        else {
            maxLength = max(cnt,maxLength);
            cnt = 1;
        }
    }
    maxLength = max(cnt,maxLength);

    cout << n-maxLength << endl;
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
    while(t--) {
        solve();
    }

    return 0;
}
