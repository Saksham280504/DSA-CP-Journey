#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void lcsPrint(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else {
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // Tabulation: 
    // TC -> O(N*M)
    // SC -> O(N*M) (dp-array)

    // Back-tracking -> O(N+M) for the worst case
    int length = dp[n][m];
    int ind = length -1;
    string s3 = "";
    for(int i=0; i<length; i++) s3 += '$';
    int i = n;
    int j = m;
    while(i>0 && j>0) {
        if(s1[i-1]==s2[j-1]) {
            s3[ind] = s1[i-1];
            ind--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--; // In case of not matching, if dp[i][j-1] == dp[i-1][j], then in that case multiple answers are possible and for that we need to go to brute-force approach
    }

    cout << s3 << endl;
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

    // Here we are asked to print the largest common subsequence of two strings!!
    // For this we use the tabulation approach as we will need the entire dp-table for back-tracking!!

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    lcsPrint(n,m,s1,s2,dp);
    return 0;
}
