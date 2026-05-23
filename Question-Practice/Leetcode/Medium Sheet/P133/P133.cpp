#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int lcs(int i, int j, vector<vector<int>>& dp, string text1, string text2) {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j] = 1 + lcs(i-1,j-1,dp,text1,text2);
        return dp[i][j] = 0 + max(lcs(i-1,j,dp,text1,text2),lcs(i,j-1,dp,text1,text2));
    }

    int lcsTab(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }

    int lcsSO(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m+1,0);

        for(int i=1; i<=n; i++) {
            vector<int> curr(m+1,0);
            for(int j=1; j<=m; j++) {
                if(text1[i-1]==text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Recursive/Memoization approach-> TLE
        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return lcs(n-1,m-1,dp,text1,text2);

        // Tabulation Approach:
        return lcsTab(text1, text2);

        // Space Optimization Approach:
        return lcsSO(text1, text2);
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
