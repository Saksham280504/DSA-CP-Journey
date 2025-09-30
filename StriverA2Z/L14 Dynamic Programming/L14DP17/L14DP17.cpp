#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numOfSubsets(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
    // Recurance rule:

    // 1. Express everything in terms of index (ind,target).
    // 2. Explore all the possibilities
    // 3. Sum up all of the possibilities.

    if(target==0) return 1;
    if(ind==0) return (arr[ind]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notPick = numOfSubsets(ind-1,target,arr,dp);
    int pick = 0;
    if(arr[ind]<=target) pick = numOfSubsets(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target] = pick + notPick;
}

int numOfSubsetsTab(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
    for(int i=0; i<n; i++) dp[i][0] = 1;
    if(arr[0]<=target) dp[0][arr[0]] = 1;
    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
            int notPick = dp[i-1][k];
            int pick = 0;
            if(arr[i]<=k) pick = dp[i-1][k-arr[i]];
            dp[i][k] = pick + notPick;
        }
    }
    return dp[n-1][target];
}

int numOfSubsetsSO(int n, int target, vector<int>& arr) {
    vector<int> prev(target+1,0);
    vector<int> curr(target+1,0);
    prev[0] = 1;
    curr[0] = 1;
    if(arr[0]<=target) prev[arr[0]] = 1;

    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
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

    // You are given an array of positive integers and a positive integer target. Your task is to find the number of unique subsequences that you can form such that the sum of all the elements of the subsequence is equal to target.

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    int num = numOfSubsets(n-1,target,arr,dp);
    cout << num << endl;

    vector<vector<int>> dp1(n,vector<int>(target+1,0));
    int num2 = numOfSubsetsTab(n,target,arr,dp1);
    cout << num2 << endl;

    int num3 = numOfSubsetsSO(n,target,arr);
    cout << num3 << endl;

    return 0;
}
