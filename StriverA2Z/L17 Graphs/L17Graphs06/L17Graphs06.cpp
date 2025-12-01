#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void dfs(int node, vector<int>& vis, vector<int> adjLS[]) {
    vis[node] = 1;
    for(auto it: adjLS[node]) {
        if(!vis[it]) dfs(it,vis,adjLS);
    }
}

int numOfProvinces(int n, vector<vector<int>>& adj) {
    vector<int> adjLS[n];
    
    // Conversion of Adjacency matrix to Adjacency List
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(adj[i][j]==1 && i!=j) {
                adjLS[i].push_back(j);
            }
        }
    }

    vector<int> vis(n,0);
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i,vis,adjLS);
        }
    }

    return cnt;

    // TC -> O(N) (dfs traversal for all nodes) + O(V+2E) (inner loop) ->O(N)
    // SC -> O(N) (vis-array) + O(N) (worst-case of recursion stack space)
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
    vector<vector<int>> adj(n,vector<int>(n,0)); //Input is given in form of adjacency matrix
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // A province is a common term for a "connected component", which is a group of vertices where any two vertices are connected to each other by a path, either directly or indirectly. 

    int cnt = numOfProvinces(n,adj);
    cout << cnt << endl;

    return 0;
}
