#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    ll a,b,c;
    cin >> a >> b >> c;
    if(c%2==0) {
        a += c/2;
        b += c/2;
    }
    else {
        a += c/2+1;
        b += c/2;
    }

    if(a>b) {
        cout << "First" << endl;
        return;
    }
    else {
        cout << "Second" << endl;
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
