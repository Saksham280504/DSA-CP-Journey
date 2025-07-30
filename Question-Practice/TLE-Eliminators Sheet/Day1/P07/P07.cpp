#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    set<char> st;
    for(int i=0; i<n; i++) {
        if(st.find(s[i])==st.end()) st.insert(s[i]);
        cnt += st.size();
    }

    cout << cnt << endl;
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
