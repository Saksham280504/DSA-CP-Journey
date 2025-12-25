#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int ans = 1e9;
    int evenCount = 0;
    for(int i=0; i<n; i++) { // This function gives me the minOperations needed to make a certain arr[i] a multiple of k
        if(arr[i]%2==0) evenCount++;
        if(arr[i]%k==0) ans = 0;
        else ans = min(ans, k-arr[i]%k);
    }

    if(k==4) { // Edge case for k=4 as 4 can be formed using 2 as well
        if(evenCount>=2) ans = 0;
        else if(evenCount==1) ans = min(ans,1);
        else ans = min(ans,2);
    }

    cout << ans << endl;

    // TC -> O(N)
    // SC -> O(1)
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
