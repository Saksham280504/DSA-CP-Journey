#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1e9)); // dp[i][j] = minimum cost to reach {i,j} from {0,0}
        deque<pair<int,int>> dq;
        dp[0][0] = grid[0][0];
        dq.push_back({0,0});
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

        while(!dq.empty()) {
            auto [r,c] = dq.front();
            dq.pop_front();
            for(int i=0; i<4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m) {
                    int wt = grid[nr][nc];
                    if(dp[r][c] + wt < dp[nr][nc]) {
                        dp[nr][nc] = dp[r][c] + wt;
                        if(wt==0) dq.push_front({nr,nc}); // 0 weight was added, explore {nr,nc} immediately after {r,c}
                        else dq.push_back({nr,nc}); // 1 weight was added, explore {nr,nc} later when all 0 weight paths have been explored.
                    }
                }
            }
        }

        return dp[n-1][m-1];
    }
};

// This is a classic example of 0-1 BFS using a deque. 
// Whenever we are asked to find the minimum cost path, for an unweighted graph we use normal BFS using a queue, for arbitary weighted graph we use Djikstra's algorithm we use a priority_queue, and for a 0/1 weighted graph, we use deque.
// When using deque, if weight (grid[i][j]) == 0, then push in front, else push in back.


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
