#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,k;
    cin >> n >> k;
    k--; // This will now give me that how many normal jumps did B took.
    if(n%2==0) cout << (k%n)+1 << endl;
    else {
        int val = n/2;
        cout << (k + (k/val))%n+1 << endl; 
    }
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
