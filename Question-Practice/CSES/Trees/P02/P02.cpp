#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

const int maxi = 2e5+2;
vector<int> adj[maxi];
int dp[maxi][2]; // dp[node][0] -> node doesn't connect with any children, dp[node][1] -> node connects with one child

void dfs(int v, int p) {
    for(int u: adj[v])  {
        if(u!=p) {
            dfs(u,v);
            dp[v][0] += max(dp[u][0],dp[u][1]);
        }
    }
    for(int u: adj[v]) {
        if(u!=p) {
            dp[v][1] = max(dp[v][1], dp[v][0] - max(dp[u][0],dp[u][1]) + dp[u][0] + 1); // Once v connects to any u, that u doesn't have the liberty anymore to think whether u will connect with its children or not. It can't connect
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
    int n;
    cin >> n;

    for(int i=0; i<n-1; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout << max(dp[1][0],dp[1][1]) << endl;

    return 0;
}
