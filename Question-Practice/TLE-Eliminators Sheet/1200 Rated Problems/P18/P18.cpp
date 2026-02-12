#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    if(a[n-2]>a[n-1]) {
        cout << -1 << endl;
        return;
    }
    if(a[n-1]>=0) {
        cout << n-2 << endl;
        for(int i=1; i<=n-2; i++) {
            cout << i << " " << n- 1<< " " << n << endl;
        }
    }
    else {
        if(is_sorted(a.begin(),a.end())) {
            cout << 0 << endl;
        }
        else cout << -1 << endl;
    }
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
