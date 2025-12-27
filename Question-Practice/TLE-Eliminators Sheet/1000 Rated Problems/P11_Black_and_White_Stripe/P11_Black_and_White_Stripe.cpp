#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,k;
    cin >> n >> k;
    string strip;
    cin >> strip;
    int blackCount = 0;
    int whiteCount = 0;
    int minChange = INT_MAX;
    int l = 0;
    int r = 0;
    while(r<=l+k-1) {
    if(strip[r]=='W') whiteCount++;
    else blackCount++;
    r++;
    }
    minChange = min(minChange,whiteCount);
    while(r<n) {
        minChange = min(minChange,whiteCount);
        if(strip[l]=='W') whiteCount--;
        else blackCount--;
        l++;
        r++;
        if(r<n) {
            if(strip[r]=='W') whiteCount++;
            else blackCount++;
        }
    }
    cout << minChange << endl;
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
