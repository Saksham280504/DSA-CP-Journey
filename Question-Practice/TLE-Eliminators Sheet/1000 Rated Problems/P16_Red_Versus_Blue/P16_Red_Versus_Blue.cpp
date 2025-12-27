#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,r,b;
    cin >> n >> r >> b;
    int RwinsInaRow = r/b;
    int RwinsInLast = r%b;
    if(RwinsInLast==0) {
        RwinsInaRow = (r-1)/2;
        RwinsInLast = r-(RwinsInaRow*b);
    }
    string s = "";
    while(b>0) {
        for(int i=0;i<RwinsInaRow; i++) s += 'R';
        s += 'B';
        b--;
    }
    for(int i=0; i<RwinsInLast; i++) s += 'R';
    cout << s << endl;
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
