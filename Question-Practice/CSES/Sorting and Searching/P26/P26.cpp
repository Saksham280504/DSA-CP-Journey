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
    vector<pair<ll,int>> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(),arr.end());

    for(int i=0; i<n-2; i++) {
        ll rem = x-arr[i].first;
        int j=i+1, k=n-1;
        while(j<k) {
            ll TwoSum = arr[j].first+arr[k].first;
            if(TwoSum<rem) j++;
            else if(TwoSum>rem) k--;
            else {
                cout << arr[i].second << " " << arr[j].second << " " << arr[k].second;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
