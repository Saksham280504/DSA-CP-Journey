#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& check, vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it: graph[node]) {
        if(!vis[it]) {
            if(dfsCheck(it,graph,check,vis,pathVis)==false) return false;
        }
        else if(pathVis[it]) return false;
    }
    pathVis[node] = 0;
    check[node]=1;
    return true;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    // This is DFS Method
    int n = graph.size();
    vector<int> vis(n,0);
    vector<int> pathVis(n,0);
    vector<int> check(n,0);
    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfsCheck(i,graph,check,vis,pathVis);
        }
    }
    for(int i=0; i<n; i++) {
        if(check[i]==1) ans.push_back(i); 
    }
    return ans;

    // TC -> O(N+E) (dfs traversal for directed graph)
    // SC -> O(3N)  (vis,pathVis,check) + O(N) (worst-case for recursion stack-space)
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    // This is BFS Method
    int n = graph.size();
    vector<int> adjLS[n];

    // 1) Reverse the graph
    // i->it
    for(int i=0; i<n; i++) {
        for(auto it: graph[i]) {
            adjLS[it].push_back(i); // it-> i
        }
    }

    // 2) Look for indegree for reversed graph   
    vector<int> indegree(n,0);
    for(int i=0; i<n; i++) {
        for(auto it: adjLS[i]) {
            indegree[it]++;
        }
    }

    //3) Find the topological sorted listing for the reversed graph
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indegree[i]==0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adjLS[node]) {
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }

    sort(topo.begin(),topo.end());

    return topo; // This topologically sorted will have all the safe nodes!!

    // TC -> O(N+E) (bfs traversal for directed graph) + O(NLogN) (sorting)
    // SC -> O(extra space due to adjLS) + O(N) (indegree) + O(N) (worst-case for queue)
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
