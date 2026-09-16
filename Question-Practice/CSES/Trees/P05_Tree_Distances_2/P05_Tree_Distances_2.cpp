#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Youtube Channel -> Senior
int n;
vector<vector<int>> adjLS;
vector<int> ans,dp;

void dfs1(int u, int p, int dist) {
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
    ans.resize(n+1);
    dp.assign(n+1,0);


    return 0;
}
