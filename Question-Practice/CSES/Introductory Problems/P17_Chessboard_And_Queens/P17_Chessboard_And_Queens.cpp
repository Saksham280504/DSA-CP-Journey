#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<string> board(8);
vector<bool> col(8);
vector<bool> diag1(8); // row + col -> [0....14]
vector<bool> diag2(8); // row - col -> [-7....7]
int ans = 0;

// The idea is to place 1 queen on 1 row such that no two queens share the same column or diagonals
void solve(int row) {
    if(row==8) {
        ans++;
        return;
    }
    for(int c=0; c<8; c++) {
        if(board[row][c]=='*') continue; // you can't place on the reserved cell, so continue
        if(col[c] || diag1[row+c] || diag2[row-c+7]) continue; // some queen already present on this column or diagonal, hence can't place here so continue
        col[c] = true;
        diag1[row+c] = true;
        diag2[row-c+7] = true;
        solve(row+1);
        col[c] = false;
        diag1[row+c] = false;
        diag2[row-c+7] = false;
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
    for(int i=0; i<8; i++) cin >> board[i];
    solve(0);
    cout << ans << endl;

    return 0;
}
