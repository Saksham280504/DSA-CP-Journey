#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int cycle_start = -1, cycle_end;
vector<vector<int>> adjLS;
vector<int> parent;
vector<bool> visited;
vector<bool> recStack;

bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;
    for(int adj: adjLS[node]) {
        if(!visited[adj]) {
            parent[adj] = node;
            if(dfs(adj)) return true;
        }
        else if(recStack[adj]) {
            cycle_end = node;
            cycle_start = adj;
            return true;
        }
    }
    recStack[node] = false;
    return false;
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
    parent.assign(n+1,-1);
    visited.assign(n+1,false);
    recStack.assign(n+1,false);

    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adjLS[u].push_back(v);
    }

    for(int i=1; i<=n; i++) {
        if(!visited[i] && dfs(i)) break;
    }

    if(cycle_start==-1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(cycle_start);
    for(int i=cycle_end; i!=cycle_start; i = parent[i]) cycle.push_back(i);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for(int x: cycle) cout << x << endl;
    return 0;
}
