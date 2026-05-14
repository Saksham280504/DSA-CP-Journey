#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1') return;
        grid[i][j] = '0';
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
    }
    public:
    // DFS Approach
        // int numIslands(vector<vector<char>>& grid) {
        //     int n = grid.size();
        //     int m = grid[0].size();
        //     int cnt = 0;
        //     for(int i=0; i<n; i++) {
        //         for(int j=0; j<m; j++) {
        //             if(grid[i][j]=='1') {
        //                 cnt++;
        //                 dfs(i,j,grid);
        //             }
        //         }
        //     }
        //     return cnt;

        //     // TC -> O(N*M)
        //     // SC -> O(N*M) (worst case)
        // }
    
    // BFS Approach
        int numIslands(vector<vector<char>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> del = {{0,1},{1,0},{-1,0},{0,-1}};
            int cnt = 0;
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(grid[i][j]=='1') {
                        cnt++;
                        queue<pair<int,int>> q;
                        q.push({i,j});
                        grid[i][j] = '0';
                        while(!q.empty()) {
                            auto [x,y] = q.front();
                            q.pop();
                            for(auto d: del) {
                                int nx = x + d[0];
                                int ny = y + d[1];
                                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!='1') continue;
                                q.push({nx,ny});
                                grid[nx][ny] = '0';
                            }
                        }
                    }
                }
            }

            return cnt;

            // TC -> O(N*M)
            // SC -> O(N*M)
        }
};

class Solution {
    private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='1') return;
        grid[i][j] = '0';

        dfs(grid,i,j+1);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
    }
public:
    // DFS Method
    // int numIslands(vector<vector<char>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     int cnt = 0;

    //     for(int i=0; i<m; i++) {
    //         for(int j=0; j<n; j++) {
    //             if(grid[i][j]=='1') {
    //                 cnt++;
    //                 dfs(grid,i,j);
    //             }
    //         }
    //     }

    //     return cnt;

    //     // TC -> O(n*m)
            // SC -> O(N*M) (recursion stack-space (worst case))
    // }

    // BFS Method
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> del = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1') {
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';

                    while(!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();
                        for(auto d: del) {
                            int ni = x + d[0];
                            int nj = y + d[1];
                            if(ni<0 || nj<0 || ni>=m || nj>=n || grid[ni][nj]!='1') continue;
                                q.push({ni,nj});
                                grid[ni][nj] = '0';
                        }
                    }
                }
            }
        }

        return cnt;

        // TC -> O(N*M)
        // SC -> O(1)
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
