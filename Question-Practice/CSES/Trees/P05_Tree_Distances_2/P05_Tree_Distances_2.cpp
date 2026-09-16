#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
// Youtube Channel -> Senior
ll n;
vector<vector<int>> adjLS;
vector<ll> ans,dp;

void dfs1(int u, int p, ll dist) {
    ans[1] += dist;
    dp[u] = 1;
    for(int v: adjLS[u]) {
        if(v==p) continue;
        dfs1(v,u,dist+1);
        dp[u] += dp[v];
    }
}

void dfs2(int u, int p) {
    for(int v: adjLS[u]) {
        if(v==p) continue;
        ans[v] = ans[u] + n - 2*dp[v];
        dfs2(v,u);
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
    for(int i=0; i<n-1; i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }
    ans.assign(n+1,0);
    dp.assign(n+1,0);

    dfs1(1,0,0);
    dfs2(1,0);

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
