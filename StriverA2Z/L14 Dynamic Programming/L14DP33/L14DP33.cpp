#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int minOp(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
    if(ind1==0) return ind2;
    if(ind2==0) return ind1;

    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s1[ind1-1]==s2[ind2-1]) return dp[ind1][ind2] = 0 + minOp(ind1-1,ind2-1,s1,s2,dp);

    int insert = 1 + minOp(ind1,ind2-1,s1,s2,dp);
    int del = 1 + minOp(ind1-1,ind2,s1,s2,dp);
    int rep = 1 + minOp(ind1-1,ind2-1,s1,s2,dp);

    return dp[ind1][ind2] = min({insert, del, rep});

    // Recursive Approach:
    // TC -> Exponential O(3^N)
    // SC -> O(N+M)

    // Memoization Approach:
    // TC -> O(N*M)
    // SC - O(N*M) + O(N+M) (auxillary stack-space)
}

int minOpTab(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    for(int j=0; j<=m; j++) dp[0][j] = j;
    for(int i=0; i<=m; i++) dp[i][0] = i;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
            else {
                int insert = 1 + dp[i][j-1];
                int del = 1 + dp[i-1][j];
                int rep = 1 + dp[i-1][j-1];
                dp[i][j] = min({insert, del, rep});
            }
        }
    }

    return dp[n][m];

    // TC -> O(N*M)
    // SC -> O(N*M)
}

int minOpSO(int n, int m, string s1, string s2) {
    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);
    for(int j=0; j<=m; j++) prev[j] = j;
    curr[0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
           if(s1[i-1]==s2[j-1]) curr[j] = 0 + prev[j-1];
           else {
            int insert = 1 + curr[j-1];
            int del = 1 + prev[j];
            int rep = 1 + prev[j-1];
            curr[j] = min({insert, del, rep});
           } 
        }
        prev = curr;
        curr[0] = i+1;
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
    
    // You are given a string s1 and a string s2, and we have to convert string s1 to s2 by three types of operations on s1:-
    // 1. Insert
    // 2. Delete
    // 3. Swap

    // The process that takes the maximum number of steps is to delete all the elements of s1 and then insert all the elements of s2. (N+M)

    // To do this in minimum number of steps, we look for all the possibilities and return the minimum of them as answer.

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n+1,vector<int>(m+1,-1));
    int Op1 = minOp(n,m,s1,s2,dp1);
    cout << Op1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1, vector<int>(m+1,0));
    int Op2 = minOpTab(n,m,s1,s2,dp2);
    cout << Op2 << endl;

    // Space-Optimization(Single Array) Approach:
    int Op3 = minOpSO(n,m,s1,s2);
    cout << Op3 << endl;
    return 0;
}
