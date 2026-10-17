#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    vector<vector<string>> ans;
    vector<string> board;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;

    void solve(int r, int n) {
        if(r==n) {
            ans.push_back(board);
            return;
        }
        for(int c=0; c<n; c++) {
            if(col[c] || diag1[r+c] || diag2[r-c+n-1]) continue;
            board[r][c] = 'Q';
            col[c] = true;
            diag1[r+c] = true;
            diag2[r-c+n-1] = true;
            solve(r+1,n);
            board[r][c] = '.';
            col[c] = false;
            diag1[r+c] = false;
            diag2[r-c+n-1] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n);
        col.resize(n);
        diag1.resize(2*n-1);
        diag2.resize(2*n-1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) board[i].push_back('.');
        }
        solve(0,n);
        return ans;
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
