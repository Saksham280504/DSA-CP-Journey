#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        // Base-cases:- 
        // For all i>=j, dp[i][j] = 0 (when only one or none coin is present, total cost required to pay is zero) (Handled in dp declaration)
        // For all j==i+1 (i.e. only 2 elements are present), minimum maximum cost to pay = i (min of both elements) (will be handled in tabulation loop)
        for(int len=2; len<=n; len++) {
            for(int i=1; i<=(n-len+1); i++) {
                int j = i+len-1;
                dp[i][j] = INT_MAX;
                for(int x=i; x<=j; x++) {
                    int cost = x+max(dp[i][x-1],dp[x+1][j]);
                    dp[i][j] = min(dp[i][j],cost);
                }
            }
        }
        return dp[1][n];
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
