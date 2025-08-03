#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int num1 = a[0];
    int num2 = a[1];

    for(int i=0; i<n; i++) {
        if(i%2==0 && a[i]!=num1) {
            cout << "NO" << endl;
            return;
        }
        else if(i%2==1 && a[i]!=num2) {
            cout << "NO" << endl;
            return;
        }
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
