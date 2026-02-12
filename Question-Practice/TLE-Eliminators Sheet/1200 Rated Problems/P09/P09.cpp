#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    map<int, int> mpp;
    for(int i=0; i<n; i++) mpp[a[i]]++;

    int ans = 0;
    int prevFreq = 0;
    int prevEle = -1e9;
    for (auto &p : mpp) {
        int ele = p.first;
        int freq = p.second;
        if(ele==prevEle+1) ans += max(0,freq-prevFreq);
        else ans += freq;
        prevEle = ele;
        prevFreq = freq;
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
    while(t--) {
        solve();
    }

    return 0;
}
