#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int lcs(int ind1, int ind2, string s1, string s2,vector<vector<int>>& dp) {
    if(ind1==0 || ind2==0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1-1]==s2[ind2-1]) return 1 + lcs(ind1-1,ind2-1,s1,s2,dp);
    return (0 + max(lcs(ind1-1,ind2,s1,s2,dp),lcs(ind1,ind2-1,s1,s2,dp)));
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
}

int lcsSO(int n, int m, string s1, string s2) {
    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);

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

    // I have to return the length of the largest Palindromic Subsequence of a string, then we can say that the longest Palindromic subsequence is nothing but the longest common subsequence of that string with its reverse.

    string s1;
    cin >> s1;
    string s2;
    int n = s1.size();
    for(int i=n-1; i>=0; i--) {
        s2 += s1[i];
    }

    // Recursive/ Memoization Approach:
    vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));
    int length1 = lcs(n,n,s1,s2,dp1);
    cout << length1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1, vector<int>(n+1,0));
    int length2 = lcsTab(n,n,s1,s2,dp2);
    cout << length2 << endl;

    // Space-Optimization Approach:
    int length3 = lcsSO(n,n,s1,s2);
    cout << length3 << endl;

    return 0;
}
