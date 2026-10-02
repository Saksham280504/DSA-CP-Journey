#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int numOfSub(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(idx==0) {
            if(target==0 && nums[idx]==0) return 2;
            if(target==0 || nums[idx]==target) return 1;
            return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notTake = numOfSub(idx-1,target,nums,dp);
        int take = 0;
        if(nums[idx]<=target) take = numOfSub(idx-1,target-nums[idx],nums,dp);
        return dp[idx][target] = notTake + take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // P -> Subset of +ve elements, N -> subset of -ve elements
        // SUM(P) - SUM(N) = target
        // SUM(P) + SUM(N) = total
        int total = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>total || (total+target)&1) return 0;
        int sumP = (total+target)/2;
        // Now we just need to find the number of subsequences with sum of elements = sumP
        int n = nums.size();

        // Approach - 1 : Recursion/Memoization
        // vector<vector<int>> dp(n,vector<int>(sumP+1,-1));
        // return numOfSub(n-1,sumP,nums,dp);

        // Approach - 2: Tabulation
        // vector<vector<int>> dp(n,vector<int>(sumP+1,0));
        // if(nums[0]<=sumP) dp[0][nums[0]] = 1;
        // dp[0][0] = nums[0]==0 ? 2: 1;
        // for(int i=1; i<n; i++) {
        //     for(int target=0; target<=sumP; target++) {
        //         int notTake = dp[i-1][target];
        //         int take = 0;
        //         if(nums[i]<=target) take = dp[i-1][target-nums[i]];
        //         dp[i][target] = notTake + take;
        //     }
        // }
        // return dp[n-1][sumP];

        // Approach - 3: Space Optimization (SC -> O(2*N))
        // vector<int> prev(sumP+1,0);
        // if(nums[0]<=sumP) prev[nums[0]] = 1;
        // prev[0] = nums[0]==0 ? 2:1;
        // for(int i=1; i<n; i++) {
        //     vector<int> curr(sumP+1,0);
        //     for(int target=0; target<=sumP; target++) {
        //         int notTake = prev[target];
        //         int take = 0;
        //         if(nums[i]<=target) take = prev[target-nums[i]];
        //         curr[target] = notTake+take;
        //     }
        //     prev = curr;
        // }
        // return prev[sumP];

        // Approach - 4: Space Optimization (SC -> O(N))
        vector<int> dp(sumP+1,0);
        if(nums[0]<=sumP) dp[nums[0]] = 1;
        dp[0] = nums[0]==0 ? 2:1;
        for(int i=1; i<n; i++) {
            for(int target=sumP; target>=nums[i]; target--) {
                int notTake = dp[target];
                int take = dp[target-nums[i]];
                dp[target] = notTake + take;
            }
        }
        return dp[sumP];
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
