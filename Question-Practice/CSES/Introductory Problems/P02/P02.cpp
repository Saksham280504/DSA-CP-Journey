#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n;
    cin >> n;
    int TotalXor = 0;
    for(int i=1; i<=n; i++) TotalXor = TotalXor^i;
    int NetXor = 0;
    for(int i=1; i<n; i++) {
        int x; 
        cin >> x;
        NetXor = NetXor^x;
    }
    cout << (TotalXor^NetXor) << endl;

    return 0;
}
