#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<vector<pair<int,int>>> adjLS;
vector<bool> seen;
vector<int> deg;
vector<int> path;

void dfs(int node) {
    while(!adjLS[node].empty()) {
        auto nei = adjLS[node].back();
        adjLS[node].pop_back();
        if(seen[nei.second]) continue;
        seen[nei.second] = true;
        dfs(nei.first);
    }
    path.push_back(node); // Backtracked path, will print in reverse
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
    deg.assign(n+1,0);
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adjLS[u].push_back({v,i});
        adjLS[v].push_back({u,i});
        deg[u]++;
        deg[v]++;
    }

    for(int i=1; i<=n; i++) {
        if(deg[i]&1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    seen.assign(m,false);
    path.clear();
    dfs(1);
    
    if(path.size()!=(m+1)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i=path.size()-1; i>=0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
