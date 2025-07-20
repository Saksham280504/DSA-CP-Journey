#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool isSmallerThanTh(vector<int>& arr, int n, int th, int num) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += ceil((double)arr[i]/(double)num);
    }
    if(sum<=th) return true;
    return false;
}
int minDivisor(vector<int>& arr, int n, int th, int maxi) {
    if(th < n) return -1;
    for(int i=1; i<=maxi; i++) {
        if(isSmallerThanTh(arr,n,th,i)) return i;
    }
    return -1;
}

int minDivisorBS(vector<int>& arr, int n, int th, int maxi) {
    if(th < n) return -1;
    int low = 1;
    int high = maxi;
    int ans = high;
    while(low<=high) {
        int mid=(low+high)/2;
        if(isSmallerThanTh(arr,n,th,mid)) {
            ans = mid;
            high = mid -1;
        }
        else low = mid+1;
    }
    return ans;
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

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int th;
    cin >> th;

    // To find Minimum Divisor

    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        maxi = max(maxi, arr[i]);
    }

    // Here we don't need mini because minimum divisor can be smaller than the mini, as divisor depends upon the threshold value.

    // int miniDivisor = minDivisor(arr,n,th,maxi);
    // TC -> O((maxi-mini+1)*N) This can be further optimised using Binary Search

    int miniDivisor = minDivisorBS(arr,n,th,maxi);
    // TC -> O(log2(maxi-mini+1)*N)

    if(miniDivisor==-1) cout << "No Divisor Found" << endl;
    cout << miniDivisor << endl;

    return 0;
}
