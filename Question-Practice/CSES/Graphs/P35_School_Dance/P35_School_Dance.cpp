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
    vector<vector<Edge>> adjLS;
    vector<int> level, it;
    Dinic(int m) {
        n = m;
        adjLS.resize(n+1);
        level.resize(n+1);
        it.resize(n+1);
    }

    int add_Edge(int u, int v, ll cap) {
        int idx_u = adjLS[u].size();
        int idx_v = adjLS[v].size();
        adjLS[u].push_back({v,cap,idx_v});
        adjLS[v].push_back({u,0LL,idx_u});
        
        return idx_u;
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &e : adjLS[u]) {
                if(e.cap<=0 || level[e.to]!=-1) continue;
                level[e.to] = level[u]+1;
                q.push(e.to);
            }
        }
        return level[t]!=-1;
    }

    ll dfs(int u, int t, ll f) {
        if(u==t) return f;
        for(int &cid=it[u]; cid<adjLS[u].size(); cid++) {
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
            while(ll pushed = dfs(s,t,LLONG_MAX)) flow += pushed;
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

    int n,m,k;
    cin >> n >> m >> k;
    int S = 0;
    int offSetB = 1;
    int offSetG = 1+n;
    int T = 1+n+m;

    Dinic dinic(T);
    for(int b=0; b<n; b++) {
        int boyNode = offSetB+b;
        dinic.add_Edge(S,boyNode,1);
    }

    vector<tuple<int,int,int>> edge_list; // {boyNode, edge_Index_from_Boy_to_Girl, GirlNode}
    for(int i=0; i<k; i++) {
        int b,g;
        cin >> b >> g;
        b--; g--;
        int boyNode = offSetB+b;
        int girlNode = offSetG+g;
        int edgeIndex = dinic.add_Edge(boyNode,girlNode,1);
        edge_list.emplace_back(boyNode,edgeIndex,girlNode);
    }

    for(int g=0; g<m; g++) {
        int girlNode = offSetG+g;
        dinic.add_Edge(girlNode,T,1);
    }

    ll max_flow = dinic.max_flow(S,T);

    vector<pair<int,int>> matchedPairs;
    for(auto &[boy,idx,girl]: edge_list) {
        auto &e = dinic.adjLS[boy][idx];
        if(e.cap==0) {
            int boyID = boy-offSetB+1;
            int girlID = girl-offSetG+1;
            matchedPairs.push_back({boyID, girlID});
        }
    }

    cout << max_flow << endl;
    for(auto &[boy,girl]: matchedPairs) {
        cout << boy << " " << girl << endl;
    }

    return 0;
}
