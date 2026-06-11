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
    map<ll,ll> mpp;
    ll numOfSubarrays = 0, l=0;
    for(ll i=0; i<n; i++) {
        if(mpp.count(arr[i]) && mpp[arr[i]]>=l) l=mpp[arr[i]]+1;
        mpp[arr[i]] = i;
        numOfSubarrays += (i-l+1);
    }
    cout << numOfSubarrays << endl;
    return 0;
}
