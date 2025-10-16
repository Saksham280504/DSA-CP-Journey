#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int maxProfit(int ind, int transaction, int n, int k, vector<int>& prices,vector<vector<int>>& dp) {
    if(ind==n || transaction==(2*k)) return 0;
    if(dp[ind][transaction]!=-1) return dp[ind][transaction];
    if(transaction%2==0) return dp[ind][transaction] =  max(-prices[ind] + maxProfit(ind+1,transaction+1,n,k,prices,dp), 0 + maxProfit(ind+1,transaction,n,k,prices,dp));
    return dp[ind][transaction] = max(prices[ind] + maxProfit(ind+1,transaction+1,n,k,prices,dp), 0 + maxProfit(ind+1,transaction,n,k,prices,dp));

    // Recursive Approach:
    // TC -> Exponential
    // SC -> O(N) (Auxillary stack-space)
    
    // Memoization Approach:
    // TC -> O(N*4)
    // SC -> O(N*4)
}

int maxProfitTab(int n, int k, vector<int>& prices, vector<vector<int>>& dp) {
    // Base-Cases handled in the declaration of dp

    for(int i=n-1; i>=0; i--) {
        for(int transaction=2*k-1; transaction>=0; transaction--) {
            if(transaction%2==0) dp[i][transaction] =  max(-prices[i] + dp[i+1][transaction+1], 0 + dp[i+1][transaction]);
            else dp[i][transaction] = max(prices[i] + dp[i+1][transaction+1], 0 + dp[i+1][transaction]);
        }
    }

    return dp[0][0];

    // TC -> O(N*4)
    // SC -> O(N*4) + O(N)
}

int maxProfitSO(int n, int k, vector<int>& prices) {
    
    vector<int> after(2*k+1,0);
    vector<int> curr(2*k+1,0);

    for(int i=n-1; i>=0; i--) {
        for(int transaction=2*k-1; transaction>=0; transaction--) {
            if(transaction%2==0) curr[transaction] =  max(-prices[i] + after[transaction+1], 0 + after[transaction]);
            else curr[transaction] = max(prices[i] + after[transaction+1], 0 + after[transaction]);
        }
        after = curr;
    }

    return after[0];

    // TC -> O(N*4)
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

    // This is the same question but we are using a different strategy for this. Here, we are allowed k transactions at max!!
    // Here we have used a variable called transaction which holds four states (buy1,sell1,buy2,sell2), thus whenever the transaction is even, we buy otherwise we sell. Finally when transaction crosses sell2 then we return 0.

    int n;
    cin >> n;
    vector<int> prices(n);

    for(int i=0;i<n; i++) cin >> prices[i];

    int k;
    cin >> k;

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n+1,vector<int>(2*k+1,-1));
    int profit1 = maxProfit(0,0,n,k,prices,dp1);
    cout << profit1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1,vector<int>(2*k+1,0));
    int profit2 = maxProfitTab(n,k,prices,dp2);
    cout << profit2 << endl;

    // Space-Optimization Approach:
    int profit3 = maxProfitSO(n,k,prices);
    cout << profit3 << endl;


    return 0;
}
