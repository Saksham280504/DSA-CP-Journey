#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxSide = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(matrix[i-1][j-1]=='0') dp[i][j] = 0;
                else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                maxSide = max(dp[i][j],maxSide);
            }
        }

        return maxSide*maxSide;
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
