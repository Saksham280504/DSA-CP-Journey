#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int n,m;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(int i, int j, vector<vector<int>>& hashMat, vector<vector<int>>& matrix) {
        if(hashMat[i][j]>0) return hashMat[i][j];
        int maxLen = 1;
        for(auto d: dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if(ni>=0 && nj>=0 && ni<n && nj<m && matrix[ni][nj] > matrix[i][j]) {
                maxLen = max(maxLen,1+dfs(ni,nj,hashMat,matrix));
            }
        }
        return hashMat[i][j] = maxLen;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> hashMat(n,vector<int>(m,0));
        int maxLen = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                maxLen = max(maxLen,dfs(i,j,hashMat,matrix));
            }
        }
        return maxLen;
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
