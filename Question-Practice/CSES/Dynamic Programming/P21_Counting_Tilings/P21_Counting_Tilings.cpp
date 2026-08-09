#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
const int mod = 1e9+7;

void generate_mask(int i, int curr, int mask, int n, vector<int>& next) {
    if(i>=n) {
        next.push_back(curr);
        return;
    }
    if((mask>>i)&1) {
        generate_mask(i+1,curr,mask,n,next);
    }
    else {
        generate_mask(i+1,curr+(1<<i), mask, n, next);
        if(i+2<=n && (((mask>>(i+1))&1)==0)) generate_mask(i+2,curr,mask,n,next);
    }
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
    int n,m;
    cin >> n >> m;
    // The central idea is to process the grid column by column, and want to see in how many different ways we can fill up the grid and what are the total number of ways to fill up the grid in one of those configurations.
    // dp[i][mask] -> Number of ways to completely tile the first i columns such that the occupancy pattern of column i is represented by mask.
    // What is mask?
    // Since there are n rows, there can be 2^n configurations (or masks), like if n=4, mask can be = 0101 -> this means 0th and 2nd row of ith column is filled and 1st and 3rd row of ith column is empty.
    vector<vector<long long>> dp(m+1,vector<long long>(1<<n));
    dp[0][0] = 1;
    // Before processing any columns, there are no occupied cells, thus for 0th row to be completely empty is only one way when no tiles are filled.
    for(int i=0; i<m; i++) {
        for(int mask=0; mask<(1<<n); mask++) {
            if(dp[i][mask]==0) continue;
            vector<int> next;
            generate_mask(0,0,mask,n,next);
            for(auto &x: next) {
                dp[i+1][x] = (dp[i+1][x]+dp[i][mask])%mod;
            }
        }
    }
    cout << dp[m][0] << endl;
 
    return 0;
}
