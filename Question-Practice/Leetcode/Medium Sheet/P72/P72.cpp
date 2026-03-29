#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1); // dp[i] -> total number of BSTs with i nodes
        // dp[i] = SUM(dp[left]*dp[right]) -> left => j nodes, right => i-j-1 nodes (j+1 is the root for that BST)
        dp[0] = dp[1] = 1; // Base-Case
        for(int i=2; i<=n; i++) { // i-> total number of nodes in BST
            for(int j=0; j<i; j++) { // j -> total number of nodes in the Left SubTree
                dp[i] += dp[j]*dp[i-j-1]; // Catalan Number Formula
            }
        }

        return dp[n];

        // TC -> O(N^2)
        // SC -> O(N)
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
