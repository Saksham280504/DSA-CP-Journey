#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    int maxi = -1;
    int sum = 0;
    int ans = 0;

    for(int i=0; i<min(n,k); i++) {
        sum += a[i];
        maxi = max(maxi, b[i]);
        ans = max(ans,sum+(maxi*(k-(i+1))));
    }

    cout << ans << endl;
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
