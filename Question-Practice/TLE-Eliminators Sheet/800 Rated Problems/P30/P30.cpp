#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    int m = n;
    int numOfDigits = 0;
    while(m>0) {
        m = m/10;
        numOfDigits++;
    }

    int cnt = 9*(numOfDigits-1);
    
    for(int i=0; i<numOfDigits-1; i++) {
        n = n/10;
    }

    cnt += n;

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
