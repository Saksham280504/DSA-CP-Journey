#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                int diff = nums[i] - nums[j];
                if(dp[j].count(diff)>0) {
                    dp[i][diff] = dp[j][diff] + 1;
                }
                else dp[i][diff] = 2; // At minimum the length of the subsequence will be 2
                ans = max(ans,dp[i][diff]);
            }
        }

        return ans;

        // TC -> O(N*N)
        // SC -> O(N*N) (worst case)

        // dp[i][diff] -> Length of the longest subsequence till the index i and with common difference diff.
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
