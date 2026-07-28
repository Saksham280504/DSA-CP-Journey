#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<bool> vis;

void dfs(int node, vector<int> adjLS[]) {
    vis[node] = true;
    for(int adj: adjLS[node]) {
        if(!vis[adj]) dfs(adj,adjLS);
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
    vector<int> adjLS[n+1];
    vector<int> adjLSReverse[n+1];
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adjLS[u].push_back(v);
        adjLSReverse[v].push_back(u);
    }

    vis.assign(n+1,false);
    dfs(1,adjLS);

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }

    fill(vis.begin(), vis.end(), false);

    dfs(1,adjLSReverse);

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
