#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int maxProfit(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>& dp) {
    if(ind>=n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy) return dp[ind][buy] = max(-prices[ind] + maxProfit(ind+1,0,n,prices,dp), 0 + maxProfit(ind+1,1,n,prices,dp));
    return dp[ind][buy] = max(prices[ind] + maxProfit(ind+2,1,n,prices,dp), 0 + maxProfit(ind+1,0,n,prices,dp));
}

int maxProfitTab(int n, vector<int>& prices, vector<vector<int>>& dp) {
    // Base-Cases already handled in declaration of DP

    for(int i=n-1; i>=0; i--) {
        dp[i][1] = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);
        dp[i][0] = max(prices[i] + dp[i+2][1], 0 + dp[i+1][0]);
    }

    return dp[0][1];
}

int maxProfitSO(int n, vector<int>& prices) {

    vector<int> front2(2,0);
    vector<int> front1(2,0);
    vector<int> curr(2,0);

    for(int i=n-1; i>=0; i--) {
        curr[1] = max(-prices[i] + front1[0], 0 + front1[1]);
        curr[0] = max(prices[i] + front2[1], 0 + front1[0]);
        front2 = front1;
        front1 = curr;
    }

    return front1[1];
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

    // In this question, we have a cooldown and that means that I can't buy a stock, just after the day I have sold one

    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i=0; i<n; i++) cin >> prices[i];

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n,vector<int>(2,-1));
    int profit1 = maxProfit(0,1,n,prices,dp1);
    cout << profit1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+2,vector<int>(2,0));
    int profit2 = maxProfitTab(n,prices,dp2);
    cout << profit2 << endl;

    // Recursion Approach:
    int profit3 = maxProfitSO(n,prices);
    cout << profit3 << endl;

    return 0;
}
