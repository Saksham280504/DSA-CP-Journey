#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int numberOfSets(int n, int k) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        // dp[i][j] -> Number of ways to form j segments till i
        // 2 possibilities -> either don't end the segment at i or end the segment at i
        // If not ending at i -> dp[i][j] += dp[i-1][j]
        // If ending at i, then you need to check for all p<i (dp[p][j-1]) and sum up all these values like a prefix

        // For 0 segments
        for(int i=0; i<n; i++) dp[i][0] = 1;

        for(int j=1; j<=k; j++) {
            int prefix = 0;
            for(int i=1; i<n; i++) {
                prefix = (prefix + dp[i-1][j-1])%mod;
                dp[i][j] = (dp[i-1][j] + prefix)%mod;
            }
        }
        return dp[n-1][k];
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
