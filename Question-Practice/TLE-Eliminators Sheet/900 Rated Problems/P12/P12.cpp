#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int diff = INT_MIN;

    for(int i=0; i<n; i++) {
        diff = max(arr[n-1]-arr[i],diff);
    }

    for(int i=0; i<n; i++) {
        diff = max(arr[i]-arr[0],diff);
    }

    for(int i=0; i<n-1; i++) {
        diff = max(arr[i]-arr[i+1],diff);
    }

    cout << diff << endl;
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