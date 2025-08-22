#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define endl '\n'

void solve() {
    ll n;
    cin >> n;
    if(n%2!=0 || n<4) {
        cout << -1 << endl;
        return;
    }
    if(n%6==0) {
        cout << n/6 << " " << n/4 << endl;
        return;
    }
    cout << n/6 + 1 << " " << n/4 << endl;
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