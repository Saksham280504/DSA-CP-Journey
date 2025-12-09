#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int timer = 1;
void dfsCheck(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<int> adjLS[], vector<vector<int>>& bridges ) {
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    for(auto adjNode: adjLS[node]) {
        if(adjNode==parent) continue;
        else if(!vis[adjNode]) {
            dfsCheck(adjNode,node,vis,tin,low,adjLS,bridges);
            low[node] = min(low[node],low[adjNode]);
            if(low[adjNode]>tin[node]) bridges.push_back({adjNode,node});
        }
        else {
            low[node] = min(low[node],low[adjNode]);
        }
    }

    // Very important things to notice here are:-

    // For a linear graph, all of its nodes will have tin[node] = low[node] due to which every edge of that graph will be a bridge
    // For a cyclic graph, all of its nodes after the dfs traversal will have the same low[node] which will be the point/node from where the cycle started. This tells us that even if any edge between a parent and a node is broken in that cycle, the node can still reach to the starting node of that cycle from where it can reach to its parent, thus in a cycle all of its edges are not bridges.
}
vector<vector<int>> criticalConnections(int n,vector<vector<int>>& connections) {
    vector<int> adjLS[n];
    for(auto it: connections) {
        adjLS[it[0]].push_back(it[1]);
        adjLS[it[1]].push_back(it[0]);
    }
    vector<int> vis(n,0), tin(n), low(n);
    vector<vector<int>> bridges;
    dfsCheck(0,-1,vis,tin,low,adjLS,bridges);

    return bridges;

    // TC -> O(V+2E)
    // SC -> O(3N)
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

    // Bridges in a graph:

    // Any edge of the graph on whose removal, the graph gets broken down into two or more components, then that edge is known as a bridge.

    // To determine bridges, we use DFS traversal.

    // To determine the number of bridges, we will take 2 arrays:

    // 1. time of insertion array (DFS time insertion)
    // 2. lowest time of insertion array (min lowest time insertion of all adjacent nodes apart from parent).

    return 0;
}
