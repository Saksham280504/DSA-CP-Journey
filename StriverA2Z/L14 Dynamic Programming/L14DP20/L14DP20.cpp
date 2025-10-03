#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int minCoins(int ind, int target, vector<int>& arr,  vector<vector<int>>& dp) {
    // Procedure:
    // 1. f(ind, target)
    // 2. Express every possibility (notTake, take)
    // 3. Return the min of all possibilities
    // 4. Form the base-case i.e. the array has only one-type of coin and you are given a certain target, here the target can only be achieved if the target is divisible by arr[0] otherwise not even infinite coins can sum up to form that target.

    if(ind==0) {
        if(target%arr[ind]==0) return target/arr[ind];
        return 1e9;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notPick = 0 + minCoins(ind-1,target,arr, dp);
    int pick = INT_MAX;
    if(arr[ind]<=target) pick = 1 + minCoins(ind,target-arr[ind],arr, dp);
    return dp[ind][target] = min(pick,notPick);

    // For recursive approach:

    // TC -> We can't determine the exact TC here, but we are sure that the TC is very much greater than O(2^n), because here we don't need to necessarily move from ind to ind-1.
    // SC -> way greater than O(N) -> O(target)

    // For memoization Approach:
    // TC -> O(N*T)
    // SC -> O(N*T) + O(T)
}

int minCoinsTab(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
    for(int k=0; k<=target; k++) {
        if(k%arr[0]==0) dp[0][k] = k/arr[0];
        else dp[0][k] = 1e9;
    }

    for(int i=1; i<n; i++) {
        for(int k=0; k<=target; k++) {
            int notPick = 0 + dp[i-1][k];
            int pick = INT_MAX;
            if(arr[i]<=k) pick = 1 + dp[i][k-arr[i]];
            dp[i][k] = min(pick,notPick);
        }
    }

    return dp[n-1][target];

    // TC -> O(N*T)
    // SC -> O(N*T)
}

int minCoinsSO(int n, int target, vector<int>& arr) {
    vector<int> prev(target+1, 1e9);
    vector<int> curr(target+1, 1e9);
    for(int k=0; k<=target; k++) {
        if(k%arr[0]==0) prev[k] = k/arr[0];
    }

    for(int i=1; i<n; i++) {
        for(int k=0; k<=target; k++) {
            int notPick = 0 + prev[k];
            int pick = 1e9;
            if(arr[i]<=k) pick = 1 + curr[k-arr[i]];
            curr[k] = min(pick,notPick);
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

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int target;
    cin >> target;

    // For Recursive/Memoization Approach:
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    int mini1 = minCoins(n-1,8,arr,dp);
    cout << mini1 << endl;

    // For Tabulation Approach:
    vector<vector<int>> dp1(n, vector<int>(target+1, 1e9));
    int mini2 = minCoinsTab(n,8,arr,dp1);
    cout << mini2 << endl;

    int mini3 = minCoinsSO(n,8,arr);
    cout << mini3 << endl;

    return 0;
}
