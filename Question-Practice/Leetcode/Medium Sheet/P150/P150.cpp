#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum(n+1,0);
        for(int i=0; i<n; i++) {
            prefixSum[i+1] = prefixSum[i] + stones[i];
        }

        vector<int> dp(n,0);
        // dp[i] -> maximum score difference for the current length (len) subarray starting at index i
        
        for(int len=2; len<=n; len++) {
            for(int i=0; i<=(n-len); i++) {
                int j = i+len-1;
                int removeI = prefixSum[j+1]-prefixSum[i+1] - dp[i+1];
                int removeJ = prefixSum[j]-prefixSum[i]-dp[i];
                dp[i] = max(removeI, removeJ);
            }
        }

        return dp[0];
    }

    // The key idea of the problem is to understand the DP state.
    // Given an sub-array stones[i....j] (len)
    // removeI -> maximum score differnce = sum(i+1...j) - dp[i+1][j] (len-1)
    // removeJ -> maximum score difference = sum(i...j-1) - dp[i][j-1] (len-1)

    // The key optimization from a 2D DP table to 1D DP array is that the single DP array at the start of len actually contains the values for the previous loop (len-1).
    // Therefore when we use dp[i] -> we mean to say dp[i][j-1] (len-1)
    // and similarly when we use dp[i+1] -> we mean to say dp[i+1][j]
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
