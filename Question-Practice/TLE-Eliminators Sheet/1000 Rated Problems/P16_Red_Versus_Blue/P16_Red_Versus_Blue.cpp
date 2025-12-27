#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,r,b;
    cin >> n >> r >> b;
    int RwinsInaRow = r/(b+1); // You need to distribute number of red wins equally among (b+1) segments.
    int ExtraRWins = r%(b+1); // These are extra R's that will remain after equal distribution of R wins in (b+1) segments, so you will also distribute these extra R's equally till you can.
    string s = "";
    for(int times=1; times<=b+1; times++) {
        for(int i=0;i<RwinsInaRow; i++) s += 'R';
        if(ExtraRWins>0) {
            s += 'R';
            ExtraRWins--;
        }
        if(times!=b+1) s+= 'B'; // If its the last segment, don't place a 'B' then
    }

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
