#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int max_log = 20;
struct LCA {
    int n;
    vector<vector<int>> adjLS;
    vector<vector<int>> bl;
    vector<int> depth;
    public:
    LCA(int n) {
        this->n = n;
        adjLS.resize(n+1);
        bl.assign(max_log,vector<int>(n+1,0)); // bl[0][0] = 0 handled
        depth.assign(n+1,0);
    }
    void edge_join(int u, int v) {
        adjLS[u].push_back(v);
    }

    void build(int root) {
        dfs(root,0,0);
        // Every node's 2^0th ancestor is assigned in the DFS
        for(int k=1; k<max_log; k++) {
            for(int u=1; u<=n; u++) {
                bl[k][u] = bl[k-1][bl[k-1][u]];
            }
        }
    }

    void dfs(int u, int p, int d) {
        depth[u] = d;
        bl[0][u] = p; 
        for(int v: adjLS[u]) {
            if(v!=p) dfs(v,u,d+1);
        }
    }

    int lowest_common_ancestor(int u, int v) {
        if(depth[u]<depth[v]) swap(u,v); // depth[u] >= depth[v]
        int diff = depth[u] - depth[v];

        for(int k=0; k<max_log; k++) {
            if(diff&(1<<k)) u = bl[k][u];
        }
        if(u==v) return u;

        for(int k=max_log-1; k>=0; k--) {
            if(bl[k][u]!=bl[k][v]) {
                u = bl[k][u];
                v = bl[k][v];
            }
        }

        return bl[0][u];
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

    int n,q;
    cin >> n >> q;
    LCA lc(n);

    for(int i=2; i<=n; i++) {
        int p;
        cin >> p;
        lc.edge_join(p,i);
    }

    lc.build(1);

    while(q--) {
        int u,v;
        cin >> u >> v;
        cout << lc.lowest_common_ancestor(u,v) << endl;
    }
    return 0;
}
