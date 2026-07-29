#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

stack<int> finishOrder;
vector<bool> vis;
vector<vector<int>> adjLS, adjLSRev;
void dfsOriginal(int node) {
    vis[node] = true;
    for(int adj: adjLS[node]) {
        if(!vis[adj]) dfsOriginal(adj);
    }
    finishOrder.push(node);
}

void dfsReverse(int u, vector<int>& component) {
    vis[u] = true;
    component.push_back(u);
    for(int adj: adjLSRev[u]) {
        if(!vis[adj]) dfsReverse(adj,component);
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

    int n,m;
    cin >> n >> m;
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
        if(!vis[i]) dfsOriginal(i);
    }

    vis.assign(n+1,false);
    vector<int> kingdom(n+1,0);
    int currLabel = 1;
    while(!finishOrder.empty()) {
        int u = finishOrder.top();
        finishOrder.pop();
        if(!vis[u]) {
            vector<int> component;
            dfsReverse(u,component);
            for(int v: component) {
                kingdom[v] = currLabel;
            }
            currLabel++;
        }
    }

    cout << currLabel-1 << endl;
    for(int i=1; i<=n; i++) {
        cout << kingdom[i] << " ";
    }
    cout << endl;

    return 0;
}
