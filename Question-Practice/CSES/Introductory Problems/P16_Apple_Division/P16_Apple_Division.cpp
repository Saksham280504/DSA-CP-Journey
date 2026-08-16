#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

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
    vector<ll> arr(n);
    ll totalSum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }

    int allMask = 1<<n;
    ll minDiff = LLONG_MAX;
    for(int mask=0; mask<allMask; mask++) {
        ll subsetSum = 0;
        for(int i=0; i<n; i++) {
            if(mask&(1<<i)) {
                subsetSum += arr[i];
            }
        }
        ll other = totalSum - subsetSum;
        minDiff = min(minDiff,abs(subsetSum-other));
    }
    cout << minDiff << endl;

    return 0;
}
