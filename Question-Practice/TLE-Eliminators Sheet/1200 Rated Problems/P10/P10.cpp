#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int binarySearch(vector<long long>& arr, int val, int n) {
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]<=val) {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }

    return ans;
}
void solve() {
    int n,q;
    cin >> n >> q;
    vector<long long> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<long long> preSum(n,0);
    vector<long long> preMax(n,0);

    preSum[0] = arr[0];
    preMax[0] = arr[0];

    for(int i=1; i<n; i++) {
        preSum[i] = preSum[i-1] + arr[i];
        preMax[i] = max(preMax[i-1],arr[i]);
    }

    for(int i=0; i<q; i++) {
        int k;
        cin >> k;
        int ind = binarySearch(preMax,k,n);
        if(ind==-1) cout << 0 << " ";
        else cout << preSum[ind] << " ";
    }
    cout << endl;
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
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
