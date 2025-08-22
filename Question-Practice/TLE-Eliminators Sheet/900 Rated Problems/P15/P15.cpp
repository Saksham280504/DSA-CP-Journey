#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    long long cnt = 0;
    for(int i=n-2; i>=0 ; i--) {
        while(arr[i]>=arr[i+1]) {
            cnt++;
            arr[i] = arr[i]/2;
            if(arr[i]==0) break;
        }
        if(arr[i]==0 && arr[i+1]==0) {
            cnt = -1;
            break;
        }
    }

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