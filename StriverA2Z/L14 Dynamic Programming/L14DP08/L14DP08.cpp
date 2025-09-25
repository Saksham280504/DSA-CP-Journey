#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numOfPaths(int i, int j, vector<vector<int>>& dp) {
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = numOfPaths(i-1,j,dp);
    int left = numOfPaths(i,j-1,dp);
    return dp[i][j] = up + left;

    // For only recursive Approach
    // TC -> O(2^(m*n))
    // SC -> O(length of path) -> O((m-1)+(n-1))

    // For memoization Approach:
    // TC -> O(MXN)
    // SC -> O(Path-length) (Recursive stack-space) + O(MXN) (DP-array)
}

int numOfPathsTab(int m, int n, vector<vector<int>>& dp) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 && j==0) dp[i][j] = 1;
            else {
                int up = 0;
                int left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];

    // TC -> O(NXM)
    // SC -> O(NXM)
}

int numOfPathsSO(int m, int n) {
    vector<int> dp(n,0);

    for(int i=0; i<m; i++) {
        vector<int> temp(n);
        if(i==0) temp[0] = 1;
        else temp[0] = dp[0];
        for(int j=1; j<n; j++) {
            temp[j] = temp[j-1] + dp[j];
        }
        dp = temp;
    }

    return dp[n-1];
    // TC -> O(MXN)
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

    // DP on Grids:

    // Here, we typically deal with 6 type of problems which are:

    // 1. Count number of possible unique paths
    // 2. Count paths with obstacles
    // 3. Minimum Path Sum
    // 4. Maximum Path Sum
    // 5. Triangle
    // 6. 2 Start Points

    // 1. Count number of possible unique paths

    // An (MXN) matrix/grid is given to us, and we need to count the number of unique paths that can be taken to reach to the point (m-1,n-1).

    int m,n;
    cin >> m >> n;
    vector<vector<int>> dp(m,vector<int>(n,-1));

    // Recursive/Memoization Approach:
    // int numOfWays = numOfPaths(m-1,n-1,dp);
    // cout << numOfWays << endl;

    // Tabulation Approach:
    // int numOfWays = numOfPathsTab(m,n,dp);
    // cout << numOfWays << endl;

    // Space-Optimization Approach:
    int numOfWays = numOfPathsSO(m,n);
    cout << numOfWays << endl;
    return 0;
}
