#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int TriangleMinPathSum(int i, int j, int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(i==n-1) return arr[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int d = arr[i][j] + TriangleMinPathSum(i+1,j,n,arr,dp);
    int dg = arr[i][j] + TriangleMinPathSum(i+1,j+1,n,arr,dp);
    return dp[i][j] = min(d,dg);

    // For recursive Approach:
    // TC -> O(2^(n(n+1)/2))
    // SC -> O(N)

    // For memoized Approach:
    // TC -> O(N*N)
    // SC -> O(N) (recursion stack-space) + O(N*N) (DP-Array)
}

int minPathTab(int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    for(int j=0; j<n; j++) {
        dp[n-1][j] = arr[n-1][j];
    }
    for(int i=n-2; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            int d = arr[i][j] + dp[i+1][j];
            int dg = arr[i][j] + dp[i+1][j+1];
            dp[i][j] = min(d,dg);
        }
    }
    return dp[0][0];

    // TC -> O(N*N)
    // SC -> O(N*N)
}

int minPathSO(int n, vector<vector<int>>& arr) {
    vector<int> dp(n+1,0);
    for(int i=n-1; i>=0; i--) {
        vector<int> temp(i+1);
        for(int j=0; j<=i; j++) {
            temp[j] = min(arr[i][j]+dp[j], arr[i][j]+dp[j+1]);
        }
        for(int j=0; j<=i; j++) {
            dp[j] = temp[j];
        }
    }
    return dp[0];

    // TC -> O(N*N)
    // SC -> O(2N)
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
    vector<vector<int>> arr;
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<i+1; j++) {
            int nums;
            cin >> nums;
            temp.push_back(nums);
        }
        arr.push_back(temp);
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));

    // Recursive/Memoization Approach:
    // int cnt = TriangleMinPathSum(0,0,n,arr,dp);
    // cout << cnt << endl;

    // Tabulation Approach:
    // int cnt = minPathTab(n,arr,dp);
    // cout << cnt << endl;

    // Space-Optimization Approach:
    int cnt = minPathSO(n,arr);
    cout << cnt << endl;

    return 0;
}
