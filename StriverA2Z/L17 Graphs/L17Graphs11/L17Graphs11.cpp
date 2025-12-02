#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool detect(int node,int parent, vector<int>& vis, vector<int> adjLS[]) {
    vis[node] = 1;
    for(auto it: adjLS[node]) {
        if(!vis[it]) {
            if(detect(it,node,vis,adjLS)) return true;
        }
        else if(it != parent) return true;
    }
    return false;
}
bool isCycle(int n, vector<int> adjLS[]) {
    vector<int> vis(n,0);
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            if(detect(i,-1,vis,adjLS)) return true;
        }
    }

    return false;

    // SC -> O(N) (recursion stack space) + O(N) (visited array)
    // TC -> O(N+2E) (for dfs traversal) + O(N) (outer for loop)

    // TC of DFS traversal => O(N+2E) (every node(N) is visited once thus O(N)). Now when we visit all the nodes, we go through the entire adjacency list where we cover all the edges twice (2E), thus making TC(DFS traversal) -> O(N+2E)
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
        adjLS[u].push_back(v);
        adjLS[v].push_back(u);
    }

    if(isCycle(n,adjLS)) {
        cout << "true" << endl;
    }
    else cout << "false" << endl;

    return 0;
}
