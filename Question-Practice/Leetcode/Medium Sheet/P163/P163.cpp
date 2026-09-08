#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

 class Solution {
private:
    int n,m;
    int dfs(int r, int c, vector<vector<int>>& grid) {
        if(r>=n || c>=m || r<0 || c<0 || grid[r][c]==0) return 0;
        int gold = grid[r][c];
        grid[r][c] = 0;
        int max_further_gold = 0;
        max_further_gold = max(max_further_gold,dfs(r-1,c,grid));
        max_further_gold = max(max_further_gold,dfs(r,c+1,grid));
        max_further_gold = max(max_further_gold,dfs(r+1,c,grid));
        max_further_gold = max(max_further_gold,dfs(r,c-1,grid));
        grid[r][c] = gold;
        return max_further_gold + gold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]>0) maxGold = max(maxGold,dfs(i,j,grid));
            }
        }
        return maxGold;
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
