#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
typedef pair<int,pair<int,ll>> Edge;

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
    vector<Edge> edges(m);
    vector<int> adjLS[n+1];

    for(int i=0; i<m; i++) {
        int u,v;
        ll wt;
        cin >> u >> v >> wt;
        edges[i] = {u,{v,wt}};
        adjLS[u].push_back(v);
    }

    vector<ll> dist(n+1,LLONG_MIN);
    dist[1] = 0;
    for(int i=0; i<n-1; i++) {
        for(auto [u, vw]: edges) {
            int v = vw.first;
            ll w = vw.second;
            if(dist[u]!=LLONG_MIN && dist[v]<dist[u]+w) dist[v] = dist[u]+w;
        }
    }

    set<int> cyclic_nodes;
    for(auto [u,vw]: edges) {
        int v = vw.first;
        ll w = vw.second;
        if(dist[u]!=LLONG_MIN && dist[v]<dist[u]+w) cyclic_nodes.insert(v);
    }

    vector<bool> vis(n+1,false);
    queue<int> q;
    q.push(1);
    queue<int> cycle_q;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(vis[node]) continue;
        vis[node] = true;
        if(cyclic_nodes.count(node)) cycle_q.push(node);
        for(int adj: adjLS[node]) {
            if(!vis[adj]) q.push(adj);
        }
    }

    vis.assign(n+1,false);
    bool is_reachable = false;

    while(!cycle_q.empty()) {
        int node = cycle_q.front();
        cycle_q.pop();
        if(vis[node]) continue;
        vis[node] = true;
        if(node==n) {
            is_reachable = true;
            break;
        }
        for(int adj: adjLS[node]) {
            if(!vis[adj]) cycle_q.push(adj);
        }
    }

    if(is_reachable) cout << -1 << endl;
    else cout << dist[n] << endl;

    return 0;
}
