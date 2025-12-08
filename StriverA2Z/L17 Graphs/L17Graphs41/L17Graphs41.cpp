#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int spanningTree(int n, vector<vector<int>>&edges) {
    vector<pair<int,int>> adjLS[n];
    for(auto it: edges) {
        adjLS[it[0]].push_back({it[1],it[2]});
        adjLS[it[1]].push_back({it[0],it[2]});
    }
    vector<int> vis(n,0);
    // {edgW,node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    int sum = 0; // to calculate MST weight

    // O(E) (overall the priority queue will have all the edges)
    while(!pq.empty()) {
        // O(logE) (pq traversal)
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node]==1) continue; // If the node is already visited we don't do anything on it 

        // For unvisited node
        vis[node] = 1; // We mark visited here to add it to the mst
        sum += wt;

        // Overall after all the iterations O(E)
        for(auto it: adjLS[node]) {
            int adjNode = it.first;
            int edgW = it.second;
            if(!vis[adjNode]) {
                // for pq traversal O(logE) 
                pq.push({edgW,adjNode});
                // We don't mark visited here
            }
        }
    }

    return sum;

    // TC -> O(ElogE) + O(ElogE)
    // SC -> O(N) (visited array) + O(E) (worst case for priority_queue)
}

vector<vector<int>> spanningTreeMST(int n, vector<vector<int>>&edges) {
    vector<pair<int,int>> adjLS[n];
    for(auto it: edges) {
        adjLS[it[0]].push_back({it[1],it[2]});
        adjLS[it[1]].push_back({it[0],it[2]});
    }

    // {wt,node,parent}
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<int> vis(n,0);

    pq.push({0,{0,-1}});
    int sum = 0;
    vector<vector<int>> mst;

    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if(vis[node]==1) continue; // If the node is visited, we don't do anything on it

        // If node is not visited
        vis[node] = 1;
        sum += wt;
        if(wt!=0)mst.push_back({parent,node});
        for(auto adj: adjLS[node]) {
            int adjNode = adj.first;
            int edgW = adj.second;
            if(!vis[adjNode]) {
                pq.push({edgW,{adjNode,node}});
            }
        }
    }

    // Now sum = MST weight and mst has all the edges

    return mst;
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

    // Prim's Algorithm:
    // 1. Prim's algorithm is used to determine the minimum spanning tree.
    // 2. This algorithm provide us with MST weight and all the MST edges.

    // What do we need for Prim's algorithm:
    // 1. Priority Queue (min_heap) {wt,node,parent}
    // 2. Visited array (initialized as {0})
    // 3. Sum = 0 to calculate MST weight
    // 4. MST list to determine MST edges.

    // We push {0,0,-1} into the queue but don't mark anything in the visited array, this is the initial configuration. 

    // The intuition of this algorithm is that we simply start with 0, look for its adjacent Nodes and push them into the priority queue. Then in the queue, we greedily look for the closest adjNode or the adjNode with minimum edgW, and then we mark it as visited and add it into mst. We then look for the neighbours of that node and add them into the queue and finally the same process goes on.

    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++) {
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({u,v,wt});
    }

    vector<vector<int>> ans = spanningTreeMST(n,edges);

    for(auto x: ans) {
        cout << x[0] << " " << x[1] << endl;
    }

    return 0;
}
