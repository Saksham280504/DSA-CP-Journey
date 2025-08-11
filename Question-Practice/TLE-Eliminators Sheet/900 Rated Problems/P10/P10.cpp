#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n,q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    ll Old_sum=0;
    for(int i=0; i<n; i++) {
        Old_sum += arr[i];
    }
    vector<ll> prefix_Sum(n+1,0);

    for(int i=1; i<=n; i++) {
        prefix_Sum[i] = prefix_Sum[i-1] + arr[i-1];
    }
    for(int i=0; i<q; i++) {
        int l,r;
        ll k;
        cin >> l >> r >> k;
        ll sum_to_be_removed = prefix_Sum[r]-prefix_Sum[l-1];
        ll sum_to_be_added = (r-l+1)*k;
        ll total_sum = Old_sum - sum_to_be_removed + sum_to_be_added;
        if(total_sum%2==1) cout << "YES" << endl;
        else cout << "NO" << endl;
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
