#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
class DisjointSet {
    vector<int> rank, size, parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<n+1; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        else if(rank[ulp_u]<rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        else if(size[ulp_u]<size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int kruskalsMST(int n, vector<vector<int>> &edges) {
    // We are given an undirected graph with n nodes and m edges, and we are asked to generate a MST weight for this graph.
    // It doesn't matter if we have an undirected graph or not, our class of disjoint sets is created in such a way that no repition will ever occur.
    // We generate the mst using the disjoint class.
    
    // O(M)
    for(auto &it: edges) { // We need to tweek the actual edges array, that's why we use &it and not it (it-> copy, &it->reference)
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        it = {wt,u,v};
    }

    // O(MlogM)
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    int mstWt = 0;

    // O(M*4*alpha) -> O(M)
    for(auto it: edges) {
        int wt = it[0];
        int u = it[1];
        int v = it[2];  
        if(ds.findUPar(u)!=ds.findUPar(v)) {
            mstWt += wt;
            ds.unionBySize(u,v);
        }
    }

    // TC -> O(MlogM) + O(M) + O(M) -> O(MlogM)
    // SC -> O(2N) (parent and size array)
    return mstWt;
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

    // Kruskal's Algorithm:

    // Procedure:
    // 1. Sort all the edges according to weight.
    // 2. Now for every edge, check whether the nodes are a part of same component, if yes, then nothing needs to be done. If not, then that edge will be added to the mst.

    return 0;
}
