#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

void solve() {
    ll n,k,b,s;
    cin >> n >> k >> b >> s;
    ll minimum = k*b;
    ll maximum = k*b + (k-1)*n;
    if(s<minimum || s>maximum) { // If (minimum<=s<=maximum), then answer will always exist
        cout << -1 << endl;
        return;
    }
    vector<ll> ans(n,0);
    ans[0] += minimum;
    s -= minimum;
    for(ll i= 0; i<n; i++) {
        ans[i] += min(k-1,s);
        s -= min(k-1,s);
    }
    for(auto x: ans) cout << x << " ";
    cout << endl;

    // TC -> O(N)
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
	cin >> t; // Read the number of test cases
	while (t--) solve();
    return 0;
}
