#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct Edge {
    int to;
    ll cap;
    int revIndex;
    Edge(int _to, ll _cap, int _revIndex) {
        to = _to;
        cap = _cap;
        revIndex = _revIndex;
    }
};

struct Dinic {
    int n;
    vector<vector<Edge>> adjLS; // adjLS will store for all vertices the information of all the outgoing edges -> adjLS[u] -> {{v1,cap1,rev1},{v2,cap2,rev2}}
    vector<int> level, it; // level will be used to create level graph in every BFS call, it[u] -> next unused edge that can be used for u.

    Dinic(int m) {
        n = m;
        adjLS.resize(m+1);
        level.resize(m+1);
        it.resize(m+1);
    }

    void addEdge(int u, int v, ll cap) {
        adjLS[u].push_back({v,cap,adjLS[v].size()});
        adjLS[v].push_back({u,0LL,adjLS[u].size()-1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &e: adjLS[u]) {
                if(level[e.to]==-1 && e.cap>0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t]!=-1;
    }

    ll dfs(int u, int t, ll f) {
        if(u==t) return f;
        for(int &cid = it[u]; cid<adjLS[u].size(); cid++) {
            Edge &e = adjLS[u][cid];
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

    ll maxFlow(int s, int t) {
        ll flow = 0;
        while(bfs(s,t)) {
            fill(it.begin(), it.end(),0);
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
        ll cap;
        cin >> u >> v >> cap;
        dinic.addEdge(u,v,cap);
    }
    ll maxFlow = dinic.maxFlow(1,n);
    cout << maxFlow << endl;

    return 0;
}
