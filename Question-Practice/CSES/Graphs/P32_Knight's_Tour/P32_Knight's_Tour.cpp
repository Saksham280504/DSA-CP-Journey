#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int N = 8;
vector<int> dx = {1,2,2,1,-1,-2,-2,-1};
vector<int> dy = {2,1,-1,-2,-2,-1,1,2};
vector<vector<int>> board;

bool isInside(int x, int y) {
    return (x>=0  && y>=0 && x<N && y<N);
}

int futureMoves(int x, int y) {
    int cnt = 0;
    for(int k=0; k<8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(isInside(nx,ny) && board[nx][ny]==0) cnt++;
    }
    return cnt;
}

bool dfs(int x, int y, int steps) {
    board[x][y] = steps;
    if(steps==N*N) return true;
    vector<pair<int,pair<int,int>>> cand; // {deg,{x,y}}
    for(int k=0; k<8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(isInside(nx,ny) && board[nx][ny]==0) {
            int deg = futureMoves(nx,ny);
            cand.push_back({deg,{nx,ny}});
        }
    }
    sort(cand.begin(), cand.end());

    for(auto &nei: cand) {
        int nx = nei.second.first;
        int ny = nei.second.second;
        if(dfs(nx,ny,steps+1)) return true;
    }

    board[x][y] = 0;
    return false;
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
    int sx, sy;
    cin >> sx >> sy;
    sx--;
    sy--;
    board.assign(N,vector<int>(N,0));

    if(!dfs(sy,sx,1)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    for(auto row: board) {
        for(auto cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
