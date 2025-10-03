#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'


int numOfPartitionsRecursion(int ind, int s2, vector<int>& arr, vector<vector<int>>& dp) {
    if(ind==0) {
        if(s2==0 && arr[ind]==0) return 2;
        if(s2==0 || s2==arr[ind]) return 1;
        else return 0;
    }
    if(dp[ind][s2]!=-1) return dp[ind][s2];
    int notPick = numOfPartitionsRecursion(ind-1,s2,arr,dp);
    int pick = 0;
    if(arr[ind]<=s2) pick = numOfPartitionsRecursion(ind-1,s2-arr[ind], arr, dp);
    return dp[ind][s2] = pick + notPick;
}

int numOfPartitionsTabulation(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(arr[0]==0) dp[0][0] = 2; // two ways: take or not take
    else {
        dp[0][0] = 1; // One way: not take
        if(arr[0]<=target) dp[0][arr[0]] = 1;
    }
    for(int ind=1; ind<n; ind++) {
        for(int k=0; k<=target; k++) { // We have not handled the case when target = 0 here in the base case, that is why the loop starts from k = 0 here.
            int notPick = dp[ind-1][k];
            int pick = 0;
            if(arr[ind]<=k) pick = dp[ind-1][k-arr[ind]];
            dp[ind][k] = pick + notPick;
        }
    }

    return dp[n-1][target];
}

int numOfPartitionsSO(int n, int target, vector<int>& arr) {
    vector<int> prev(target+1,0);
    vector<int> curr(target+1,0);
    if(arr[0]==0) prev[0] = 2;
    else {
        prev[0] = 1;
        if(arr[0]<=target) prev[arr[0]] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int k=0; k<=target; k++) {
            int notPick = prev[k];
            int pick = 0;
            if(arr[i]<=k) pick = prev[k-arr[i]];
            curr[k] = pick + notPick;
        }
        prev = curr;
    }

    return prev[target];
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

    // We are given an array and we have to create two partitions such that:

    // 1. Their union create the original array
    // 2. The partitions have sum S1 and S2, such that S1 >= S2 and S1-S2 = 
    // Finally we have to count that how many subsets can we create this way

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int d;
    cin >> d;

    int target = 0;
    for(int i=0; i<n; i++) {
        target += arr[i];
    }

    // We apply the DP17 lecture here, by using the following analogy:
    // S1 >= S2
    // S1-S2 = D
    // S1+S2 = TotalSum
    // S2 = (TotalSum-D)/2

    // Now, we just need to find the number of subsets with sum S2 such that:
    // TotalSum-D>=0
    // (TotalSum-D)%2==0

    if(target-d<0 || (target-d)%2!=0) {
        cout << 0 << endl;
        return 0;
    }
    int s2 = (target-d)/2;
    vector<vector<int>> dp1(n,vector<int>(s2+1,-1));
    int cnt1 = numOfPartitionsRecursion(n-1,s2,arr,dp1);
    cout << cnt1 << endl;

    vector<vector<int>> dp2(n,vector<int>(s2+1,0));
    int cnt2 = numOfPartitionsTabulation(n,s2,arr,dp2);
    cout << cnt2 << endl;

    int cnt3  = numOfPartitionsSO(n,s2, arr);
    cout << cnt3 << endl;
    return 0;
}
