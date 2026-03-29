#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        // Aim is to maximize the distance of every water cell with its nearest land cell
        // But if we go and perform BFS for every water cell, that would take a TC -> O(N^4) (TLE)
        // Thus we think backward and perform a multi-source BFS, where we select all the land cells first and then expand.
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) q.push({i,j}); // pushing all the initial land cells into the queue
            }
        }

        if(q.empty() || q.size()==(n*n)) return -1; // If all cells are land cells or water cells, then return -1.

        int dist = -1;
        vector<int> del = {0,1,0,-1,0};

        while(!q.empty()) {
            int size = q.size();
            dist++; // Now we have the distance/level from all the current land/visited cells from the initial land cells (Initial distance = 0)
            
            while(size--) {
                auto [x,y] = q.front(); // We don't use &[x,y] here, as after it is popped out from queue, there is no reference to its address. Thus create a copy as it is in the end getting popped out.
                q.pop();
                for(int d=0; d<4; d++) {
                    int nx = x + del[d];
                    int ny = y + del[d+1];
                    if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0) {
                        grid[nx][ny] = 1; // mark visited by changing into land cell, as if this cell is visited afterwards, then the dist at that time will only be higher or equal to the current dist
                        q.push({nx,ny});
                    }
                }
            }
        }

        return dist;
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
