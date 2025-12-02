#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, vector<int>& delrow, vector<int>& delcol) {
    int n = board.size();
    int m = board[0].size();
    vis[row][col] = 1;
    for(int i=0; i<4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && ncol >=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O') {
            dfs(nrow,ncol,vis,board,delrow,delcol);
        }
    }
}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};
    
    for(int i=0; i<n; i++) {
        if(board[i][0]=='O' && !vis[i][0]) {
            dfs(i,0,vis,board,delrow,delcol);
        }
        if(board[i][m-1]=='O' && !vis[i][m-1]) {
            dfs(i,m-1,vis,board,delrow,delcol);
        }
    }
    for(int j=0; j<m; j++) {
        if(board[n-1][j]=='O' && !vis[n-1][j]) {
            dfs(n-1,j,vis,board,delrow,delcol);
        }
        if(board[0][j]=='O' && !vis[0][j]) {
            dfs(0,j,vis,board,delrow,delcol);
        }
    }

    for(int i=1; i<n-1; i++) {
        for(int j=1; j<m-1; j++) {
            if(board[i][j]=='O' && !vis[i][j]) board[i][j] = 'X';
        }
    }

    // TC -> O(N*M*4) (worst case for dfs traversal) + O(N*M) (outer for-loop)
    // SC -> O(N*M) (vis) + O(N*M) (worst case for recursion stack-space)

    // Worst case will be when all entries on board are: '0'
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
    vector<vector<char>> board;

    for(int i=0; i<n; i++) {
        vector<char> arr(m);
        for(int j=0; j<m; j++) {
            cin >> arr[j];
        }
        board.push_back(arr);
    }

    return 0;
}
