#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;

    bool check = true;
    for(int i=0; i<n; i++) {
        if(s[i]!=c) {
            check = false;
            break;
        }
    }
    if(check) {
        cout << 0 << endl;
        return;
    }

    for(int i=2; i<=n; i++) {
        bool isPossible = true;
        for(int j=i; j<=n; j+=i) {
            if(s[j-1]!=c) {
                isPossible = false;
                break;
            }
        }
        if(isPossible) {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }

    cout << 2 << endl;
    cout << n-1 << " " << n << endl;
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
