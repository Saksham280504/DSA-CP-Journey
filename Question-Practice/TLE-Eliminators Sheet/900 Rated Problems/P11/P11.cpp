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

    for(int i=0; i<n-1; i++) {
        if(arr[i]==1){
            arr[i]++;
            if(i>0 && arr[i]%arr[i-1]==0) arr[i]++;
        }
        if(arr[i+1]%arr[i]==0)arr[i+1]++;
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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