#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    // This is a same pattern problem as the longest common substring
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        // dp[i][j] -> maximumm length of the subarray ending at nums1[i-1] and nums2[j-1]

        int ans = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(nums1[i-1]==nums2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                    ans = max(ans,curr[j]);
                }
                else curr[j] = 0;
            }
            prev = curr;
        }

        return ans;
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
