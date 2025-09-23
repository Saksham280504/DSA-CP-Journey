#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int MaxNonAdjacentSum(int ind, vector<int>& arr, vector<int>& dp) {
    if(ind==0) return arr[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick = arr[ind] + MaxNonAdjacentSum(ind-2, arr,dp);
    int notpick = 0 + MaxNonAdjacentSum(ind-1, arr,dp);
    return dp[ind] = max(pick,notpick);
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
    vector<int> dp(n,-1);

    // Recursive/Memoization Approach:
    // int maxSum = MaxNonAdjacentSum(n-1,arr,dp);
    // cout << maxSum << endl;

    // Recursive Approach -> TC -> O(2^N), SC -> O(N) (stack-space)
    // Memoization Approach -> TC -> O(N), SC -> O(N) (stack-space) + O(N) (DP-Array)

    // Tabulation-Approach:
    // dp[0] = arr[0];
    // for(int i=1; i<n; i++) {
    //     int take = arr[i];
    //     if(i>1) take += dp[i-2];
    //     int nontake = 0 + dp[i-1];
    //     dp[i] = max(take, nontake);
    // }
    // cout << dp[n-1] << endl;

    // TC -> O(N)
    // SC -> O(N)

    // SPace-optimization Approach:
    
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1; i<n; i++) {
        int pick = arr[i];
        if(i>1) pick += prev2;
        int notpick = 0 + prev;
        int curi = max(pick, notpick);
        prev2 = prev;
        prev = curi;
    }
    cout << prev << endl;
    
    return 0;
}
