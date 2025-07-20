#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int nosa(vector<int>& arr, int n, int maxArraySum) {
    int subArray = 1;
    int subArraySum = 0;
    for(int i=0; i<n; i++) {
        if(subArraySum + arr[i] <=maxArraySum) {
            subArraySum += arr[i];
        }
        else {
            subArray++;
            subArraySum = arr[i];
        }
    }
    return subArray;
}

int MinOfMax(vector<int>& arr, int n, int k, int max, int sum) {
    if(k>n) return -1;
    for(int i=max; i<=sum; i++) {
        if(nosa(arr,n,i)==k) return i;
    }
    return -1;
}

int MinOfMaxBS(vector<int>& arr, int n, int k, int max, int sum) {
    int low = max;
    int high = sum;
    while(low<=high) {
        int mid =(low+high)/2;
        if(nosa(arr,n,mid)>k) low = mid+1;
        else high = mid-1;
    }
    return low;
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

    int k;
    cin >> k;

    // Split array - Largest Subarray -> We are given an array and we have to split that array in k subarrays such that none of the subarrays is empty and we have to split them in such a way that the maximum Subarray Sum of that Split is minimum among all the other splits.

    int max = *max_element(arr.begin(),arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    

    int minMaxSum = MinOfMax(arr,n,k,max,sum);
    // TC -> O(N*(sum-max+1))
    int minMaxSum = MinOfMaxBS(arr,n,k,max,sum);
    // TC -> O(N*log2(sum-max+1))
    
    if(minMaxSum==-1) cout << "SubArrays not possible" << endl;
    else cout << minMaxSum << endl;

    return 0;
}
