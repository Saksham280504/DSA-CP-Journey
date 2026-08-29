#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int target_keys = 0, startX = -1, startY = -1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='@') startX = i, startY = j;
                else if(grid[i][j]>='a' && grid[i][j]<='f') {
                    int ch = (grid[i][j]-'a');
                    target_keys |= (1 << ch);
                }
            }
        }
        queue<vector<int>> q; // {r,c,mask,steps}
        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(64,false)));
        q.push({startX,startY,0,0});
        vis[startX][startY][0] = true;
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()) {
            auto r = q.front()[0];
            auto c = q.front()[1];
            auto mask = q.front()[2];
            auto steps = q.front()[3];
            if(mask==target_keys) return steps;
            for(auto &d: dirs) {
                int nr = r + d[0], nc = c + d[1], newMask = mask;
                if(nr<0 || nc<0 || nr>=n || nc>=m || grid[nr][nc]=='#') continue;
                char ch = grid[nr][nc];
                if(ch>='A' && ch<='F' && !(mask&(1<<(ch-'A')))) continue; // locked and don't possess the key
                if(ch>='a' && ch<='f') {
                    newMask = (mask|(1<<(ch-'a')));
                }
                if(!vis[nr][nc][newMask]) {
                    vis[nr][nc][newMask] = true;
                    q.push({nr,nc,newMask,steps+1});
                }
            }
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
