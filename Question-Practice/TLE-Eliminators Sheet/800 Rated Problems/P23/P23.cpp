#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    long a, b, c, d;
    cin >> a >> b >> c >> d;
    if(d<b || (c>(a+d-b))) {
        cout << -1 << endl;
        return;
    }
    int num = (d-b) + (a+d-b-c);

    cout << num << endl;
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
