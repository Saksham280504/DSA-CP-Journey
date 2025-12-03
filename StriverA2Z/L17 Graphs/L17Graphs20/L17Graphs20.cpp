#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void dfs(int node, vector<int>& vis, stack<int>& stk, vector<int> adjLS[]) {
    vis[node] = 1;
    for(auto it: adjLS[node]) {
        if(!vis[it]) dfs(it,vis,stk,adjLS);
    }
    stk.push(node);
}
vector<int> topoSort(int n, vector<int> adjLS[]) {
    vector<int> vis(n,0);
    stack<int> stk;
    for(int i=0; i<n; i++) {
      if(!vis[i]) {
        dfs(i,vis,stk,adjLS);
      }
    }

    vector<int> arr;

    while(!stk.empty()) {
        arr.push_back(stk.top());
        stk.pop();
    }

    return arr;

    // TC -> O(N+E)
    // SC -> O(3N) (vis,stack,arr) + O(N) (worst-case of recursion stack-space i.e. when it is a linear directed graph)
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

    // From here, we start the Topological Sort Algorithm section.
    // Topological Sort can only be applied on DAG (Directed Acyclic Graphs).
    // Topological Sort can be defined as a linear ordering of vertices such that if there is an edge between u & v, then u appears before v in that ordering.

    int n,m;
    cin >> n >> m;
    vector<int> adjLS[n];

    for(int i=0; i<m; i++) {
        int u,v; 
        cin >> u >> v;
        adjLS[u].push_back(v);
    }

    vector<int> ans = topoSort(n,adjLS);

    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
