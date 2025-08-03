#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }
    vector<int> a;
    a.push_back(b[0]);
    for(int i=1; i<n; i++) {
        if(b[i]>=b[i-1]) a.push_back(b[i]);
        else {
            a.push_back(b[i]);
            a.push_back(b[i]);
        }
    }
    int m = a.size();
    cout << m << endl;
    for(int i=0; i<m; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
