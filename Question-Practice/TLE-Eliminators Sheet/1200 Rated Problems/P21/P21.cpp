#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    // a[i].a[j] = i+j (i+j maximum value can go at max upto 2*n-1, so if a[i].a[j]>=2n, then that pair will never be a pleasant pair)

    sort(a.begin(),a.end());
    ll ans = 0;
    for(ll i=0; i<n; i++) {
        for(ll j=i+1; j<n; j++) {
            if(a[i].first*a[j].first>=2*n) break;
            if(a[i].first*a[j].first==(a[i].second+a[j].second)) ans++;
        }
    }
    cout << ans << endl;

    // TC -> O(NlogN)
    // SC -> O(N)
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
