#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // dp[n][m] = 0 -> both strings are currently empty, hence nothing to delete
        // Here we form the string from back, this means that dp[i][j] have strings s1 from (n-1...i) and string s2 from (m-1....j) and then we have to find the minimum ASCII sum.
        for(int i=n-1; i>=0; i--) {
            dp[i][m] = s1[i] + dp[i+1][m];
        }

        for(int j=m-1; j>=0; j--) {
            dp[n][j] = s2[j] + dp[n][j+1];
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s1[i]==s2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = min(s1[i] + dp[i+1][j], s2[j] + dp[i][j+1]);
            }
        }

        return dp[0][0];
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

    return 0;
}
