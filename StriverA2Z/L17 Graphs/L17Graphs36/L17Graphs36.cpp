#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
    vector<int> dist(n,1e8); // Distance array
    dist[src] = 0;

    for(int i=0; i<n; i++) {
        for(auto it: edges) {
            // edges[i] -> {u,v,wt} >> u->v (edge weight = wt)
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]) {
                dist[v] = dist[u]+wt;
            }
        }
    }
    
    // Nth iteration to check for negative cycle:-
    for(auto it:edges) { // Relaxation
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v]) {
            return {-1};
        }
    }
    return dist;

    // Q-1) Why was N-1 iterations performed?
    // -> I have attached the photo of the proof, but still to explain it verbally:
    // There is no graph in which a src will reach a node in more than n-1 edges. Either it will take less than or equal to n-1 edges or that node will be unreachable. So we see that by performing the iteration for n-1 times, we will get the distance of even that node which is present at the maximum distance from the src (i.e. n-1 edges) and there will be no other shorter distance possible than that.

    // Q-2) How to determine if the graph has negative cycle?
    // We know that we get shortest path array after n-1 edges. So if we perform nth iteration, and we see that the dist array is still getting changed that means either the graph didn't reach its minimum shortest path for all nodes which is impossible or that the graph has a section (cycle) with net effective weight < 0.

    // TC -> O(N*edges.size())
    // SC -> O(N)
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

    // Bellman Ford Algorithm (Single source shortest path algorithm):

    // 1) Helps in finding shortest path from src to all the other nodes for a graph 
    // 2) Djikstra fails on negative weight edges and gives a TLE when a negative weight cycle is present in the graph.
    // Negative cycle -> The total weight of the cycle is < 0.

    // Bellman Ford Algorithm  helps us to detect negative weight cycle.

    // Bellman graph is only applicable for DG. This doesn't mean you can't use it for UG, you can, but you need to convert the UG to BDG(Bidirectional graph).

    // Rules:-
    // 1. Edges can be given in any order
    // 2. Relaxation of edges is needed to be done N-1 times.


    return 0;
}
