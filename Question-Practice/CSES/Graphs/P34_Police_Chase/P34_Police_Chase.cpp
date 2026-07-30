#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct Edge {
    int to;
    ll cap;
    int revIndex;
    Edge(int _to, ll _cap , int _revIndex) {
        to = _to;
        cap = _cap;
        revIndex = _revIndex;
    }
};

struct Dinic {
    int n;
    vector<vector<Edge>> adjLS;
    vector<int> level, it;

    Dinic(int m) {
        n = m;
        adjLS.resize(m+1);
        level.resize(m+1);
        it.resize(m+1);
    }

    void addEdge(int u, int v, ll cap) {
        adjLS[u].push_back({v,cap, adjLS[v].size()});
        adjLS[v].push_back({u,0LL, adjLS[u].size()-1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &e: adjLS[u]) {
                if(e.cap<=0 || level[e.to]!=-1) continue;
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }

        return (level[t]!=-1);
    }

    ll dfs(int u, int t, ll f) {
        if(u==t) return f;
        for(int &cid = it[u]; cid<adjLS[u].size(); cid++) {
            auto &e = adjLS[u][cid];
            if(e.cap<=0 || level[e.to]!=level[u]+1) continue;
            ll pushed = dfs(e.to, t, min(f,e.cap));
            if(pushed>0) {
                e.cap -= pushed;
                adjLS[e.to][e.revIndex].cap += pushed;
                return pushed;
            }
        }
        return 0;
    }

    ll max_flow(int s, int t) {
        ll flow = 0;
        while(bfs(s,t)) {
            fill(it.begin(), it.end(), 0);
            while(ll pushed = dfs(s,t,LLONG_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }

    vector<bool> isReachable(int s) {
        vector<bool> vis(n+1,false);
        vis[s] = true;
        queue<int> q;
        q.push(s);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &e: adjLS[u]) {
                if(e.cap<=0 || vis[e.to]) continue;
                vis[e.to] = true;
                q.push(e.to);
            }
        }

        return vis;
    }
};

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
    vector<pair<int,int>> edges;
    Dinic dinic(n);
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        dinic.addEdge(u,v,1);
        dinic.addEdge(v,u,1); // since edges are 2-way
        // We have given 1 as capacity of edges, because we want only 2 states of an edge, i.e. either they are open or they are closed.
        edges.push_back({u,v});
    }
    ll max_flow = dinic.max_flow(1,n);

    vector<bool> is_reachable = dinic.isReachable(1);

    vector<pair<int,int>> cuts;

    for(auto &[u,v]: edges) {
        if(is_reachable[u] && !is_reachable[v]) {
            cuts.push_back({u,v});
        }
        if(is_reachable[v] && !is_reachable[u]) {
            cuts.push_back({v,u});
        }
    }

    cout << cuts.size() << endl;
    for(auto [a,b]: cuts) {
        cout << a << " " << b << endl;
    }


    return 0;
}
