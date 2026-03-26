#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private: 
    int minJumps(int ind, int jumps, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind>=n-1) return jumps;
        if(dp[ind][jumps]!=-1) return dp[ind][jumps];
        int mini = INT_MAX;
        for(int i=1; i<=nums[ind]; i++) {
            mini = min(mini,minJumps(ind+i,jumps+1,n,nums,dp));
        }

        return dp[ind][jumps] = mini;
    }
    public:
    int jump(vector<int>& nums) {
        int n = nums.size(), l=0, r=0, jumps=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return minJumps(0,0,n,nums,dp);
    }

    // TC -> O(N)
    // SC -> O(1)
};

// Optimal Solution
class Solution {
    public:
    int jump(vector<int>& nums) {
        int n = nums.size(), l=0, r=0, jumps=0;
        while(r<n-1) {
            int farthest = 0;
            for(int i=l; i<=r; i++) {
                farthest = max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }

    // TC -> O(N)
    // SC -> O(1)
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
