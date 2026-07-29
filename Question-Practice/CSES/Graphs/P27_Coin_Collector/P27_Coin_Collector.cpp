#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

int n,m;
vector<vector<int>> adjLS, adjLSRev, sccGraph;
vector<int> value, component, order;
vector<bool> vis;
stack<int> finishOrder;
vector<ll> compSum;

void dfs1(int node) {
    vis[node] = true;
    for(int adj: adjLS[node]) {
        if(!vis[adj]) dfs1(adj);
    }
    finishOrder.push(node);
}

void dfs2(int node, int compID, long long &sum) {
    component[node] = compID;
    sum += value[node];
    for(int adj: adjLSRev[node]) {
        if(component[adj]==-1) dfs2(adj,compID,sum);
    }
}

void createCondensedGraph(int NumOfComps) {
    sccGraph.resize(NumOfComps);
    for(int u=1; u<=n; u++) {
        for(int v: adjLS[u]) {
            if(component[u]!=component[v]) sccGraph[component[u]].push_back(component[v]);
        }
    }
}

void findTopologicalOrder(int NumOfComps) {
    vector<int> inDegree(NumOfComps,0);
    for(int i=0; i<NumOfComps; i++) {
        for(int v: sccGraph[i]) {
            inDegree[v]++;
        }
    }
    queue<int> q;
    for(int i=0; i<NumOfComps; i++) {
        if(!inDegree[i]) q.push(i); 
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(int v: sccGraph[u]) {
            inDegree[v]--;
            if(!inDegree[v]) q.push(v);
        }
    }
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

    cin >> n >> m;
    value.assign(n+1,0);
    for(int i=1; i<=n; i++) cin >> value[i];

    adjLS.resize(n+1);
    adjLSRev.resize(n+1);
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adjLS[u].push_back(v);
        adjLSRev[v].push_back(u);
    }

    vis.assign(n+1,false);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs1(i);
    }

    component.resize(n+1,-1);
    int CompID = 0;
    compSum.clear();
    while(!finishOrder.empty()) {
        int u = finishOrder.top();
        finishOrder.pop();
        if(component[u]==-1) {
            ll sum = 0;
            dfs2(u,CompID++,sum);
            compSum.push_back(sum);
        }

    }
    int NumOfComps = CompID;

    createCondensedGraph(NumOfComps);
    findTopologicalOrder(NumOfComps);

    vector<ll> dp(NumOfComps,0);

    for(int u : order) {
        dp[u] += compSum[u];
        for(int v: sccGraph[u]) {
            dp[v] = max(dp[v],dp[u]);
        }
    } 
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
