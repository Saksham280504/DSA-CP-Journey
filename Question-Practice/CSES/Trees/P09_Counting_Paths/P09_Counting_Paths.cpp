#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int n,m;
vector<vector<int>> adjLS;
vector<int> depth;
vector<vector<int>> BinaryLift;
vector<int> value; // This array will initially store 0,-1,1 if they are part of any paths or not. And once we apply dfs_final for prefixing the sum of all nodes in subtree rooted at every node, value[node] -> sum of values of all nodes of subtree rooted at node = number of paths node is part of
int MAX_BIT = 20;

void dfs_depth(int u, int p) {
    BinaryLift[u][0] = p;
    for(int j=1; j<MAX_BIT; j++) {
        BinaryLift[u][j] = BinaryLift[BinaryLift[u][j-1]][j-1];
    }
    for(int v: adjLS[u]) {
        if(v==p) continue;
        depth[v] = depth[u]+1;
        dfs_depth(v,u);
    }
}

int find_lca(int u, int v) {
    if(depth[u]<depth[v]) swap(u,v); // depth[u]<=depth[v]

    int diff = depth[u]-depth[v];
    for(int bit=MAX_BIT-1; bit>=0; bit--) {
        if(diff&(1<<bit)) {
            u = BinaryLift[u][bit];
        } 
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

void dfs_final(int u, int p) {
    int x = value[u];
    for(int v: adjLS[u]) {
        if(v==p) continue;
        dfs_final(v,u);
        x += value[v];
    }
    value[u] = x;
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
    cin >> n >> m;
    adjLS.resize(n+1);
    depth.assign(n+1,0);
    BinaryLift.assign(n+1,vector<int>(MAX_BIT,0));

    for(int i=1; i<n; i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }
    dfs_depth(1,0);
    value.assign(n+1,0);

    while(m--) {
        int a,b;
        cin >> a >> b;
        value[a]++;
        value[b]++;
        int lca = find_lca(a,b);
        value[lca]--;
        int above_lca = BinaryLift[lca][0];
        if(above_lca) value[above_lca]--;
    }

    dfs_final(1,0);

    for(int i=1; i<=n; i++) cout << value[i] << " ";
    cout << endl;

    return 0;
}
