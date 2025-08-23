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

    map<ll,int> mpp;
    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }

    int maxi = INT_MIN;
    for(auto it: mpp) {
        maxi = max(maxi, it.second);
    }

    int num = n-maxi;
    int cnt = 0;
    while(maxi<n) {
        cnt++;
        maxi = maxi*2;
    }

    cnt += num;

    cout << cnt << endl;
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