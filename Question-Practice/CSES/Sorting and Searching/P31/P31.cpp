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
    for(int i=0; i<n; i++) cin >> arr[i];
    map<ll,ll> mpp;
    mpp[0] = 1;
    ll curr_sum=0, total=0;
    
    for(int i=0; i<n; i++) {
        curr_sum += arr[i];
        ll mod = (curr_sum%n+n)%n;
        total += mpp[mod];
        mpp[mod]++;
    }

    cout << total << endl;

    return 0;
}
