#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

ll mod = 1e9+7;
vector<ll> dp;

ll numOfWays(ll sum) {
    if(sum==0) return 1;
    if(dp[sum]!=-1) return dp[sum];
    ll ways = 0;
    for(int k=1; k<=6; k++) {
        if(k<=sum) ways = (ways + numOfWays(sum-k))%mod;
    }
    return dp[sum] = ways;
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
    ll n;
    cin >> n;

    // Memoization Approach
    // dp.assign(n+1,-1);
    // cout << numOfWays(n) << endl;

    // Tabulation approach - 1
    // dp.assign(n+1,0);
    // dp[0] = 1;
    // // dp[i] = number of ways to create sum i
    // for(int sum=1; sum<=n; sum++) {
    //     for(int k=1; k<=6; k++) {
    //         if(k<=sum) dp[sum] = (dp[sum]+dp[sum-k])%mod;
    //     }
    // }
    // cout << dp[n] << endl;

    // Tabulation approach - 2
    // dp.assign(n+1,0);
    // dp[n] = 1;
    // // dp[i] -> number of ways to reach n if currently at i
    // for(int sum=n-1; sum>=0; sum--) {
    //     for(int k=1; k<=6; k++) {
    //         if((sum+k)<=n) dp[sum] = (dp[sum]+dp[sum+k])%mod;
    //     }
    // }
    // cout << dp[0] << endl;

    // Space Optimization approach

    // we know that for any sum that we want to create, it depends upon sum-1, sum-2, sum-3, sum-4, sum-5 and sum-6 as (1,2,3,4,5,6) are the only last dice digits possible.
    // dp[sum] = dp[sum-6] + dp[sum-5] + dp[sum-4] + dp[sum-3] + dp[sum-2] + dp[sum-1]

    vector<ll> prev = {1}; // dp[0] = 1
    for(ll sum=1; sum<=n; sum++) {
        ll curr = 0;
        for(ll j: prev) {
            curr = (curr+j)%mod;
        }
        prev.push_back(curr);
        if(prev.size()>6) prev.erase(prev.begin());
    }
    cout << prev.back() << endl;
    return 0;
}
