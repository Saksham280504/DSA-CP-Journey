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
    ll n,x;
    cin >> n >> x;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = (i+1);
    }
    sort(arr.begin(),arr.end());

    ll l=0, r=n-1;
    while(l<r) {
        ll sum = arr[l].first + arr[r].first;
        if(sum==x) {
            cout << arr[l].second << " " << arr[r].second << endl;
            return 0;
        }
        else if(sum<x) {
            l++;
        }
        else r--;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
