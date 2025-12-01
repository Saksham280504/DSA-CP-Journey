#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traversal the neighbours and mark them if its a land (Neighbour checking)
        for(int delrow = -1; delrow<=1; delrow++) {
            for(int delcol = -1; delcol<=1; delcol++) {
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

}
int numOfIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt =0;
    for(int row=0; row<n; row++) {
        for(int col=0; col<m; col++) {
            if(!vis[row][col] && grid[row][col]=='1') {
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
    }

    return cnt;

    // SC -> O(N^M) (vis 2-D Array) + O(N^M) (worst-case for queue space which occurs when all the entries in the grid are '1')
    // TC -> O(N*M) (traversal of grid) + O(Number of lands) -> O(N*M) +O(N*M*9) (worst case)
    // For every bfs call, we get one island and whenver a bfs call occurs, neighbour checking is performed for all the lands part of that island. In this question too, bfs call was made on:
    // (0,1), (4,0) and (4,3)
    // Due to bfs call on (0,1), neighbour checking was performed on (0,1),(1,1),(0,2),(1,2),(2,2) i.e. on the land points of that island
    // After that due to the bfs call on (4,0), neighbour checking was performed on (4,0) and (4,1).
    // Lastly for bfs call (4,3), neighbour checking was performed on (4,3). Therefore, for all the land points of the grid, a neighbour checking is performed which involves 9 (3*3) steps.
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
    vector<vector<char>> grid;

    for(int i=0; i<n; i++) {
        vector<char> arr(m);
        for(int j=0; j<m; j++) {
            cin >> arr[j];
        }
        grid.push_back(arr);
    }

    int cnt = numOfIslands(grid);

    cout << cnt << endl;

    return 0;
}
