#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> preSum(n+1,vector<int>(m+1,0)); // preSum[i][j] => preSum matrix till (i-1,j-1) index
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                preSum[i+1][j+1] = mat[i][j] + preSum[i][j+1] + preSum[i+1][j] - preSum[i][j];
            }
        }
        auto getSquareSum = [&] (int r2, int c2, int sideLen) {
            int r1 = r2-sideLen+1;
            int c1 = c2-sideLen+1;
            int SquareSum = preSum[r2+1][c2+1] - preSum[r1][c2+1] - preSum[r2+1][c1] + preSum[r1][c1];
            return SquareSum; 
        };
        int maxLen = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i>=maxLen && j>=maxLen) {
                    if(getSquareSum(i,j,maxLen+1)<=threshold) maxLen++;
                }
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
