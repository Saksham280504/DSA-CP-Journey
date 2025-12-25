#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    vector<long long> second_smallest;
    long long smallest_min = LLONG_MAX;
    for(int i=0; i<n; i++) {
        int m;
        cin >> m;
        vector<long long> arr(m);
        for(int j=0; j<m; j++) cin >> arr[j];
        sort(arr.begin(), arr.end());
        second_smallest.push_back(arr[1]);
        smallest_min = min(smallest_min,arr[0]);
    }

    sort(second_smallest.begin(), second_smallest.end());
    long long secondMinSum = 0;
    long long secondSmallestMinimum = second_smallest[0];
    for(int i=0; i<n; i++) secondMinSum += second_smallest[i];

    long long ans = secondMinSum + smallest_min - secondSmallestMinimum;
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

    long long t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
