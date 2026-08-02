#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

const ll mod = 1e9+7;
const int  MAXN = 1e6;
ll dp[MAXN+1][2];

void solve() {
    int n;
    cin >> n;
    // dp[i][0] -> number of ways to fill up the grid up to the top from the ith row such that there is 1 2 width block trying to expand from i-1th row.
    // dp[i][1] -> number of ways to fill up the grid up to the top from the ith row, if there are 2 1 width blocks trying to expand from the i-1th row.

    // Base-Cases:
    dp[n][0] = 1;
    dp[n][1] = 1;

    for(int i=n-1; i>=1; i--) {
        dp[i][0] = (2LL*dp[i+1][0] + dp[i+1][1])%mod;
        dp[i][1] = (4LL*dp[i+1][1] + dp[i+1][0])%mod;
    }

    ll totalWays = (dp[1][0] + dp[1][1])%mod;
    cout << totalWays << endl;
}

void precompute() {
    // dp[i][0] -> number of ways to create tower of height i, such that there is a 2 unit wide block at ith layer
    // dp[i][1] -> number of ways to create a tower of height i, such that there are 2 1 unit wide blocks at ith layer

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2; i<=1e6; i++) {
        dp[i][0] = (2LL*dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = (4LL*dp[i-1][1] + dp[i-1][0])%mod;
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

    // Approach - 1 -> TC -> O(N*T)
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    // Approach - 2 -> TC -> O(N + T)
    // precompute();
    // int t;
    // cin >> t;
    // while(t--) {
    //     int n;
    //     cin >> n;
    //     cout << (dp[n][0]+dp[n][1])%mod << endl;
    // }
    return 0;
}
