#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<bool> vis;
void dfs(int node, vector<int> adjLS[]) {
    vis[node] = true;
    for(auto adj: adjLS[node]) {
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
    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }
    vis.assign(n+1,false);
    vector<int> Components;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            Components.push_back(i);
            dfs(i,adjLS);
        }
    }
    cout << Components.size()-1 << endl;
    for(int i=1; i<Components.size(); i++) {
        cout << Components[0] << " " << Components[i] << endl;
    }

    // TC -> O(V+2*E) (Undirected Graph)
    // SC -> O(V+2*E) (Undirected Graph)

    return 0;
}
