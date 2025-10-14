#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int maxProfit(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>& dp) {
    if(ind==n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    int profit = 0;
    if(buy) profit = max(-prices[ind] + maxProfit(ind+1,0,n,prices,dp), 0 + maxProfit(ind+1,1,n,prices,dp));
    else profit = max(prices[ind] + maxProfit(ind+1,1,n,prices,dp), 0 + maxProfit(ind+1,0,n,prices,dp));
    return dp[ind][buy] = profit;

    // Recursive Approach:
    // TC -> O(2^n)
    // SC -> O(N) (auxillary stack space)

    // Memoization Approach:
    // TC -> O(N*2)
    // SC -> O(N*2) + O(N)
}

int maxProfitTab(int n, vector<int>& prices, vector<vector<int>>& dp) {
    dp[n][0] = dp[n][1] = 0;

    for(int i=n-1; i>=0; i--) {
        for(int buy = 0; buy<=1; buy++) {
            if(buy) dp[i][buy] = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);
            else dp[i][buy] = max(prices[i] + dp[i+1][1], 0 + dp[i+1][0]);
        }
    }

    return dp[0][1];

    // TC -> O(N*2)
    // SC ->O(N*2)
}

int maxProfitSO(int n, vector<int>& prices) {
    vector<int> ahead(2,0), curr(2,0);

    for(int i=n-1; i>=0; i--) {
        for(int buy=0; buy<=1; buy++) {
            if(buy) curr[buy] = max(-prices[i] + ahead[0], 0 + ahead[1]);
            else curr[buy] = max(prices[i] + ahead[1], 0 + ahead[0]);
        }
        ahead = curr;
    }
    return ahead[1];

    // TC -> O(2*N)
    // SC -> O(4) -> O(1)
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    // Here we have the liberty to perform the buy and sell operations multiple times but we just need to make sure that we perform the buy function only when we have no stock to sell and we perform the sell function only when we have a stock to sell.

    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0; i<n; i++) cin >> prices[i];

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n,vector<int>(2,-1));
    int maxProfit1 = maxProfit(0,1,n,prices,dp1);
    cout << maxProfit1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1,vector<int>(2,0));
    int maxProfit2 = maxProfitTab(n,prices,dp2);
    cout << maxProfit2 << endl;

    // Space-Optimization Approach:
    int maxProfit3 = maxProfitSO(n,prices);
    cout << maxProfit3 << endl;
    return 0;
}
