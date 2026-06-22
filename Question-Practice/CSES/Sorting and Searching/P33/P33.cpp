#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

bool check(vector<ll>& arr, ll min_max_sum, int k) {
    int cnt = 1;
    ll sum = 0;
    for(ll x: arr) {
        if(x>min_max_sum) return false;
        sum += x;
        if(sum>min_max_sum) {
            sum = x;
            cnt++;
        }
    }
    return cnt<=k;  // If for a max_subarray_sum, we can divide the array into k or lesser subarrays then return true otherwise return false
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n,k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll low = 1, high = accumulate(arr.begin(), arr.end(), 0LL); 
    // When we are dividing the array into k subarrays such that max_subarray_sum becomes minimum, then below that minimum value we can't divide the array into k subarrays, the cnt of number of subarrays for smaller max_subarray_sum will be greater than k. 
    // So we will see the following behaviour: (low=1)..... F F F F F F F T T T T T T ...... (high = ArraySum), so this behaviour shows binary search on answers intuition which builds the core ideolgy behind our approach.
    ll ans = high;
    while(low<=high) {
        ll mid = low+(high-low)/2;
        if(check(arr,mid,k)) { 
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    cout << ans << endl;

    return 0;
}
