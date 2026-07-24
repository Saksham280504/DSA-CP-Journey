#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int n,m;
vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x, int y) {
    vis[x][y] = true;
    for(auto [delx, dely] : dir) {
        int newX = x + delx;
        int newY = y + dely;
        if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]!='#' && !vis[newX][newY]) dfs(newX,newY);
    }
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
    cin >> n >> m;
    grid.resize(n,vector<char>(m));
    vis.assign(n,vector<bool>(m,false));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    int rooms = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='.' && !vis[i][j]) {
                dfs(i,j);
                // could also perform bfs(i,j)
                rooms++;
            }
        }
    }
    cout << rooms << endl;

    // TC -> O(N*M)
    // SC -> O(N*M) (vis grid) + O(N*M) (for recursive stack(DFS) or queue(BFS))

    return 0;
}
