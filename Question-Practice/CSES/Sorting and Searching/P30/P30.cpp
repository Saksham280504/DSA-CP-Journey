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
    ll x;
    cin >> x;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<ll,ll> mpp;
    mpp[0] = 1; // Not taking any element also produces sum=0;

    // Ideology is simple => (______sum-x_______)(____X_____) for a subarray ending at index i to have a sum = x, it is important for us to have a subarray from 0 to j (j<i) such that subarray_sum[0...j] = (sum-x)

    ll curr_sum = 0, total=0;
    for(int i=0; i<n; i++) {
        curr_sum += arr[i];
        total += mpp[curr_sum-x];
        mpp[curr_sum]++;
    }
    cout << total << endl;

    return 0;
}
