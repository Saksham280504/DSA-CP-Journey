#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        // We apply 2 phase tree pruning using topological sorting (Kahn's algorithm) to finally remain with only the needed edges to pass over twice in order to start from any index, collect all coins and come back to the starting node with minimum edges.

        int n = coins.size();
        vector<unordered_set<int>> graph(n); // we use a set and not a vector, to maintain a dynamic graph
        vector<int> degree(n,0);

        for(auto &e: edges) {
            int u = e[0];
            int v = e[1];
            graph[u].insert(v);
            graph[v].insert(u);
            degree[u]++;
            degree[v]++;
        }

        // Phase-1: Prune all leaf nodes with no coins
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(degree[i]==1 && coins[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            degree[u]--;
            for(int v: graph[u]) {
                if(degree[v]>0) {
                    graph[v].erase(u); // This is the reason we use set
                    degree[v]--;
                    if(degree[v]==1 && coins[v]==0) q.push(v);
                }
            }
        }

        // Phase-2: Prune 2 layers of remaining leaves
        queue<int> leaf_q;
        for(int i=0; i<n; i++) {
            if(degree[i]==1) leaf_q.push(i);
        }
        for(int layer=0; layer<2; layer++) {
            int sz = leaf_q.size();
            while(sz--) {
                int u = leaf_q.front();
                leaf_q.pop();
                degree[u]--;
                for(int v: graph[u]) {
                    if(degree[v]>0) {
                        graph[v].erase(u);
                        degree[v]--;
                        if(degree[v]==1) leaf_q.push(v);
                    }
                }
            }
        }

        // All the remaining edges must be traversed and that too twice, in order to obtain all coins, return back to starting node and that too with minimum edges

        int remEdges = 0;
        for(auto &e: edges) {
            int u = e[0];
            int v = e[1];
            if(degree[u] && degree[v]) remEdges++;
        }
        return remEdges*2;
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
