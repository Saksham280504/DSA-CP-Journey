#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
bool detect(int src, vector<int> adjLS[],vector<int>& vis) {
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push({src,-1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto adjacentNode: adjLS[node]) {
            if(!vis[adjacentNode]) {
                vis[adjacentNode] = 1;
                q.push({adjacentNode,node});
            }
            else if(parent != adjacentNode) return true; // If paths cross, then that means a cycle has been formed
        }
    }

    return false;
}
bool isCycle(int n, vector<int> adjLS[]) {
    vector<int> vis(n,0);
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            if(detect(i,adjLS,vis)) return true;
        }
    }

    return false;

    // TC -> O(N) (for loop) + O(2E) (we check the queue for the entire degree of the graph)
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

    return 0;
}
