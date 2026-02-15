#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<ll> maxBit(31,0);

    for(int i=0; i<n; i++) {
        for(int j=30; j>=0; j--) {
            if(a[i]&(1<<j)) {
                maxBit[j]++;
                break;
            }
        }
    }

    ll cnt = 0;
    for(int i=0; i<=30; i++) {
        cnt += (maxBit[i]*(maxBit[i]-1))/2;
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
    while(t--) solve();

    return 0;
}
