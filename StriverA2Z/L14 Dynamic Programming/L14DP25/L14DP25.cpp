#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int lcs(int len1, int len2, string s1, string s2, vector<vector<int>> dp) {
    if(len1==0 || len2==0) return 0;
    if(dp[len1][len2]!=-1) return dp[len1][len2];
    if(s1[len1-1]==s2[len2-1]) return dp[len1][len2] = 1 + lcs(len1-1,len2-1,s1,s2,dp);
    return dp[len1][len2] = (0 + max(lcs(len1-1,len2,s1,s2,dp),lcs(len1, len2-1,s1,s2,dp)));

    // For recursive approach:
    // TC -> O(2^N*2^M) Exponential (Too high, need to optimize)

    // Memoization approach:
    // TC -> O(N*M)
    // SC -> O(N*M) (DP Array) + O(N+M) (Auxillary Stack-space)
}

int lcsTab(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];

    // TC -> O(N*M)
    // SC -> O(N*M)
}

int lcsSO(int n, int m, string s1, string s2) {
    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);

    for(int j=0; j<=m; j++) prev[j] = 0;
    curr[0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = 0 + max(prev[j],curr[j-1]);
        }
        prev = curr;
    }

    return prev[m];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // From here we start DP on Strings which basically involves two types of problems:
    // 1. Comparison
    // 2. Replaces/edit

    // Subsequence of a string refers to a collection of characters of that string such that they need not to be continuous but still need to follow the same order as they were present on the initial string.

    // To find the largest common subsequence of 2 strings, if we follow the brute-force approach where we generate all the possible subsequences of both the strings and then compare all of them to find the answer will give exponential time Complexity and space Complexity thus we will not follow that approach.

    // What we will follow is generate all and compare on the way.
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    // Recursive/Memoization Approach: 
    vector<vector<int>> dp1(n+1,vector<int>(m+1,-1));
    int lcs1 = lcs(n,m,s1,s2, dp1);
    cout << lcs1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1,vector<int>(m+1,0));
    int lcs2 = lcsTab(n,m,s1,s2,dp1);
    cout << lcs2 << endl;

    // Space-Optimization Approach:
    int lcs3  = lcsSO(n,m,s1,s2);
    cout << lcs3 << endl;
    return 0;
}
