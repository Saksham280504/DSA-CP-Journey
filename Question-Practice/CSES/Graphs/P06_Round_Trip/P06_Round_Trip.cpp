#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int n,m;
vector<vector<int>> adjLS;
vector<int> parent;
vector<bool> vis;
int cycle_start = -1, cycle_end;

bool dfs(int node) {
    vis[node] = true;
    for(int adj: adjLS[node]) {
        if(adj==parent[node]) continue;
        if(vis[adj]) {
            cycle_start = adj;
            cycle_end = node;
            return true;
        }
        else {
            parent[adj] = node;
            if(dfs(adj)) return true;
        }
    }
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
    cin >> n >> m;
    adjLS.resize(n+1);
    parent.assign(n+1,-1);
    vis.assign(n+1,false);

    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        if(!vis[i] && dfs(i)) break;
    }

    if(cycle_start==-1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    vector<int> cycle;
    cycle.push_back(cycle_start);
    int curr = cycle_end;
    while(curr!=cycle_start) {
        cycle.push_back(curr);
        curr = parent[curr];
    }
    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for(int x: cycle) cout << x << " ";
    cout << endl;

    return 0;
}
