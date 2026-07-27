#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

const int MOD = 1e9+7;
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
    vector<int> adjLS[n+1];
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adjLS[u].push_back(v);
    }   
    vector<int> indegree(n+1,0);
    for(int u=1; u<=n; u++) {
        for(int v: adjLS[u]) indegree[v]++;
    }

    queue<int> q;
    for(int u=1; u<=n; u++) {
        if(!indegree[u]) q.push(u);
    }

    vector<int> order;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(int v: adjLS[u]) {
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }

    vector<int> dp(n+1,0);
    dp[1] = 1;
    for(int u: order) {
        if(dp[u]==0) continue;
        for(int v: adjLS[u]) {
            dp[v] = (dp[v]+dp[u])%MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
