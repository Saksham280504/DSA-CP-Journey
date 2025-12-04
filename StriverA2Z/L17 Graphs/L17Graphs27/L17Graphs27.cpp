#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> shortestPath(vector<vector<int>>& graph, int n, int m) {

    // Always make adjacency list
    vector<int> adjLS[n];

    for(auto it: graph) {
        adjLS[it[0]].push_back(it[1]);
        adjLS[it[1]].push_back(it[0]); // For undirected graph
    }
    int src = 0;
    vector<int> dist(n,1e9);
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it: adjLS[node]) {
            if(dist[node]+1<dist[it]) {
                dist[it] = dist[node]+1;
                q.push(it);
            }  
        }
    }

    for(int i=0; i<n; i++) {
        if(dist[i]==1e9) dist[i]=-1;
    }

    return dist;

    // TC -> O(V+2E) BFS traversal of the graph
    // SC -> O(N) (dist-array) + O(N) (worst case for queue)
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

    return 0;
}
