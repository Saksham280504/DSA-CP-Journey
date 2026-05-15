#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
int buySellProfitWithFee(int ind, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
    int n = prices.size();
    if(ind==n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy) return dp[ind][buy] = max(-prices[ind] + buySellProfitWithFee(ind+1,0,fee,prices,dp), 0 + buySellProfitWithFee(ind+1,1,fee,prices,dp));
    return dp[ind][buy] = max(prices[ind] - fee + buySellProfitWithFee(ind+1,1,fee,prices,dp), 0 + buySellProfitWithFee(ind+1,0,fee,prices,dp));
}

int buySellTab(int fee, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=n-1; i>=0; i--) {
        dp[i][1] = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);
        dp[i][0] = max(prices[i]- fee + dp[i+1][1], 0 + dp[i+1][0]);
    }
    return dp[0][1];
}

int buySellSO(int fee, vector<int>& prices) {
    int n = prices.size();
    vector<int> front(2,0);
    for(int i=n-1; i>=0; i--) {
        vector<int> curr(2,0);
        curr[1] = max(-prices[i] + front[0], 0 + front[1]);
        curr[0] = max(prices[i]-fee + front[1], 0 + front[0]);
        front = curr;
    }

    return front[1];
}
public:
    // Recursion/Memoization Approach
    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // vector<vector<int>> dp1(n,vector<int>(2,-1)); // dp[ith day][buy state] -> buy state = 1 (I can buy), buy state = 0 (I can't buy)
        // return buySellProfitWithFee(0,1,fee,prices,dp1);

        return buySellSO(fee, prices);
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
