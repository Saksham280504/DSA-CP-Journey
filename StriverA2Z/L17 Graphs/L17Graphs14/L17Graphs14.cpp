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

    for(int i=0; i<n; i++) {
        if(grid[i][0]==1 && !vis[i][0]) {
            dfs(i,0,vis,grid,delrow,delcol);
        }
        if(grid[i][m-1]==1 && !vis[i][m-1]) {
            dfs(i,m-1,vis,grid,delrow,delcol);
        }
    }

    for(int j=0; j<m; j++) {
        if(grid[0][j]==1 && !vis[0][j]) {
            dfs(0,j,vis,grid,delrow,delcol);
        }
        if(grid[n-1][j]==1 && !vis[n-1][j]) {
            dfs(n-1,j,vis,grid,delrow,delcol);
        }
    }

    int cnt = 0;
    for(int i=1; i<n-1; i++) {
        for(int j=1; j<m-1; j++) {
            if(grid[i][j]==1 && !vis[i][j]) cnt++;
        }
    }

    return cnt;

    // TC -> O(N*M*4) (worst case for dfs traversal) + O(N*M) (outer for-loop)
    // SC -> O(N*M) (vis) + O(N*M) (worst case for recursion stack-space)

    // Worst case will be when all entries on board are: 1
}

int numEnclavesBFS(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<int,int>> q;

    for(int j=0; j<m; j++) {
        if(!vis[0][j] && grid[0][j]==1) {
            q.push({0,j});
            vis[0][j]=1;
        }
        if(!vis[n-1][j] && grid[n-1][j]==1) {
            q.push({n-1,j});
            vis[n-1][j]=1;
        }
    }

    for(int i=0; i<n; i++) {
        if(!vis[i][0] && grid[i][0]==1) {
            q.push({i,0});
            vis[i][0]=1;
        }
        if(!vis[i][m-1] && grid[i][m-1]==1) {
            q.push({i,m-1});
            vis[i][m-1]=1;
        }
    }

    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1) {
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<n-1; i++) {
        for(int j=1; j<m-1; j++) {
            if(grid[i][j]==1 && !vis[i][j]) cnt++;
        }
    }

    return cnt;

    // TC -> O(N*M) (outer for-loop) + O(N*M*4) (worst case of traversal (i.e. all points are 1))

    // SC -> O(N*M) (visited array) + O(N*M) (worst case for queue)
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

    // I used DFS method to solve the problem!!
    int cnt = numEnclaves(grid);
    cout << cnt << endl;

    // Striver's Method (BFS):

    int cnt2 = numEnclavesBFS(grid);
    cout << cnt2 << endl;



    return 0;
}
