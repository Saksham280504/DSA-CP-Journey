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
        q.push({1,{src[0],src[1]}});
    }
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if(row==dest[0] && col==dest[1]) return dis; // Check for destination while taking out of the priority queue & not while inserting it.

        for(int delrow=-1; delrow<=1; delrow++) {
            for(int delcol=-1; delcol<=1; delcol++) {
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]!=1 && dist[row][col]+1<dist[nrow][ncol]) {
                dist[nrow][ncol] = dis + 1;
                q.push({dist[nrow][ncol],{nrow,ncol}});
            }
            }
        }
    }
    return -1;

    // TC -> O(ElogV) where E(edges)->(n*m*4) & V -> (n*m)
    // SC -> near about O(N*M) (dist array)
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
