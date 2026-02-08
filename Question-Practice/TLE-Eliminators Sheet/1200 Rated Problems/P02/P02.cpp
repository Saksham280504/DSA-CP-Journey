#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    
    for(int i=1; i<=60; i++) {
        long long k = 1LL<<i;
        set<long long> st;
        for(int i=0; i<n; i++) st.insert(arr[i]%k);
        if(st.size()==2) {
            cout << k << endl;
            break;
        }
    }

    // TC -> O(T*60*N)
    // SC -> O(N)
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
