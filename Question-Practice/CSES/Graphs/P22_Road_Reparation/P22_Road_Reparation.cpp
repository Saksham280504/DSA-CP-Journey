#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

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
    vector<pair<int,int>> adjLS[n+1];
    vector<bool> vis(n+1,false);
    for(int i=0; i<m; i++) {
        int u,v,ct;
        cin >> u >> v >> ct;
        adjLS[u].push_back({v,ct});
        adjLS[v].push_back({u,ct});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1});
    long long res = 0;
    while(!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();
        if(vis[node]) continue;
        vis[node] = true;
        res += cost;
        for(auto [adj,wt]: adjLS[node]) {
            if(!vis[adj]) {
                pq.push({wt,adj});
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << res << endl;
    return 0;
}
