#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int lcsubstringTab(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans= max(ans, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }

    return ans;

    // TC -> O(N*M)
    // SC -> O(N*M)
}

int lcsubStringSO(int n, int m, string s1, string s2) {
    vector<int> prev(m+1,0), curr(m+1,0);
    
    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) {
                curr[j] = 1 + prev[j-1];
                ans = max(ans, curr[j]);
            }
            else curr[j] = 0;
        }
        prev = curr;
    }

    return ans;

    // TC -> O(N*M)
    // SC -> O(2M)
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
    // Here we need to find the length of largest common substring (subsequence which only have contiguous elements)!!
    // Here we use the same approach but with slight modifications and i.e. if two elements don't match we only take a zero and nothing else from before so that means that max(dp[i-1][j], dp[i][j-1]) is of no use here.
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();  

    // Tabulation Approach:
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int length1 = lcsubstringTab(n,m,s1,s2,dp);
    cout << length1 << endl;

    int length2 = lcsubStringSO(n,m,s1,s2);
    cout << length2 << endl;

    return 0;
}
