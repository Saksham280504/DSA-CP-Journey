#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void floydWarshall(vector<vector<int>> &dist) {
    
    int n = dist.size();

    for(int k=0; k<n; k++) { // via 
        for(int i=0; i<n; i++) { // from
            for(int j=0; j<n; j++) { // to
                if(dist[i][k]!=1e8 && dist[k][j]!=1e8) { 
                    // This step is very important to make sure that d[i][k] + d[k][j] doesn't create overflow.
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    // For every kth iteration, we use the matrix that we get from the (k-1)th iteration.

    // TC -> O(N^3)
    // SC -> O(N^2)
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

    // Floyd Warshall Algorithm: 

    // Q-1) Why does this algorithm differ from Dijkstra and Bellman Ford Algorithm?
    // Ans. Dijkstra and and Bellman are single source shortest path algorithms, whereas Floyd Warshal algorithm is a multi source sorted path algorithm.

    // We can also find negative weight cycles using Floyd Warshall Algorithm.

    // Procedure for Floyd Warshall Algorithm:-

    // 1. Go via every vertex -> d[i][j] = min(d[i][k] + d[k][j]) (if there are 5 nodes(0 to 4) and we need to find d[0][1], then for that k will be 2,3,4). One very important thing that we have here is that it might happen that to compute d[i][j], we will need to make sure that the values of d[i][k] and d[k][j] are precomputed, and wherever we use precomputed data, that is where we know that dynamic programming comes in.

    // Floyd Warshall Algorithm is just a brute-force method and no such intuition exists for this Algorithm. 
    // You just need to reach from every ith node to every jth node via every kth node, and the overall resultant that you get from all these iterations is your shortest path matrix.

    // One thing we must know is that shortest path from ith node to ith node must be 0. So, we initially take it as 0 when we form the adjacency matrix of the graph. So if after all the iterations we get d[i][i]<0, then that means that a negative cycle exists in that graph.

    // Floyd warshall also only works for directed graph, in case of undirected graphs, we build bidirected graphs.


    return 0;
}
