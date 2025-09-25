#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int minPath(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp) {
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = minPath(i-1,j,grid,dp) == 0 ? -1: grid[i][j] + minPath(i-1,j,grid,dp);
    int left = minPath(i,j-1,grid,dp) == 0 ? -1 : grid [i][j] + minPath(i,j-1,grid,dp);
    if(up<0) return left;
    if(left<0) return up;
    return dp[i][j] = min(up,left);

    // Recursive Approach:
    // TC -> O(2^(m*n))
    // SC -> O(path-length) -> O(m-1+n-1) (stack-space)

    // Memoization Approach:
    // TC -> O(m*n)
    // SC -> O(m-1+n-1) (stack-space) + O(m*n) (dp-array)
}

int minPathTab(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else {
                int up = 0;
                int left = 0;
                if(i>0) up = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];
                if(up==0) dp[i][j] = left;
                else if(left==0) dp[i][j] = up;
                else dp[i][j] = min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}

int minPathSO(int n, int m, vector<vector<int>>& grid) {
    vector<int> dp(m,0);
    for(int i=0; i<n; i++) {
        vector<int> temp(m);
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) temp[j] = grid[i][j];
            else {
                int up = 0;
                int left = 0;
                if(i>0) up = grid[i][j] + dp[j];
                if(j>0) left = grid[i][j] + temp[j-1];
                if(up==0) temp[j] = left;
                else if(left==0) temp[j] = up;
                else temp[j] = min(up,left);
            }
        }
        dp = temp;
    }
    return dp[m-1];
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
    vector<vector<int>> grid;
    for(int i=0; i<n; i++) {
        vector<int> temp(m);
        for(int j=0; j<m; j++) {
            cin >> temp[j];
        }
        grid.push_back(temp);
    }
    vector<vector<int>> dp(n,vector<int>(m,-1));

    // Recursive/Memoization Approach:
    // int cost = minPath(n-1,m-1,grid,dp);
    // cout << cost << endl;

    // Tabulation Approach:
    // int cost = minPathTab(n,m,grid,dp);
    // cout << cost << endl;

    // Space-Optimization Approach:
    int cost = minPathSO(n,m,grid);
    cout << cost << endl;
    return 0;
}
