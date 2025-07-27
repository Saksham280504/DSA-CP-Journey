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

    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        int maxDiff = 0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            if(i==0) {
                maxDiff = max(maxDiff,arr[0]-0);
            }
            if(i>0) {
                int diff = arr[i]-arr[i-1];
                maxDiff = max(maxDiff, diff);
            }
        }

        maxDiff = max(maxDiff, 2*(x-arr[n-1]));

        cout << maxDiff << endl;
    }

    return 0;
}
