#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int n,q;
int MAX_BIT = 20;
vector<vector<int>> adjLS;
vector<vector<int>> BinaryLift;
vector<int> depth;

void dfs(int u, int p) {
    BinaryLift[u][0] = p;
    for(int j=1; j<MAX_BIT; j++) {
        BinaryLift[u][j] = BinaryLift[BinaryLift[u][j-1]][j-1];
    }
    for(int v: adjLS[u]) {
        if(v==p) continue;
        depth[v] = depth[u]+1;
        dfs(v,u);
    }
}

int find_lca(int u, int v) {
    if(depth[u]<depth[v]) swap(u,v); // We always want depth[u] >= depth[v]
    int diff = depth[u]-depth[v];
    for(int bit=MAX_BIT-1; bit>=0; bit--) {
        if(diff&(1<<bit)) u = BinaryLift[u][bit];
    }
    if(u==v) return u;
    for(int bit=MAX_BIT-1; bit>=0; bit--) {
        if(BinaryLift[u][bit]!=BinaryLift[v][bit]) {
            u = BinaryLift[u][bit];
            v = BinaryLift[v][bit];
        } 
    }
    return BinaryLift[u][0];
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
    cin >> n >> q;
    adjLS.resize(n+1);
    BinaryLift.assign(n+1,vector<int>(MAX_BIT,0));
    depth.assign(n+1,0);
    for(int i=1; i<n; i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }
    // Here note that we can't perform iterative filling of BinaryLift and depth array as the nodes are not sorted in topological order.
    dfs(1,0);
    while(q--) {
        int a,b;
        cin >> a >> b;
        int lca = find_lca(a,b);
        cout << depth[a]+depth[b]-2*depth[lca] << endl;
    }

    return 0;
}
