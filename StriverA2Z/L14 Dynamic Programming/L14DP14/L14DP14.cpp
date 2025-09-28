#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool isSsThere(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake = isSsThere(ind-1,target,arr,dp);
    bool take = false;
    if(target>=arr[ind]) {
        take = isSsThere(ind-1,target-arr[ind],arr,dp);
    }
    dp[ind][target] = (take||notTake) ? 1:0;
    return dp[ind][target];

    // For recursion approach:
    // TC -> O(2^N) (at every index, we have two choices)
    // SC -> O(N)

    // For memoization Approach:
    // TC -> O(N*target)
    // SC -> O(N)(recursion stack-space) + O(N*target) (dp-array)
}

bool isSsTab(int n, int target,vector<int>& arr, vector<vector<bool>>& dp) {
    for(int i=0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;

    for(int ind=1; ind<n; ind++) {
        for(int k=1; k<=target; k++) {
            bool notTake = dp[ind-1][k];
            bool take = false;
            if(k>=arr[ind]) {
            take = dp[ind-1][k-arr[ind]];
            }
            dp[ind][k] = take | notTake;
        }
    }

    return dp[n-1][target];

    // TC -> O(N*target)
    // SC -> O(N*target)
}

bool isSsSO(int n, int target, vector<int>& arr) {
    vector<bool> prev(target+1,false);
    prev[0] = true;
    prev[arr[0]] = true;
    vector<bool> curr(target+1,false);
    curr[0] = true;
    for(int ind=1; ind<n; ind++) {
        for(int k=1; k<=target; k++) {
            bool notTake = prev[k];
            bool take = false;
            if(k>=arr[ind]) take = prev[k-arr[ind]];
            curr[k] = take | notTake;
        }
        prev = curr;
    }

    return prev[target];

    // TC -> O(n*target)
    // SC -> O(2*target)
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

    // Here we begin DP on Subsequences/Subsets:

    // -> Subsequence is any contiguous/non-contiguous part of the array that follow the order of the array.
    // For eg:- In [1,3,2] -> [1,2] is both subset/subsequence but [2,1] is only a subset but not subsequence.

    // To solve any problem for DP on subsequences, we follow the following thumb rule:
    // 1. Express everything in terms of (ind, target)
    // 2. Explore possibilities of that index -> Only two possibilities are there, i.e., either arr[ind] is a part of the subsequence or arr[ind] is not the part of the subsequence.
    // 3. Return what you are looking for

    // Q. We are given an array of integers and an integer value target, and we want to find if there exists a subsequence within the array such that the sum of the elements of the subsequence is equal to the given target.

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    // Recursive/Memoization Approach:
    // vector<vector<int>> dp(n,vector<int>(target+1,-1));
    // string isTrue = isSsThere(n-1,target,arr,dp) ? "true" : "false";
    // cout << isTrue << endl;

    // Tabulation Approach:
    // For tabulation approach, all we need to remember are these 2 thumb rules:
    // 1. Fulfill the base-cases
    // 2. Form the nested loop (Number of states = Number of nested loops)

    // vector<vector<bool>> dp(n,vector<bool>(target+1,false));
    // string isSs = isSsTab(n,target,arr,dp) ? "true" : "false";
    // cout << isSs << endl;

    // Space-Optimization Approach:

    string isSs = isSsSO(n,target,arr) ? "true": "false";
    cout << isSs << endl;
    return 0;
}
