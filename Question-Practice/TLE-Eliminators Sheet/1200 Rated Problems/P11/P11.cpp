#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> isRemoved(n+1,false);
    long long ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            if(s[j-1]=='1') break;
            if(isRemoved[j]) continue;
            else {
                isRemoved[j] = true;
                ans += (long long)i;
            }
        }
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
    while(t--) solve();

    return 0;
}
