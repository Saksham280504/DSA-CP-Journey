#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    int dfs(int node, vector<bool>& vis, vector<pair<int,int>> adjLS[]) {
        vis[node] = true;
        int changes = 0;
        for(auto adj: adjLS[node]) {
            int neighbour = adj.first;
            int cost = adj.second;
            if(!vis[neighbour]) changes += cost + dfs(neighbour, vis, adjLS);
        }
        return changes;
    }
    public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> adjLS[n];
        for(auto &e: connections) {
            int u = e[0], v = e[1];
            adjLS[u].push_back({v,1});
            adjLS[v].push_back({u,0});
        }
        vector<bool> vis(n,false);
        return dfs(0,vis,adjLS);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
