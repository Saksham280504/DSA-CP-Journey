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
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int k;
    cin >> k;

    int lsum = 0, rsum = 0, maxSum = 0;

    for(int i=0; i<k; i++) lsum += arr[i];
    maxSum = lsum;
    int rInd = n-1;
    for(int i=k-1; i>=0; i--) {
        lsum -= arr[i];
        rsum += arr[rInd];
        rInd--;
        maxSum = max(maxSum,lsum + rsum);
    }

    cout << maxSum << endl;

    return 0;
}
