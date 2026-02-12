#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    map<int,int> Presum;
    Presum[0] = -1;
    int len = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += a[i];
        if(Presum.count(sum-s)) {
            len = max(len,i-Presum[sum-s]);
        }
        if(!Presum.count(sum)) {
            Presum[sum] = i;
        }
    }

    if(len==INT_MIN) {
        cout << -1 << endl;
    }
    else cout << n-len << endl;
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
