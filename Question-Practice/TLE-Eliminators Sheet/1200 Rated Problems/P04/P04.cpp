#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    int m = (n*(n-1))/2;
    vector<int> arr(m);
    for(int i=0; i<m; i++) cin >> arr[i];
    sort(arr.begin(),arr.end()); // O(MlogM)
    int i=0;
    int x = n-1;
    vector<int> ans;
    while(x>0) {
        ans.push_back(arr[i]);
        i += x;
        x--;
    }
    ans.push_back(1000000000);
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << endl;
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
