#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int n;
    void dfs(int r, int c, vector<vector<int>>& grid,queue<pair<int,int>>& q) {
        grid[r][c] = 2;
        q.push({r,c});
        for(auto d: dir) {
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1) {
                dfs(nr,nc,grid,q);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> q;
        bool found = false;
        for(int r=0; r<n && !found; r++) {
            for(int c=0; c<n; c++) {
                if(grid[r][c]) {
                    dfs(r,c,grid,q);
                    found = true;
                    break;
                }
            }
        }

        int steps = 0;
        while(!q.empty()) {
            int q_size = q.size();
            while(q_size--) {
                auto [r,c] = q.front();
                q.pop();
                for(auto d: dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if(nr>=0 && nc>=0 && nr<n && nc<n) {
                        if(grid[nr][nc]==1) {
                            return steps;
                        }
                        if(grid[nr][nc]==0) {
                            grid[nr][nc] = 2;
                            q.push({nr,nc});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
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
