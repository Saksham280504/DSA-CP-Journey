#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define endl '\n'

void solve() {
    ll n,k,x;
    cin >> n >> k >> x;
    ll small = 0;
    ll large = 0;

    for(ll i=1; i<=k; i++) {
        small += i;
    }

    for(ll i=n; i>n-k; i--) {
        large += i;
    }

    if(x < small || x > large) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}
int32_t main() {
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