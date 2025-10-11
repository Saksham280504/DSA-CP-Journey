#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int DistinctSub(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
    if(ind2==0) return 1;
    if(ind1==0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1-1]==s2[ind2-1]) return dp[ind1][ind2] = (DistinctSub(ind1-1,ind2-1,s1,s2,dp) + DistinctSub(ind1-1,ind2,s1,s2,dp));
    else return dp[ind1][ind2] =DistinctSub(ind1-1,ind2,s1,s2,dp);

    // For recursive approach:
    // TC -> exponential -> O(2^n*2*m)
    // SC -> O(N+M) (auxillary stack-space)

    // For Memoization Approach:
    // TC -> O(N*M)
    // SC -> O(N*M) + O(N+M)
}

int DistinctSubTab(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    for(int i=0;i<=n; i++) dp[i][0] = 1;
    for(int j=0;j<=m; j++) dp[0][j] = 0;
    dp[0][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][m];

    // TC -> O(N*M)
    // SC -> O(N*M) + O(N+M)
}

int DistinctSubSO(int n, int m, string s1, string s2) {
    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);
    prev[0] = 1;
    curr[0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) curr[j] = prev[j-1] + prev[j];
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    return prev[m];
}

int DistinctSubSO2(int n, int m, string s1, string s2) {
    vector<int> prev(m+1,0);
    prev[0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=m; j>=1; j--) {
            if(s1[i-1]==s2[j-1])prev[j] = prev[j] + prev[j-1];
        }
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

    // We are given a string s1 and string s2, and we have to check how many times does string s2 appears in s1!!

    // For this we need to check all the possibilities and then return the sum of all the possibilities.

    // Thus the procedure of recursion will be as follows:-

    // 1. Express everything in terms of index
    // 2. Explore all possibilities
    // 3. Return the summation of all the possibilities
    // 4. Base Cases

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    // Recursive/ Memoization Approach:
    vector<vector<int>> dp1(n+1,vector<int>(m+1,-1));
    int num1 = DistinctSub(n,m,s1,s2,dp1);
    cout << num1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1,vector<int>(m+1,0));
    int num2 = DistinctSubTab(n,m,s1,s2,dp2);
    cout << num2 << endl;

    // Space-Optimization (Double Array) Approach:
    int num3 = DistinctSubSO(n,m,s1,s2);
    cout << num3 << endl;

    // Space-Optimization (Single Array) Approach:
    int num4 = DistinctSubSO2(n,m,s1,s2);
    cout << num4 << endl;
    return 0;
}
