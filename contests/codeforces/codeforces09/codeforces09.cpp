#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> s(n);
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    vector<ll> t(n);
    for(int i=0; i<n; i++) {
        cin >> t[i];
    }
    vector<int> check(n,0);

    for(int i=0; i<n; i++) {
        int flag = 0;
        for(int j=0; j<n; j++) {
            if(check[j]==1) continue;
            else if(abs(t[j]-s[i])%k==0) {
                check[j] = 1;
                flag = 1;
                break;
            }
            else if(abs(t[j]-abs(s[i]-k))%k==0) {
                check[j] = 1;
                flag = 1;
                break;
            }
        }
        if(flag==0) {
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
