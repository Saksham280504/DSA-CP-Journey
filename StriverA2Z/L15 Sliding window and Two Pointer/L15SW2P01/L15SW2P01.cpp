#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int maxSubArraySum1(int n, int k, vector<int>& arr){
    int maxLen = 0;

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            if(sum<=k) maxLen = max(maxLen,j-i+1);
            else break;
        }
    }

    return maxLen;
    // TC -> O(N*N)
}

int maxSubArraySum2(int n, int k, vector<int>& arr) {
    int maxLen=0, l=0, r=0, sum=0;

    while(r<n) {
        sum += arr[r];
        while(sum>k) {
            sum -= arr[l];
            l++;
        }
        if(sum<=k) maxLen = max(maxLen,r-l+1);
        r++;
    }

    return maxLen;
    // TC -> O(2*N)
}

int maxSubArraySum3(int n, int k, vector<int>& arr) {
    int maxLen=0, l=0, r=0, sum=0;

    while(r<n) {
        sum += arr[r];
        if(sum>k) {
            sum -= arr[l];
            l++;
            // Here, we made sure that the subarray's size atleast stays equal to maxLen. 
        }
        if(sum>=k) maxLen = max(maxLen,r-l+1);
        r++;
    }

    return maxLen;
    // TC -> O(N)
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

    // Not a typical algorithm, but a constructive algorithm.

    // Types of problems:-

    // 1. Constant Window
    // 2. Longest subarray/ substring where <condition>

    // 2A. Longest subarray with sum<=k

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int k;
    cin >> k;

    int maxSum1 = maxSubArraySum1(n,k,arr); // Brute-force Approach
    cout << maxSum1 << endl;
    int maxSum2 = maxSubArraySum2(n,k,arr);
    cout << maxSum2 << endl; // Better Approach
    // The Optimal approach is only used when we need to print the size of the longest subarray, and not the actual subArray
    int maxSum3 = maxSubArraySum3(n,k,arr); // Optimal Approach
    cout << maxSum3 << endl;

    // 3. Number of SubArrays where <condition>
    // 4. Shortest/Minimum Window <condition>

    return 0;
}
