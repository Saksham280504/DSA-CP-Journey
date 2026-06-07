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
    vector<long long> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    long long minOp = 0;
    for(int i=1; i<n; i++) {
        if(arr[i]<arr[i-1]) {
            minOp += (arr[i-1]-arr[i]);
            arr[i] = arr[i-1];
        }
    }

    cout << minOp << endl;
    return 0;
}
