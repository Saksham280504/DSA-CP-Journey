#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int maxPathSum(int i, int j, int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(j<0 || j>=m) return -1e9;
    if(i==0) return arr[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int ld = arr[i][j] + maxPathSum(i-1,j-1,n,m,arr,dp);
    int rd = arr[i][j] + maxPathSum(i-1,j+1,n,m,arr,dp);
    int s = arr[i][j] + maxPathSum(i-1,j,n,m,arr,dp);
    return dp[i][j] = max(s,max(ld,rd));

    // Recursion Approach:
    // TC -> O(m*(3^n)) (exponential)
    // SC -> O(N) (recursion stack-space)

    // Memoization Approach:
    // TC -> O(m*n)
    // SC -> O(n) (recursion stack-space) + O(n*m) (dp-array)
}

int maxPathTab(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    for(int j=0; j<m; j++) {
        dp[0][j] = arr[0][j];
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            int ld = arr[i][j];
            if(j>0) ld += dp[i-1][j-1];
            int rd = arr[i][j];
            if(j<m-1) rd += dp[i-1][j+1];
            int s = arr[i][j] + dp[i-1][j];
            dp[i][j] = max(s, max(ld,rd));
        }
    }
    int maxi = INT_MIN;
    for(int j=0; j<m; j++) {
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;

    // TC -> O(N*M)
    // SC -> O(N)
}

int maxPathSO(int n, int m, vector<vector<int>>& arr) {
    vector<int> dp(m,0);
    for(int j=0; j<m; j++) {
        dp[j] = arr[0][j];
    }

    for(int i=1; i<n; i++) {
        vector<int> temp(m);
        for(int j=0; j<m; j++) {
            int ld = arr[i][j];
            if(j>0) ld += dp[j-1];
            int rd = arr[i][j];
            if(j<m-1) rd += dp[j+1];
            int s = arr[i][j] + dp[j];
            temp[j] = max(s, max(ld,rd));
        }
        dp = temp;
    }
    
    int maxi = INT_MIN;
    for(int j=0; j<m; j++) {
        maxi = max(maxi,dp[j]);
    }
    return maxi;

    // TC -> O(N*M)
    // SC -> O(2*M)
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

    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr;
    for(int i=0; i<n; i++) {
        vector<int> temp(m);
        for(int j=0; j<m; j++) {
            cin >> temp[j];
        }
        arr.push_back(temp);
    }

    vector<vector<int>> dp(n,vector<int>(m,-1));

    // Recursive/ Memoization Approach:
    int maxi = INT_MIN;
    for(int j=0; j<m; j++) {
        maxi = max(maxi, maxPathSum(n-1,j,n,m,arr,dp));
    }
    cout << maxi << endl;

    // Tabulation Approach:
    cout << maxPathTab(n,m,arr,dp) << endl;

    // Space-Optimization Approach:
    cout << maxPathSO(n,m,arr) << endl;
    return 0;
}
