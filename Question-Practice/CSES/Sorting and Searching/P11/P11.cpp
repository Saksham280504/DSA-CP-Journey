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
    vector<pair<ll,ll>> arr(n);
    for(ll i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    ll rounds = 1;
    for(ll i=1; i<n; i++) {
        if(arr[i].second<(arr[i-1].second)) rounds++;
    }

    cout << rounds << endl;

    return 0;
}
