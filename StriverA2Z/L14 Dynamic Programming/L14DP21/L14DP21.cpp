#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numOfWays(int ind, int S2, vector<int>& arr, vector<vector<int>> &dp) {
    if(ind==0) {
        if(S2==0 && arr[ind]==0) return 2;
        if(S2==0 || S2==arr[ind]) return 1; 
        else return 0;
    }
    if(dp[ind][S2]!=-1) return dp[ind][S2];
    int notPick = numOfWays(ind-1,S2,arr,dp);
    int pick = 0;
    if(arr[ind]<=S2) pick = numOfWays(ind-1,S2-arr[ind],arr,dp);
    return dp[ind][S2] = pick + notPick;
}

int numOfWaysTab(int n, int S2, vector<int>& arr, vector<vector<int>>& dp) {
    if(arr[0]==0) dp[0][0] = 2;
    else {
        dp[0][0] = 1;
        if(arr[0]<=S2) dp[0][arr[0]] = 1;
    }
    for(int i=1; i<n; i++) {
        for(int k=0; k<=S2; k++) {
            int notPick = dp[i-1][k];
            int pick = 0;
            if(arr[i]<=k) pick = dp[i-1][k-arr[i]];
            dp[i][k] = pick + notPick;
        }
    }

    return dp[n-1][S2];
}

int numOfWaysSO(int n, int S2, vector<int>& arr) {
    vector<int> prev(S2+1, 0);
    vector<int> curr(S2+1, 0);
    if(arr[0]==0) prev[0] = 2;
    else {
        prev[0] = 1;
        if(arr[0]<=S2) prev[arr[0]] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int k=0; k<=S2; k++) {
            int notPick = prev[k];
            int pick = 0;
            if(arr[i]<=k) pick = prev[k-arr[i]];
            curr[k] = pick + notPick;
        }
        prev = curr;
    }
    return prev[S2];
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

    // In this problem, we are given an array of integers and a target, and our aim is to find the number of ways we can assign '+' and '-' sign to the elements of the array such that when we sum the elements along with signs, it results into target.

    // So, if we consider the subset of positive elements to have sum S1
    // And the subset of negative elements to have a sum -S2.
    // Then S1 + (-S2) = target (or D) -> S1 - S2 = D
    // So, now this becomes a problem of DP18, where we took S1 + S2 = TotalSum, so S2 = (TotalSum-D)/2
    // Here, (TotalSum-D)>=0 and (TotalSum-D)%2==0
    // From here we see that the answer is the number of ways to generate a subArray with sum S2 = (TotalSum-D)/2.

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int target;
    cin >> target;
    int TotalSum = 0;
    for(int i=0; i<n; i++) TotalSum += arr[i];
    if((TotalSum-target)<0 || (TotalSum-target)%2!=0) {
        cout << 0 << endl;
        return 0;
    }
    int S2 = (TotalSum-target)/2;

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n, vector<int>(S2+1,-1));
    int ways1 = numOfWays(n-1,S2,arr,dp1);
    cout << ways1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n, vector<int>(S2+1,0));
    int ways2 = numOfWaysTab(n,S2,arr,dp2);
    cout << ways2 << endl;

    // Space-Optimization Approach:
    int ways3 = numOfWaysSO(n, S2, arr);
    cout << ways3 << endl;

    return 0;
}
