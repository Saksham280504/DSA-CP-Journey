#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int maxProfit(int ind, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>>& dp) {
    if(ind==n || cap==0) return 0;
    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    if(buy) return  dp[ind][buy][cap] = max(-prices[ind] + maxProfit(ind+1,0,cap,n,prices,dp), 0 + maxProfit(ind+1,1,cap,n,prices,dp));
    return dp[ind][buy][cap] = max(prices[ind] + maxProfit(ind+1,1,cap-1,n,prices,dp), 0 + maxProfit(ind+1,0,cap,n,prices,dp));

    // TC -> Exponential
    // SC -> O(N) (auxillary stack-space)

    // Memoization Approach:
    // TC -> O(N*2*3)
    // SC -> O(N*2*3) + O(N)
}

int maxProfitTab(int n, vector<int>& prices, vector<vector<vector<int>>>& dp) {

    // We have handled the base-cases in declaration of dp only

    for(int i=n-1; i>=0; i--) {
        for(int buy=0; buy<=1; buy++) {
            for(int cap=1; cap<=2; cap++) {
                if(buy) dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], 0 + dp[i+1][1][cap]);
                else dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], 0 + dp[i+1][0][cap]);
            }
        }
    }

    return dp[0][1][2];

    // TC -> O(N*2*3)
    // SC -> O(N*2*3)
}

int maxProfitSO(int n, vector<int>& prices) {
    vector<vector<int>> after(2,vector<int>(3,0));
    vector<vector<int>> curr(2,vector<int>(3,0));

    for(int i=n-1; i>=0; i--) {
        for(int buy=0; buy<=1; buy++) {
            for(int cap=1; cap<=2; cap++) {
                if(buy) curr[buy][cap] = max(-prices[i] + after[0][cap], 0 + after[1][cap]);
                else curr[buy][cap] = max(prices[i] + after[1][cap-1], 0 + after[0][cap]);
            }
        }
        after = curr;
    }

    return after[1][2];

    // TC -> O(N*2*3)
    // SC -> O(2*3) -> O(1)
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

    // In this question, we have a cap on the number of times we can perform a transaction pair (Buy & Sell) to generate a maximum profit. The cap on number of transactions = 2 i.e. at most 2 transactions can be done.

    int n;
    cin >> n;
    vector<int> prices(n);

    for(int i=0; i<n; i++) cin >> prices[i];

    // Recursive/Memoization Approach:
    vector<vector<vector<int>>> dp1(n+1,vector<vector<int>>(2, vector<int>(3,-1)));
    int profit1 = maxProfit(0,1,2,n,prices,dp1);
    cout << profit1 << endl;

    // Tabulation Approach:
    vector<vector<vector<int>>> dp2(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    int profit2 = maxProfitTab(n,prices,dp2);
    cout << profit2 << endl;

    // Space-Optimization Approach:
    int profit3 = maxProfitSO(n,prices);
    cout << profit3 << endl;
    return 0;
}
