#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int lis(int ind, int prev_ind, int n, vector<int>& arr, vector<vector<int>>& dp) {
    if(ind==n) return 0;
    if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    int len = 0 + lis(ind+1,prev_ind,n,arr,dp);
    if(prev_ind==-1||arr[ind]>arr[prev_ind]) len = max(len, 1 + lis(ind+1,ind,n,arr,dp));
    return dp[ind][prev_ind+1] = len;

    // Recursive Approach:
    // TC -> O(2^n) Exponential
    // SC -> O(N) (auxillary stack-space)

    // Memoization Approach:
    // TC -> O(N*N)
    // SC -> O(N*N) + O(N)
}

int lisTab(int n, vector<int>& arr, vector<vector<int>>& dp) {
    // Base-Cases handled in declaration

    for(int ind=n-1; ind>=0; ind--) {
        for(int prev_ind=ind-1;prev_ind>=-1; prev_ind--) {
            int len = 0 + dp[ind+1][prev_ind+1];
            if(prev_ind==-1 || arr[ind]>arr[prev_ind]) len = max(len, 1 + dp[ind+1][ind+1]);
            dp[ind][prev_ind+1] = len;
        }
    }

    return dp[0][-1+1];

    // TC -> O(N*N)
    // SC -> O(N*N)
}

int lisSO(int n, vector<int>& arr) {
    vector<int> next(n+1,0);
    vector<int> curr(n+1,0);

    for(int ind=n-1; ind>=0; ind--) {
        for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--) {
            int len = 0 + next[prev_ind+1];
            if(prev_ind==-1 || arr[ind] > arr[prev_ind]) len = max(len,1 + next[ind+1]);
            curr[prev_ind+1] = len;
        }
        next = curr;
    }

    return next[-1+1];

    // TC -> O(N*N)
    // SC -> O(2N)
}

int lisBetter(int n, vector<int>& arr) {
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i=0;i<n; i++) {
        for(int prevI = 0; prevI<i; prevI++) {
            if(arr[i] > arr[prevI]) dp[i] = max(dp[i], 1 + dp[prevI]);
        }
        maxi = max(maxi,dp[i]);
    }

    return maxi;

    // TC <= O(N*N)
    // SC -> O(N)
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

    // You are given an array of n integers and you need to print the length of the largest increasing subsequence of that array.

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    // Recursive/Memoization Solution:
    vector<vector<int>> dp1(n,vector<int>(n+1,-1));
    int length1 = lis(0,-1,n,arr,dp1);
    cout << length1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1,vector<int>(n+1,0));
    int length2 = lisTab(n,arr,dp2);
    cout << length2 << endl;

    // Space-Optimization Approach:
    int length3 = lisSO(n,arr);
    cout << length3 << endl;

    return 0;
}
