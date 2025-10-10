#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int minOperations(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
    if(ind1==0 || ind2==0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1-1]==s2[ind2-1]) return dp[ind1][ind2] = 1 + minOperations(ind1-1,ind2-1,s1,s2,dp);
    return dp[ind1][ind2] = 0 + max(minOperations(ind1-1, ind2, s1, s2,dp), minOperations(ind1, ind2-1, s1, s2,dp));
}

int minOperationsTab(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=m; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int minOperationsSO(int n, int m, string s1, string s2) {
    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = 0 + max(curr[j-1],prev[j]);
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

    // In this question, we were asked to find the minimum number of operations needed to convert a string s1 to s2.
    // For this, maximum number of operations = n+m i.e. delete the entire s1 and paste s2.
    // For minimum operations we need to delete only those elements which are not in the lcs of s1 and s2 and we will delete those elements from s1 and paste the other elemets of s2.
    // This will give the minimum operations = n+m-2*lcs.
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n+1,vector<int>(m+1,-1));
    int mini1 = n+m-2*minOperations(n,m,s1,s2,dp1);
    cout << mini1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1, vector<int>(m+1,0));
    int mini2 = n+m-2*minOperationsTab(n,m,s1,s2,dp2);
    cout << mini2 << endl;

    // Space-Optimization Approach:
    int mini3 = n+m-2*minOperationsSO(n,m,s1,s2);
    cout << mini3 << endl;
    return 0;
}
