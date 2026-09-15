#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int n,m;
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for(int i=0; i<4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !ocean[nr][nc]) {
                if(heights[nr][nc]>=heights[r][c]) dfs(nr,nc,ocean,heights);
            } 
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        for(int i=0; i<n; i++) {
            dfs(i,0,pacific,heights);
            dfs(i,m-1,atlantic,heights);
        }
        for(int j=0; j<m; j++) {
            dfs(0,j,pacific,heights);
            dfs(n-1,j,atlantic,heights);
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
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
