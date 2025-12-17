#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Recursive/Memoization solution
class Solution {
    private:
    int minJumps(int ind, int jumps, int n, vector<int>& nums, vector<vector<int>>& dp) { 
        if(ind>=n-1) return jumps; // It might be possible that through some path I reach way beyond n-1, therefore the edge case is (ind>=n-1) and not(ind==n)
        if(dp[ind][jumps]!=-1) return dp[ind][jumps];
        int mini = INT_MAX;
        for(int i=1; i<=nums[ind]; i++) {
            mini = min(mini,minJumps(ind+i,jumps+1,n,nums,dp));
        } 
        return dp[ind][jumps] = mini;
    }
    public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return minJumps(0,0,n,nums,dp);
    }

    // Recursive Solution
    // TC -> O(N^N) (not favourable) (TLE)
    // SC -> O(N)

    // Memoization Solution
    // TC -> O(N^2) (not favourable) (TLE)
    // SC -> O(N^2)
};

// Optimal Solution (TC->O(N))

class Solution {
    public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps=0,l=0,r=0; // We jump in ranges not in terms of indices (l->lowest range value (smallest distance covered), r-> largest range value(largest distance covered))

        while(r<n-1) {
            int farthest = 0;
            for(int ind=l; ind<=r; ind++) {
                farthest = max(farthest,ind+nums[ind]); // We try to look for the farthest we can reach from all the indices from l to r
            }
            l = r+1; // We greedily try to put l at just one place ahead of r so that we can try out every index
            r = farthest; // We greadily try to put r at the farthest distance achievable from that range to reach the ind=n-1 as soon as possible.
            jumps++; // Every new range shows the range of indices we can reach from our previous range.
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
