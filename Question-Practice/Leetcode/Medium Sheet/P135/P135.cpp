#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
int maxPoints(int ind, vector<int>& points, vector<int>& dp) {
    if(ind<0) return 0;
    if(ind==0) return points[0];
    if(dp[ind]!=-1) return dp[ind];
    int take = points[ind] + maxPoints(ind-2,points,dp);
    int notTake = 0 + maxPoints(ind-1,points,dp);
    return dp[ind] = max(take,notTake);
}

// The core intuition of the problem is that you have to group same elements together as the penalty of losing nums[i]-1 and nums[i]+1 only occurs for the first occurance of nums[i]. After that all of the occurances of nums[i] have no penalties. 
// Therefore, we first need to group the points of unique elements together.
// Then we need to choose elements such that no two adjacent elements are chosen together. This converts the problem into House Robber problem pattern (maximum non-adjacent sum).
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> points(mx+1,0);

        for(int x: nums) {
            points[x] += x;
        }

        // Either you can use recursion
        vector<int> dp(mx+1,-1);
        return maxPoints(mx,points,dp);

        // Or Tabulation (Better)
        vector<int> dpTab(mx+1,0);
        dpTab[0] = points[0];
        for(int i=1; i<n; i++) {
            int take = points[i];
            if(i>1) take += dpTab[i-2];
            int notTake = 0 + dpTab[i-1];
            dpTab[i] = max(take,notTake);
        }

        return dpTab[mx];

        // Or you can use Space-Optimization (Best)
        int back2 = 0; // dp[i-2]
        int back1 = points[0]; // dp[i-1]
        for(int i=0; i<=mx; i++) {
            int take = points[i] + back2;
            int notTake = 0 + back1;
            back2 = back1;
            back1 = max(take,notTake);
        }

        return back1;
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
