#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int high = n-2;
    while(high>=1) {
        for(int i=1; i<=high; i++) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
        }
        if(arr[high+1]<arr[high]) {
            cout << "NO" << endl;
            return;
        }
        else high--;
    }
    if(arr[high+1]<arr[high]) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
