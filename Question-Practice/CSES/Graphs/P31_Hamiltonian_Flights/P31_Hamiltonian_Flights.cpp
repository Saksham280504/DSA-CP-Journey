#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
const ll MOD = 1e9+7;

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
    vector<vector<int>> adjLS(n);
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adjLS[u].push_back(v);
    }

    int FULL = (1<<n);
    vector<vector<ll>> dp(FULL,vector<ll>(n,0)); // dp[mask][u] -> Number of ways of starting at node 1, visiting all the cities in mask and ending at city u
    dp[1<<0][0] = 1;
    for(int mask=0; mask<FULL; mask++) {
        for(int u=0; u<n; u++) {
            if(!(mask&(1<<u))) continue;
            ll ways = dp[mask][u];
            if(!ways) continue;
            for(int v: adjLS[u]) {
                if(mask&(1<<v)) continue;
                int newMask = mask | (1<<v);
                dp[newMask][v] = (dp[newMask][v]+ways)%MOD;
            }
        }
    }
    
    cout << (dp[FULL-1][n-1]%MOD) << endl;

    return 0;
}
