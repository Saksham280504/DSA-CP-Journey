#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int MinInsertions(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
    if(ind1==0 || ind2 == 0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1-1]==s2[ind2-1]) return dp[ind1][ind2] = 1 + MinInsertions(ind1-1, ind2-1, s1, s2,dp);
    return dp[ind1][ind2] = 0 + max(MinInsertions(ind1-1,ind2,s1,s2,dp), MinInsertions(ind1, ind2-1, s1, s2,dp));
}

int MinOperationsTab(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=m; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int MinOperationSO(int n, int m, string s1, string s2) {
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

    // We are asked to find out the minimum number of insertions to be made in order to make a string a palindromic string.
    // Maximum number of operations = length of string (Here, we just paste the reverse of the string at the end of the string and it becomes a palindrome).
    // But in order to find the minimum number of operations, we just find the longest palindromic subsequence and make it constant, except it all of the remaining characters are non-palindromic so we would have to paste them at their mirror positions in order to generate a palindromic string.
    // Here the number of operations become -> length of string - length of longest common subsequence

    string s1;
    cin >> s1;
    int n = s1.size();
    string s2;
    for(int i=n-1; i>=0; i--) s2 += s1[i];

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));
    int minOperations = n-MinInsertions(n,n,s1,s2,dp1);
    cout << minOperations << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1,vector<int>(n+1,0));
    int minOperations2 = n-MinOperationsTab(n,n,s1,s2,dp2);
    cout << minOperations2 << endl;

    // Space-Optimization Approach:
    int minOperations3 = n-MinOperationSO(n,n,s1,s2);
    cout << minOperations3 << endl;

    return 0;
}
