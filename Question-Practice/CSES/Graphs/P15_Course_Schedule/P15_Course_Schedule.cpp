#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
vector<vector<int>> adjLS;
vector<bool> vis;
vector<bool> recStack;
stack<int> order;
bool isCycle = false;

void dfs(int node) {
    vis[node] = true;
    recStack[node] = true;
    for(int adj: adjLS[node]) {
        if(!vis[adj]) dfs(adj);
        if(recStack[adj]) {
            isCycle = true;
            return;
        }
    }
    recStack[node] = false;
    order.push(node);
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

    int n,m;
    cin >> n >> m;
    adjLS.resize(n+1);
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adjLS[u].push_back(v);
    }

    // DFS Approach
    // vis.resize(n+1,false);
    // recStack.resize(n+1,false);
    // for(int i=1; i<=n; i++) {
    //     if(!vis[i]) dfs(i);
    // }
    // if(isCycle) {
    //     cout << "IMPOSSIBLE" << endl;
    //     return 0;
    // }
    // vector<int> result;
    // for(int i=1; i<=n; i++) {
    //     result.push_back(order.top());
    //     order.pop();
    // }
    // for(int x: result) cout << x << " ";
    // cout << endl;

    // BFS Approach
    vector<int> inDegree(n+1,0);
    for(int u=1; u<=n; u++) {
        for(int v: adjLS[u]) {
            inDegree[v]++;
        }
    }
    queue<int> q;
    for(int u=1; u<=n; u++) {
        if(inDegree[u]==0) q.push(u);
    }
    vector<int> order;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(int v: adjLS[u]) {
            inDegree[v]--;
            if(inDegree[v]==0) q.push(v);
        }
    }

    if(order.size()==n) {
        for(int x: order) cout << x << " ";
        cout << endl;
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}
