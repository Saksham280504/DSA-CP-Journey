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
    ll maxi = *max_element(arr.begin(),arr.end());
    ll max_sum = INT_MIN, sum = 0;

    for(ll i=0; i<n; i++) {
        sum += arr[i];
        if(sum<0) sum = 0;
        max_sum = max(max_sum,sum);
    }
    if(max_sum==0) max_sum = maxi;
    cout << max_sum << endl;

    return 0;
}
