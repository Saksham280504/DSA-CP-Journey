#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void topoSortDFS(int node, vector<int>& vis, stack<int>& st, vector<pair<int,int>> adjLS[]) {
    vis[node] = 1;
    for(auto it: adjLS[node]) {
        if(!vis[it.first]) {
            topoSortDFS(it.first, vis, st,adjLS);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int n, int m, vector<vector<int>>& graph) {
    vector<pair<int,int>> adjLS[n];

    for(auto it: graph) {
        adjLS[it[0]].push_back({it[1],it[2]}); // {{neighbour,edgeWeight},{neighbour,edgeWeight},{},...,{}}
    }

    vector<int> vis(n,0);

    // 1) Apply topo sort and form the stack
    stack<int> st;
    for(int i=0;i<n; i++) {
        if(!vis[i]) {
            topoSortDFS(i,vis,st,adjLS);
        }
    }
    
    // 2) Take the nodes out of the stack and relax the edges

    int src = 0;
    vector<int> dist(n,1e9);
    dist[src] = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        for(auto it: adjLS[node]) {
            if((it.second + dist[node])<dist[it.first]) {
                dist[it.first] = it.second + dist[node];
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        if(dist[i]==1e9) dist[i]=-1;
    }

    return dist;

    // TC -> O (N+M) (for toposort) + O(N+M) (for 2nd step)

    // Intuition for topoSort is that it allows us to go to every node by means of reachability. By having a defined path for our src node, we have all the information we need to reach a node from previous nodes, thus it reduces the total number of steps, thus giving smallest time complexity.
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
