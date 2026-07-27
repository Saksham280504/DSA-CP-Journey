#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long 
ll INF = 1e18;
ll MOD = 1e9+7;
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
    vector<pair<int,ll>> adjLS[n+1];
    for(int i=0; i<m; i++) {
        int u,v;
        ll wt;
        cin >> u >> v >> wt;
        adjLS[u].push_back({v,wt});
    }
    vector<vector<ll>> dp(n+1,vector<ll>(4,INF));
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<>> pq;
    pq.push({0,1});

    while(!pq.empty()) {
        auto [currCost,u] = pq.top();
        pq.pop();
        if(currCost>dp[u][0]) continue;
        for(auto &[v,wt]: adjLS[u]) {
            ll newCost = currCost+wt;
            if(newCost<dp[v][0]) {
                dp[v][0] = newCost;
                dp[v][1] = dp[u][1];
                dp[v][2] = dp[u][2] + 1;
                dp[v][3] = dp[u][3] + 1;
                pq.push({newCost,v});
            }
            else if(newCost==dp[v][0]) {
                dp[v][1] = (dp[v][1] + dp[u][1])%MOD;
                dp[v][2] = min(dp[v][2],dp[u][2]+1);
                dp[v][3] = max(dp[v][3],dp[u][3]+1);
            }
        }
    }

    cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << " " << dp[n][3] << endl;
    return 0;
}
