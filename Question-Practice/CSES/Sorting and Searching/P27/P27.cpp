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
    set<tuple<ll,int,int>> pairs;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            pairs.insert({arr[i]+arr[j],i,j});
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            pairs.erase({arr[i]+arr[j],i,j});
        }
        for(int j=0; j<i; j++) {
            ll diff = x-(arr[i]+arr[j]);
            auto it = pairs.lower_bound({diff,-1,-1}); // will give you the iterator it pointing to smallest sum(arr[k]+arr[l])>=diff
            if(it==pairs.end()) continue; // All pair sums are smaller than diff
            auto [sum,k,l] = *it;
            if(sum!=diff) continue;
            cout << i+1 << " " << j+1 << " " << k+1 << " " << l+1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
