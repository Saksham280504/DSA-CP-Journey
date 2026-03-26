#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();

        // Step - 1: Waste Matrix
        vector<vector<int>> waste(n,vector<int>(n,0));
        for(int i=0; i<n; i++) {
            int maxi = 0;
            int sum = 0;
            for(int j=i; j<n; j++) {
                maxi = max(maxi, nums[j]);
                sum += nums[j];
                waste[i][j] = (j-i+1)*maxi - sum;
            }
        }

        // Step - 2: DP
        vector<vector<int>> dp(n+1,vector<int>(k+2,1e9));
        dp[0][0] = 0;
        for(int i=1; i<=n; i++) { // i -> number of elements from start
            for(int j=1; j<=k+1; j++) { // number of segment allowed
                for(int h=0; h<i; h++) { // Starting element of the last segment
                    dp[i][j] = min(dp[i][j], dp[h][j-1] + waste[h][i-1]);
                }
            }
        }

        return dp[n][k+1];

        // TC -> O(n^2*k)
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
