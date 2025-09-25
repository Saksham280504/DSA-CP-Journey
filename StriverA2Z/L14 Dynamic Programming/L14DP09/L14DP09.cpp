#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numberOfPaths(int i, int j,vector<vector<int>>& maze, vector<vector<int>>& dp) {
    if(maze[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = numberOfPaths(i-1,j,maze,dp);
    int left = numberOfPaths(i,j-1,maze,dp);
    return dp[i][j] = up + left;
    
    // For recursive Approach:
    // TC -> O(2^(mXn))
    // SC -> O(length of path) -> O(m-1+n-1) (stack-space)

    // For memoization Approach:
    // TC -> O(n*m)
    // SC -> O(length of path) + O(dp-array) -> O(m-1+n-1) + O(m*n)
}

int numOfPathsTab(int m, int n, vector<vector<int>>& maze, vector<vector<int>>& dp) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(maze[i][j]==-1) dp[i][j] = 0;
            else if(i==0 && j==0) dp[i][j] = 1;
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

    // TC -> O(m*n)
    // SC -> O(m*n)
}

int numOfPathsSO(int m, int n, vector<vector<int>>& maze) {
    vector<int> dp(n,0);
    for(int i=0; i<m; i++) {
        vector<int> temp(n);
        if(maze[i][0]==-1) temp[0] = 0;
        else if(i==0) temp[0] = 1;
        else temp[0] = dp[0];
        for(int j=1; j<n; j++) {
            if(maze[i][j]==-1) temp[j] = 0;
            else temp[j] = temp[j-1] + dp[j];
        }
        dp = temp;
    }
    return dp[n-1];

    // TC -> O(N*M)
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
    int m,n;
    cin >> m >> n;
    vector<vector<int>> maze;
    for(int i=0; i<m; i++) {
        vector<int> temp(n);
        for(int j=0; j<n; j++) {
            cin >> temp[j];
        }
        maze.push_back(temp);
    }
    vector<vector<int>> dp(m,vector<int>(n,-1));
    // Recursive/ Memoization Approach:
    // int num = numberOfPaths(m-1,n-1,maze,dp);
    // cout << num << endl;

    // Tabulation Approach:
    int num = numOfPathsTab(m,n,maze,dp);
    cout << num << endl;

    // Space-Optimization Approach:
    return 0;
}
