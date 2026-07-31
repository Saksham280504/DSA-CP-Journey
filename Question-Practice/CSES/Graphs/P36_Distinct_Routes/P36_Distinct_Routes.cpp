#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct Edge {
    int to, revIndex;
    ll cap, flow;

    Edge(int _to, int _revIndex, ll _cap, ll _flow) {
        to = _to;
        revIndex = _revIndex;
        cap = _cap;
        flow = _flow;
    }
};

struct Dinic {
    int n;
    vector<vector<Edge>> adjLS;
    vector<int> level, it;

    Dinic(int m) {
        n = m;
        adjLS.resize(n+1);
        level.resize(n+1);
        it.resize(n+1);
    }

    void addEdge(int u, int v, ll cap) {
        int idx_u = adjLS[u].size();
        int idx_v = adjLS[v].size();
        adjLS[u].push_back({v,idx_v,cap,0});
        adjLS[v].push_back({u,idx_u,0,0});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &e: adjLS[u]) {
                if(e.cap-e.flow>0 && level[e.to]==-1) {
                    level[e.to] = level[u]+1;
                    q.push(e.to);
                }
            }
        }
        return level[t]!=-1;
    }

    ll dfs(int u, int t, ll f) {
        if(u==t) return f;
        for(int &cid=it[u]; cid<adjLS[u].size(); cid++) {
            auto &e = adjLS[u][cid];
            if(e.cap-e.flow<=0 || level[e.to]!=level[u]+1) continue;
            ll pushed = dfs(e.to, t, min(f,e.cap-e.flow));
            if(pushed>0) {
                e.flow += pushed;
                adjLS[e.to][e.revIndex].flow -= pushed;
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
    Dinic dinic(n);
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        dinic.addEdge(u,v,1);
    }
    ll maxPaths = dinic.max_flow(1,n);

    vector<vector<int>> routes;
    for(int i=0; i<maxPaths; i++) {
        vector<int> path;
        int curr=1;
        path.push_back(curr);
        while(curr!=n) {
            bool found = false;
            for(auto &e: dinic.adjLS[curr]) {
                if(e.flow>0 && e.to>=1 && e.to<=n) {
                    curr = e.to;
                    path.push_back(curr);
                    e.flow = 0; // to mark as visited
                    found = true;
                    break;
                }
            }
            if(!found) break;
        }
        routes.push_back(path);
    }

    cout << maxPaths << endl;
    for(auto &path: routes) {
        cout << path.size() << endl;
        for(auto &node: path) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
