#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adjLS[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it: adjLS[node]) {
        if(!vis[it]) {
            if(dfs(it,vis,pathVis,adjLS)==true) return true;
        }
        else if(pathVis[it]) return true;
    }

    pathVis[node]=0;
    return false;
}
bool isCyclic(int n, vector<int> adjLS[]) {
    vector<int> vis(n,0);
    vector<int> pathVis(n,0);

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            if(dfs(i,vis,pathVis,adjLS)==true) return true;
        }
    }

    return false;
 
    // TC -> O(N+E) (bfs traversal for directed graph)
    // SC -> O(2N) (vis & pathvis array)
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
    vector<int> adjLS[n];

    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adjLS[u].push_back(v); // Directed Graph
    }

    if(isCyclic(n,adjLS)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}
