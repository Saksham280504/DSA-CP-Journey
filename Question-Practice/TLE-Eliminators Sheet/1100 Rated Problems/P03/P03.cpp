#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a;
    ll b;
    for(ll i=0; i<n; i++) {
        cin >> b;
        a.push_back({b,i});
    }
    sort(a.begin(), a.end());
    vector<ll> preSum(n);
    preSum[0] = a[0].first;
    for(ll i=1; i<n; i++) {
        preSum[i] = preSum[i-1] + a[i].first;
    }
    vector<ll> ans(n);
    for(ll i=0; i<n; i++) {
        ll j = i;
        ll found = i;
        while(j<n) {
            pair<ll,ll> temp = {preSum[j]+1,INT_MIN};
            ll indx = lower_bound(a.begin(), a.end(),temp) - a.begin();
            indx--;
            if(indx==j) break;
            found += indx-j;
            j = indx;
        }
        ans[a[i].second] = found;
    }

    for(auto it: ans) cout << it << " ";
    cout << endl;
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
