#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void dfs(int node, vector<int>& vis, vector<int> adjLS[], stack<int>& st) {
    vis[node] = 1;
    for(auto it: adjLS[node]) {
        if(!vis[it]) {
            dfs(it,vis,adjLS,st);
        }
    }
    st.push(node);
}

void dfs3(int node,vector<int>& vis, vector<int> adjT[], vector<int>& component) {
    vis[node] = 1;
    component.push_back(node);
    for(auto it: adjT[node]) {
        if(!vis[it]) {
            dfs3(it,vis,adjT,component);
        }
    }
}
int kosaraju(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> adjLS[n];

    // Making of Adjacency list
    // O(V+E)
    for(int i=0; i<n; i++) {
        for(auto it: adj[i]) {
            adjLS[i].push_back(it);
        }
    }

    vector<int> vis(n,0);
    stack<int> st;
    // Step-1) Perform a dfs traversal and store the nodes according to finishing time.
    // O(V+E)
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i,vis,adjLS,st);
        }
    }

    // Step-2) Reverse the graph and reset the visited array
    // O(V+E)
    vector<int> adjT[n];
    for(int i=0; i<n; i++) {
        vis[i] = 0;
        for(auto it: adjLS[i]) {
            // i -> it
            adjT[it].push_back(i);
            // it -> i
        }
    }

    // Step-3) Perform dfs and get the count
    // O(V+E)
    vector<vector<int>> scc;
    int cnt=0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            scc.push_back({}); // Whenever we find a new starting node, we create a new SCC
            dfs3(node,vis,adjT,scc[cnt]);
            cnt++;
        }
    }

    return cnt;

    // TC -> O(V+E)
    // SC -> O(E)
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

    // Strongly Connected Components (SCC):-

    // Algorithm:- Kosaraju's Algorithm
    // Types of questions:- No. of SCC, Print the SCC
    // Only valid of Directed Graphs.
    // SSC stands for that component or part of graph where every node is reachable to every other node of that component.
    // The intuition for finding the number of SCCs is to reverse all the edges, so that we make sure that dfs traversal from one SCC to another gets broken but still the DFS tarversal within the SCC remains unaffected

    // Procedure of Kosaraju's Algorithm:
    // 1) Sort all the edges according to finishing time
    // 2) Reverse the graph
    // 3) Do a DFS

    return 0;
}
