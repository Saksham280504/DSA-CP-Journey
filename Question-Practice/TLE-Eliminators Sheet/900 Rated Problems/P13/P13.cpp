#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    bool isStarted = false;
    for(int i=0; i<n; i++) {
        if(arr[i]!=0 && isStarted==false) {
            isStarted = true;
            cnt++;
        }
        else if(arr[i]==0 && isStarted==true) {
            isStarted = false;
        }
    }
    if(cnt < 2) cout << cnt << endl;
    else cout << 2 << endl;
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