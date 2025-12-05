#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    vector<int> src = {0,0};
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dest = {n-1,m-1};

    vector<vector<int>> dist(n,vector<int>(m,1e9));
    queue<pair<int,pair<int,int>>> q;
    if(grid[src[0]][src[1]]!=1) {
        dist[src[0]][src[1]] = 1;
        q.push({0,{src[0],src[1]}});
    }
    while(!q.empty()) {
        int dis = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        for(int delrow=-1; delrow<=1; delrow++) {
            for(int delcol=-1; delcol<=1; delcol++) {
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]!=1 && dist[row][col]+1<dist[nrow][ncol]) {
                if(nrow==dest[0] && ncol == dest[1]) return dist[row][col]+1;
                dist[nrow][ncol] = dist[row][col] + 1;
                q.push({dist[nrow][ncol],{nrow,ncol}});
            }
            }
        }
    }
    if(dist[dest[0]][dest[1]]!=1e9) return dist[dest[0]][dest[1]]; // when the src & destination are same
    return -1;
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

    return 0;
}
