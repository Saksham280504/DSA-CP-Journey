#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void dfsOfGraph(int node,vector<int>& vis, vector<int> adj[], vector<int>& dfs) {
    vis[node]=1;
    dfs.push_back(node);

    for(auto it: adj[node]) {
        if(!vis[it]) dfsOfGraph(it,vis,adj,dfs);
    }

    // SC -> O(N)(dfs) + O(N) (visited array) + O(N) (recursion stack-space) (without adjacency list)
    // TC -> O(N) (for every node) + O(2*E) (degree of graph/ summation of degree of every node)
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

    int n,m;
    cin >> n >> m;

    vector<int> adj[n];

    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n,0);
    int start = 0;
    vector<int> dfs;
    dfsOfGraph(start,vis,adj,dfs);

    for(auto it: dfs) {
        cout << it << " ";
    }
    return 0;
}
