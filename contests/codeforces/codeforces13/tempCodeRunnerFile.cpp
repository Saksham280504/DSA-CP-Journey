#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 3;
    string t = "";
    for(int k=0; k<r; k++) t += s[k];
    bool is2025 = false;
    bool is2026 = false;
    while(r<n) {
        t += s[r];
        if(t=="2025") {
            is2025 = true;
        }
        if(t=="2026") {
            is2026 = true;
            break;
        }
        t.erase(t.begin());
        r++;
    }
    if(is2026) {
        cout << 0 << endl;
        return;
    }
    if(is2025) {
        cout << 1 << endl;
        return;
    }
    cout << 0 << endl;
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
