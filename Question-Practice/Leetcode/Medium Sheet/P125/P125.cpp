#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    int maxSum(int ind, vector<int>& dp, vector<int>& arr) {
        if(ind==0) return arr[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take = arr[ind] + maxSum(ind-2,dp,arr);
        int notTake = 0 + maxSum(ind-1,dp,arr);
        return dp[ind] = max(take,notTake);
    }
    
    int maxSumTab(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,-1);
        dp[0] = arr[0];
        for(int i=1; i<n; i++) {
            int take = arr[i];
            if(i>1) take += dp[i-2];
            int notTake = 0 + dp[i-1];
            dp[i] = max(take,notTake);
        }

        return dp[n-1];
    }

    int maxSumSO(vector<int>& arr) {
        int n = arr.size();
        int prev1 = 0;
        int prev = arr[0];
        for(int i=1; i<n; i++) {
            int take = arr[i] + prev1;
            int notTake = 0 + prev;
            prev1 = prev;
            prev = max(take,notTake);
        }

        return prev;
    }
    public:
    int rob(vector<int>& nums) {
        // Recursion/Memoization Approach:
        // int n = nums.size();
        // if(n==1) return nums[0];
        // vector<int> temp1, temp2;
        // temp1.push_back(nums[0]);
        // for(int i=1; i<n-1; i++) {
        //     temp1.push_back(nums[i]);
        //     temp2.push_back(nums[i]);
        // }
        // temp2.push_back(nums[n-1]);
        // vector<int> dp1(n-1,-1);
        // vector<int> dp2(n-1,-1);
        // int sum1 = maxSum(n-2,dp1,temp1);
        // int sum2 = maxSum(n-2,dp2,temp2);
        // return max(sum1,sum2);

        // Tabulation Approach
        // int n = nums.size();
        // if(n==1) return nums[0];
        // vector<int> temp1, temp2;
        // temp1.push_back(nums[0]);
        // for(int i=1; i<n-1; i++) {
        //     temp1.push_back(nums[i]);
        //     temp2.push_back(nums[i]);
        // }
        // temp2.push_back(nums[n-1]);

        // int maxSum1 = maxSumTab(temp1);
        // int maxSum2 = maxSumTab(temp2);
        // return max(maxSum1, maxSum2);

        // Space-Optimization Approach:
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1, temp2;
        temp1.push_back(nums[0]);
        for(int i=1; i<n-1; i++) {
            temp1.push_back(nums[i]);
            temp2.push_back(nums[i]);
        }
        temp2.push_back(nums[n-1]);

        int maxSum1 = maxSumSO(temp1);
        int maxSum2 = maxSumSO(temp2);

        return max(maxSum1,maxSum2);
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
