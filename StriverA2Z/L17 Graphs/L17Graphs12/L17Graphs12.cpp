#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis(m,vector<int>(n,0));
    vector<vector<int>> dist(m,vector<int>(n));

    // {{r,c},d}
    queue<pair<pair<int,int>,int>> q;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j]==0) {
                vis[i][j] = 1;
                q.push({{i,j},0});
            }
        }
    }
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};

    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int distance = q.front().second;
        q.pop();
        dist[row][col] = distance;
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]) {
                q.push({{nrow,ncol},distance+1}); // We only push those cells in queue which haven't been visited before
                vis[nrow][ncol] = 1;
            }
        }
    }
    return dist;

    // TC -> O(N*M) (for loop) + O(N*M*4) (all the elements of the matrix are pushed once into the queue then for every element of the queue we have applied a 4-step loop)

    // SC -> O(2*N*M) (vis & dist matrix) + O(N*M) (queue space for the worst case)
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

    int m,n;
    cin >> m >> n;
    vector<vector<int>> grid;

    for(int i=0; i<m; i++) {
        vector<int> arr(n);
        for(int j=0; j<n; j++) {
            cin >> arr[j];
        }
        grid.push_back(arr);
    }
    vector<vector<int>> dist = updateMatrix(grid);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
