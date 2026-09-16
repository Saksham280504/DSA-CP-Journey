#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Youtube Channel -> Senior
int n;
vector<vector<int>> adjLS;
vector<vector<int>> dp;

void dfs(int u, int p) {
    // for dp[u][0]
    for(int v: adjLS[u]) {
        if(v!=p) {
            dfs(v,u);
            dp[u][0] += max(dp[v][0],dp[v][1]);
        }
    }
    // for dp[u][1]
    for(int v: adjLS[u]) {
        if(v!=p) {
            dp[u][1] = max(dp[u][1],1+dp[u][0]-max(dp[v][0],dp[v][1])+dp[v][0]);
        }
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

    cin >> n;
    adjLS.resize(n+1);
    dp.assign(n+1,vector<int>(2,0));
    // dp[u][0] -> maximum number of matching in subtree of u not taking any direct edges of u with its children
    // dp[u][0] = SUM(max(dp[v][0],dp[v][1]))
    // dp[u][1] -> maximum number of matching in subtree of u taking one edge from all the edges connecting the children with u
    // dp[u][1] -> max(1 + SUM(max(dp[v][0],dp[v][1])) - max(dp[v0][0],dp[v0][1]) + dp[v0][0]) = max(1 + dp[u][0] - max(dp[v0][0],dp[v0][1]) + dp[v0][0])

    for(int i=0; i<(n-1); i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }
    dfs(1,0);
    cout << max(dp[1][0],dp[1][1]) << endl;

    return 0;
}
