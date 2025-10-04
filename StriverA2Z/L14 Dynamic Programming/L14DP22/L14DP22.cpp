#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numOfWays(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {   
    if(target==0) return 1;
    if(ind==0) {
        if(target%arr[ind]==0) return 1;
        return 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notTake = numOfWays(ind-1,target,arr,dp);
    int take = 0;
    if(arr[ind]<=target) take = numOfWays(ind,target-arr[ind],arr,dp);
    return dp[ind][target] = notTake + take;

    // For recursive approach:
    // TC calculation is complex, so we can just say that the TC is exponential and way greater than O(2^N)
    // SC -> O(Target)

    // For memoization Approach:
    // TC -> O(N*Target)    
    // SC -> O(N*Target) + O(Target)
}

int numOfWaysTab(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
    for(int i=0; i<n; i++) dp[i][0] = 1;
    for(int k=0; k<=target; k++) {
        if(k%arr[0]==0) dp[0][k] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
            int notPick = dp[i-1][k];
            int pick = 0;
            if(arr[i]<=k) pick = dp[i][k-arr[i]];
            dp[i][k] = pick + notPick;
        }
    }
    return dp[n-1][target];

    // TC -> O(N*target)
    // SC -> O(N*target)
}

int numOfWaysSO(int n, int target, vector<int>& arr) {
    vector<int> prev(target+1,0);
    vector<int> curr(target+1,0);
    prev[0] = 1;
    curr[0] = 1;
    for(int k=0; k<=target; k++) {
        if(k%arr[0]==0) prev[k] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
            int notPick = prev[k];
            int pick = 0;
            if(arr[i]<=k) pick = curr[k-arr[i]];
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

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int target;
    cin >> target;

    // In DP20, we were trying to find the minimum number of coins needed to make up the target, but here we are trying to find in how many ways can we make up the target. Both the questions are different!!!

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n, vector<int>(target+1, -1));
    int ways1 = numOfWays(n-1,target,arr,dp1);
    cout << ways1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n, vector<int>(target+1,0));
    int ways2 = numOfWaysTab(n, target, arr, dp2);
    cout << ways2 << endl;

    int ways3 = numOfWaysSO(n,target,arr);
    cout << ways3 << endl;
    return 0;
}
