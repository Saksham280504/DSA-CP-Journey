#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int maxiSum(int ind, vector<int>& arr,vector<int>& dp) {
    if(ind==0) return arr[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick = arr[ind] + maxiSum(ind-2,arr,dp);
    int notpick = 0 + maxiSum(ind-1,arr,dp);
    return dp[ind] = max(pick, notpick);

    // TC ->O(N)
    // SC -> O(N) + O(N)
}

int maxiSumTab(int n,vector<int>& arr) {
    // vector<int>dp(n,-1);
    // dp[0] = arr[0];
    // for(int i=1; i<n-1; i++) {
    //     int pick = arr[i];
    //     if(i>1) pick += dp[i-2];
    //     int notpick = 0 + dp[i-1];
    //     dp[i] = max(pick,notpick);
    // }
    // return dp[n-2];
    // TC -> O(N)
    // SC ->O(N)

    int prev = arr[0];
    int prev2 = 0;
    for(int i=1; i<n-1; i++) {
        int pick = arr[i];
        if(i>1) pick += prev2;
        int notpick = 0 + prev;
        int curi = max(pick, notpick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
    // TC -> O(N)
    // SC -> O(1)
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

    // This problem is same as the largest sum of non-adjacent elements of an array. The only difference is that here the last and first element are adjacent.

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> temp1, temp2;
    for(int i=0; i<n; i++) {
        if(i!=0) temp1.push_back(arr[i]);
        if(i!=n-1) temp2.push_back(arr[i]);
    }

    // Recursive/Memoization Approach:

    // vector<int> dp1(n,-1);
    // vector<int> dp2(n,-1);
    // int sum1 = maxiSum(n-2,temp1,dp1);
    // int sum2 = maxiSum(n-2,temp2,dp2);
    // cout << max(sum1,sum2) << endl;

    // Tabulation-Approach:

    int sum1 = maxiSumTab(n,temp1);
    int sum2 = maxiSumTab(n,temp2);
    cout << max(sum1,sum2) << endl;

    return 0;
}
