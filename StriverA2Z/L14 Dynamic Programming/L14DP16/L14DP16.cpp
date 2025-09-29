#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/'
 
int isPartitionPossible(int n, int target, vector<int>& arr, vector<vector<bool>>& dp) {
    for(int i=0; i<n; i++) {
        dp[i][0] = true;
    }
    if(arr[0]<=target) dp[0][arr[0]] = true;

    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i]<=k) take = dp[i-1][k-arr[i]];
            dp[i][k] = take | notTake;
        }
    }

    int mini = INT_MAX;
    for(int k=0; k<=target; k++) {
        if(dp[n-1][k]==true) mini = min(mini,abs(k-(target-k)));
    }

    return mini;
}

int isPartitionPossibleSO(int n, int target, vector<int>& arr) {
    vector<bool> prev(target+1,false);
    vector<bool> curr(target+1,false);
    prev[0] = true;
    curr[0] = true;
    if(arr[0]<=target) prev[arr[0]] = true;
    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
            bool notTake = prev[k];
            bool take = false;
            if(arr[i]<=k) take = prev[k-arr[i]];
            curr[k] = take | notTake;
        }
        prev = curr;
    }

    int mini = INT_MAX;
    for(int k=0; k<=target; k++) {
        if(prev[k]) mini = min(mini, abs(k-(target-k)));
    }
    return mini;
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

    // I need to partition a set into two subsets with minimum absolute sum difference. For this we use the same concept of DP on subsequences as per L14DP14, where we see that tabulation approach allows us to check whether we can generate a subsequence with sum 1 to target from an array of size n (0->n-1 elements).

    int n;
    cin >> n;
    vector<int> arr(n);
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));

    int minDiff = isPartitionPossible(n,sum,arr,dp);

    cout << minDiff << endl;

    int miniDiffSO = isPartitionPossibleSO(n,sum,arr);
    cout << miniDiffSO << endl;

    return 0;
}
