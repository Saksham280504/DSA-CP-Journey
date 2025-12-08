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

    int FindUlP(int node) {
        if(node==parent[node]) return node;
        return parent[node] = FindUlP(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = FindUlP(u);
        int ulp_v = FindUlP(v);
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
        int ulp_u = FindUlP(u);
        int ulp_v = FindUlP(v);
        if(ulp_u==ulp_v) return;
        else if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int maxRow = -1;
    int maxCol = -1;

    // O(N)
    for(auto it: stones) {
        int row = it[0];
        int col = it[1];
        maxRow = max(maxRow,row);
        maxCol = max(maxCol,col);
    }
    // Total number of nodes for disjoint set = maxRow + maxCol + 1
    DisjointSet ds(maxRow+maxCol+2); // for safety
    unordered_map<int,int> stoneNodes;

    // O(N*4*alpha) -> O(N)
    for(auto it: stones) {
        int nodeRow = it[0]; // ranges from 0 to maxRow
        int nodeCol = it[1]+maxRow+1; // ranges from maxRow + 1 to maxRow+1+maxCol
        ds.unionBySize(nodeRow,nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int nc = 0;
    // O(N*4*alpha) -> O(N)
    for(auto it: stoneNodes) {
        if(ds.FindUlP(it.first)==it.first) nc++;
    }

    // From each component we get one stone which can't removed, thus for nc components we will get nc stones which can't be removed, thus the ones that can be removed will be = n-nc
    return n-nc;

    // TC -> O(N)
    // SC -> O(2N) (size & parent array)
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

    return 0;
}
