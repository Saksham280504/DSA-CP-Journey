#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int sum=1; sum<=target; sum++) {
            for(int x: nums) {
                if(sum>=x && (dp[sum]<=(INT_MAX-dp[sum-x]))) dp[sum] += dp[sum-x];
            }
        }
        return dp[target];
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
