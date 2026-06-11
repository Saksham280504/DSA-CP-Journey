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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    ll val1 = arr[n/2];
    ll min_cost_1 = 0;
    ll val2 = arr[n/2-1];
    ll min_cost_2 = 0;
    for(ll i=0; i<n; i++) {
        min_cost_1 += abs(val1-arr[i]);
        min_cost_2 += abs(val2-arr[i]);
    }
    if(n&1) {
        cout << min_cost_1 << endl;
        return 0;
    }
    cout << min(min_cost_1, min_cost_2) << endl;
    return 0;
}
