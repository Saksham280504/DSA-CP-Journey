#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    long a,b,c;
    cin >> a >> b >> c;

    // Case-1
    if((2*b-c)/a>0 && (2*b-c)%a==0) {
        cout << "YES" << endl;
    }
    // Case-2
    else if((c-a)%2==0 && ((c+a)/(2*b))>0 && ((c+a)%(2*b)==0)) {
        cout << "YES" << endl;
    }
    // Case-3
    else if((2*b-a)/c>0 && (2*b-a)%c==0) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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
