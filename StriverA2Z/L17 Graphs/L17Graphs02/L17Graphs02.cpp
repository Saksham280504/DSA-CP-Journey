#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // We will be given integer n(number of nodes) and m(number of edges) as the 1st line of input.
    int n,m;
    cin >> n >> m;

    // Then we will be given m lines of input showing edges.
    // We can store the graph in two ways:

    // 1) Adjacency Matrix Method:-

    // vector<vector<int>> adj(n+1,vector<int>(n+1,0));

    // for(int i=0; i<m; i++) {
    //     int u,v;
    //     cin >> u >> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }

    // TC -> O(M)
    // SC -> O(N*N) (too much)

    // 2) Adjacency List Method:-

    // vector<int> adj[n+1];

    // for(int i=0; i<m; i++) {
    //     int u,v;
    //     cin >> u >> v;
    //     adj[u].push_back(v); // From u to v
    //     adj[v].push_back(u); // From v to u
    // }

    // TC -> O(M)
    // SC -> O(2M)

    // For a directed graph, we know that if we have u v as the input, then the edge only goes from u to v and not from v to u. Therefore we would only use the statement : adj[u].push_back(v) and not adj[v].push_back(u). SC -> O(M) for directed graph

    // In case of weighted graph, you will have u v wt as the input where u & v are vertices and wt is the edge weight between them. In order to store the weight, we use the following ways:

    // 1) Matrix Method:

    // vector<vector<int>> adj(n+1,vector<int>(n+1,0));

    // for(int i=0; i<m; i++) {
    //     int u,v,wt;
    //     cin >> u >> v >> wt;

    //     adj[u][v] = wt;
    //     adj[v][u] = wt; // Rather than storing 1, we store weights here
    // }

    // TC -> O(N)
    // SC -> O(N*N)

    // 2) List Method:

    vector<pair<int,int>> adj[n+1];

    for(int i=0; i<m; i++) {
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    // TC -> O(M)
    // SC -> O(2*(M*2))
    return 0;
}
