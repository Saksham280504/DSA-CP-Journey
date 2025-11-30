#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    // For zero-based indexing
    
    // Initial configuration
    int vis[n] = {0};
    vis[0] = 1; // Starting Node
    queue<int> q;
    q.push(0); // Starting Node
    vector<int> bfs;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    return bfs;

    // SC -> O(3N) -> O(N)
    // TC -> O(N) (outer while loop for q) + O(2E) (inner for loop for all the degrees of that particular node)
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

    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs  = bfsOfGraph(n,adj);

    for(int i=0; i<n; i++) {
        cout << bfs[i] << " ";
    }

    return 0;
}
