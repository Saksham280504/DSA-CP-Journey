#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// The key insight of the problem is to understand the grid as a graph, where we are trying to look for a cyclic undirected graph.
class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;
    vector<int> dir = {0,1,0,-1,0};

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        vis[x][y] = true;
        for(int i=0; i<4; i++) {
            int nx = x + dir[i];
            int ny = y + dir[i+1];
            if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
            if(grid[nx][ny]!=grid[x][y]) continue;
            if(nx==px && ny==py) continue;
            if(vis[nx][ny]) return true;
            if(dfs(nx,ny,x,y,grid)) return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m,vector<bool>(n,false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j]) {
                    if(dfs(i,j,-1,-1,grid)) return true;
                }
            }
        }
        return false;
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
