#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    ll t;
    cin >> t;
    for(ll i=0; i<t; i++) {
        ll n;
        cin >> n;
        vector<ll> arr;
        for(ll i=0; i<n; i++) {
            ll nums;
            cin >> nums;
            arr.push_back(nums);
        }
        vector<char> str;
        ll maxi = LONG_MIN;
        ll mini = LONG_MAX;
        for(ll i=0; i<n; i++) {
            if(arr[i] > maxi) maxi = arr[i];
            if(arr[i] < mini) mini = arr[i];
        }

        for(ll i=0; i<n; i++) {
            if(i==0 || i==n-1) str.push_back('1');
            else if( arr[i] == maxi || arr[i]== mini) str.push_back('1');
            else str.push_back('0');
        }
        for(ll i=0; i<n; i++) {
            cout << str[i];
        }
        cout << endl;
     }
    return 0;
}
