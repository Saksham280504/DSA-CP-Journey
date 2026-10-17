#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    vector<int> row;
    vector<int> col;
    vector<int> boxes;
    vector<pair<int,int>> emptyCells;
    int box_index(int r, int c) {
        return (r/3)*3 + (c/3);
    }
    bool backTrack(int idx, vector<vector<char>>& board) {
        if(idx==emptyCells.size()) return true;
        auto [r,c] = emptyCells[idx];
        int box = box_index(r,c);
        int used = row[r] | col[c] | boxes[box];
        for(int d=1; d<=9; d++) {
            int mask = 1<<d;
            if(!(used&mask)) {
                row[r] |= mask;
                col[c] |= mask;
                boxes[box] |= mask;
                board[r][c] = d+'0';
                if(backTrack(idx+1,board)) return true;
                row[r] &= ~mask;
                col[c] &= ~mask;
                boxes[box] &= ~mask;
                board[r][c] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        row.assign(9,0);
        col.assign(9,0);
        boxes.assign(9,0);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j]!='.') {
                    int d = board[i][j] - '0';
                    int mask = 1<<d;
                    row[i] |= mask;
                    col[j] |= mask;
                    boxes[box_index(i,j)] |= mask;
                }
                else {
                    emptyCells.push_back({i,j});
                }
            }
        }
        backTrack(0,board);
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
