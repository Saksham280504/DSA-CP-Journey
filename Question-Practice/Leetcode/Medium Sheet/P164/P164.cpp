#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int n;
    vector<vector<int>> dp;
    int maxProfitMemo(int day, int buy, vector<int>& prices) {
        if(day>=n) return 0;
        if(dp[day][buy]!=-1) return dp[day][buy];
        if(buy) return dp[day][buy] = max(-prices[day]+maxProfitMemo(day+1,0,prices), 0+maxProfitMemo(day+1,1,prices));
        return dp[day][buy] = max(prices[day]+maxProfitMemo(day+2,1,prices), 0+maxProfitMemo(day+1,0,prices));
    }
    int maxProfitTab(vector<int>& prices) {
        for(int day=n-1; day>=0; day--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) dp[day][buy] = max(-prices[day]+dp[day+1][0], 0+dp[day+1][1]);
                else dp[day][buy] = max(prices[day]+dp[day+2][1], 0+dp[day+1][0]);
            }
        }
        return dp[0][1];
    }
    int maxProfitSO(vector<int>& prices) {
        vector<int> forw2(2,0), forw1(2,0); // n+1th and nth day
        for(int day=n-1; day>=0; day--) {
            vector<int> curr(2,0);
            for(int buy=0; buy<=1; buy++) {
                if(buy) curr[buy] = max(-prices[day]+forw1[0], 0+forw1[1]);
                else curr[buy] = max(prices[day]+forw2[1], 0+forw1[0]);
            }
            forw2 = forw1;
            forw1 = curr;
        }
        return forw1[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n+2,vector<int>(2,0));
        int maxi = maxProfitSO(prices);
        return maxi;
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
