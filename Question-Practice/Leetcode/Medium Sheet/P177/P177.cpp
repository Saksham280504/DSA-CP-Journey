#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int n,m;
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==1) return;
        grid[i][j] = 1;
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++) {
            if(grid[i][0]==0) dfs(i,0,grid);
            if(grid[i][m-1]==0) dfs(i,m-1,grid);
        }
        for(int j=0; j<m; j++) {
            if(grid[0][j]==0) dfs(0,j,grid);
            if(grid[n-1][j]==0) dfs(n-1,j,grid);
        }
        int cnt = 0;
        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(grid[i][j]==0) {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
