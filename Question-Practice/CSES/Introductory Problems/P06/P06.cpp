#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    long long y,x;
    cin >> y >> x;
    if(y==1LL && x==1LL) {
        cout << 1 << endl;
        return;
    }
    if(y>x) {
        if(y&1LL) {
            long long num = (y-1)*(y-1) + 1;
            x -= 1;
            num += x;
            cout << num << endl;
        }
        else {
            long long num = y*y;
            x -= 1;
            num -= x;
            cout << num << endl;
        }
    }
    else {
        if(x&1LL) {
            long long num = x*x;
            y -= 1;
            num -= y;
            cout << num << endl;
        }
        else {
            long long num = (x-1)*(x-1) + 1;
            y -= 1;
            num += y;
            cout << num << endl;
        }
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
    while(t--) solve();
    return 0;
}
