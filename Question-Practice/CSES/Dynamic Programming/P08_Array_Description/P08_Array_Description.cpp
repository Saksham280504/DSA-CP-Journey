#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
const int mod = 1e9+7;

bool isValid(int x, int m) {
    return (x>=1 && x<=m);
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
    vector<int> arrDesc(n);
    for(int i=0; i<n; i++) cin >> arrDesc[i];

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // dp[i][k] -> number of ways to create prefix array of length i with ending element as k

    // For 1 length prefix
    for(int k=1; k<=m; k++) {
        if(arrDesc[0]==0 || arrDesc[0]==k) dp[1][k] = 1;
    }

    for(int i=2; i<=n; i++) {
        for(int k=1; k<=m; k++) {
            if(arrDesc[i-1]!=0 && arrDesc[i-1]!=k) continue;

            for(int prev=k-1; prev<=k+1; prev++) {
                if(!isValid(prev,m)) continue;
                dp[i][k] = (dp[i][k]+dp[i-1][prev])%mod;
            }
        }
    }

    int ways = 0;
    for(int k=1; k<=m; k++) {
        ways = (ways+dp[n][k])%mod;
    }
    cout << ways << endl;

    return 0;
}
