#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n,m;
    cin >> n >> m;
    string x,s;
    cin >> x >> s; 
    int flag = 0;
    int cnt = 0;
    while(flag==0) {
        x += x;
        n = x.size();
        cnt++;
        if(n <= m) {
            x += x;
            n = x.size();
            cnt++;
            if(n<m) continue;
        }
        for(int i=0; i<n; i++) {
            if(x[i]!=s[0] || n-i < m) continue;
            flag = 1;
            for(int j=1; j<m; j++) {
                if(x[i+j] != s[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                cout << cnt << endl;
                return;
            }
        }
        if(n > m && flag==0) {
            cout << -1 << endl;
            return;
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
    while(t--) {
        solve();
    }

    return 0;
}
