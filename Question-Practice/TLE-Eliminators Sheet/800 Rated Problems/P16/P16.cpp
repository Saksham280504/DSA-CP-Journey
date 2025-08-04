#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int flag = 0;
    ll mini = __LONG_LONG_MAX__;
    for(int i=1; i<n; i++) {
        if(arr[i]>=arr[i-1]) {
            mini = min(mini,arr[i]-arr[i-1]);
        }
        else {
            flag = 1;
            break;
        }
    }

    if(flag) {
        cout << 0 << endl;
        return;
    }
    cout << ((mini/2) + 1) << endl;
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
