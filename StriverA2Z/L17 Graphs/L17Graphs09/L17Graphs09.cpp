#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int orangesRotting(vector<vector<int>>& farm) {
    int n = farm.size();
    int m = farm[0].size();
    
    // {{r,c},t}
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(farm[i][j]==2) {
                q.push({{i,j},0});
                vis[i][j]=2;
            }
        }
    }

    vector<int> delRow = {-1,0,1,0};
    vector<int> delCol = {0,1,0,-1};
    int tm = 0;
    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        tm = max(time,tm);
        q.pop();
        vis[row][col] = 2;
        for(int i=0; i<4; i++) {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && farm[nrow][ncol]==1) {
                q.push({{nrow,ncol},time+1});
                vis[nrow][ncol] = 2;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(farm[i][j]==1 && vis[i][j]!=2) return -1;
        }
    }
    return tm;

    // SC -> O(N*M) (queue holds all the oranges which can be rotten and on the worst case it can hold all the oranges at a time) + O(N*M) (visited array)

    // TC -> O(N*M) (initial run to get rotten oranges at t=0) + O(4*X) (where X is the total number of rotten oranges in the end)
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
    vector<vector<int>> farm;

    for(int i=0; i<n; i++) {
        vector<int> arr(m);
        for(int j=0; j<m; j++) {
            cin >> arr[j];
        }
        farm.push_back(arr);
    }

    int num = orangesRotting(farm);
    cout << num << endl;

    return 0;
}
