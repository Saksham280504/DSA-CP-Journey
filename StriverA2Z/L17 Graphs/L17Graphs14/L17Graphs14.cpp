#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<int>& delrow, vector<int>& delcol) {
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    for(int i=0; i<4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1) {
            dfs(nrow,ncol,vis,grid,delrow,delcol);
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};

    for(int j=0; j<m; j++) {
        if(grid[0][j]==1 && !vis[0][j]) {
            dfs(0,j,vis,grid,delrow,delcol);
        }
    }

    for(int i=0; i<n; i++) {
        if(grid[i][0]==1 && !vis[i][0]) {
            dfs(i,0,vis,grid,delrow,delcol);
        }
    }

    for(int j=0; j<m; j++) {
        if(grid[n-1][j]==1 && !vis[n-1][j]) {
            dfs(n-1,j,vis,grid,delrow,delcol);
        }
    }

    for(int i=0; i<n; i++) {
        if(grid[i][m-1]==1 && !vis[i][m-1]) {
            dfs(i,m-1,vis,grid,delrow,delcol);
        }
    }
    int cnt = 0;
    for(int i=1; i<n-1; i++) {
        for(int j=1; j<m-1; j++) {
            if(grid[i][j]==1 && !vis[i][j]) cnt++;
        }
    }

    return cnt;
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
        vector<int> arr(m); 
        for(int j=0; j<m; j++) {
            cin >> arr[j];
        }
        grid.push_back(arr);
    }



    return 0;
}
