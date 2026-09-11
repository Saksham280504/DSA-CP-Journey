#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {

public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0,INT_MIN,INT_MIN}; // without taking any elements, we can only generate 0 sum, so dp[0] = 0%3 = 0, and 1 and 2 sum are not possible, thus dp[1] = dp[2] = INT_MIN
        // dp[rem] -> maximum sum possible with sum%3 = rem
        for(int x: nums) {
            vector<int> next_dp = dp;
            for(int rem=0; rem<3; rem++) {
                if(dp[rem]!=INT_MIN) {
                    int next_sum = dp[rem]+x;
                    int next_rem = (rem+x)%3;
                    next_dp[next_rem] = max(dp[next_rem],next_sum);
                }
            }
            dp = move(next_dp);
        }
        return dp[0];
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
