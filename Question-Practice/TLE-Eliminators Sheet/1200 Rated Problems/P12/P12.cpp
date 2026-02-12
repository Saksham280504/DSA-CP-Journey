#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;

    // It is okay if a friend doesn't go to the restaurant at all.
    vector<long long> x(n);
    vector<long long> y(n);

    for(int i=0; i<n; i++) cin >> x[i];
    for(int i=0; i<n; i++) cin >> y[i];

    multiset<long long> ms;

    for(int i=0; i<n; i++) ms.insert(y[i]-x[i]);

    int ans = 0;
    while(ms.size()>1) {
        long long val = *ms.begin();
        ms.erase(ms.begin());
        auto it = ms.lower_bound(-val);
        if(it==ms.end()) continue;
        ans++;
        ms.erase(it);
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
