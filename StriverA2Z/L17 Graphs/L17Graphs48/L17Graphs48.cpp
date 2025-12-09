#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class DisjointSet {
    public:
    vector<int> rank, size, parent;
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<n; i++) {
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
int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    DisjointSet ds(n*m);
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};

    // Finding the size of already present islands
    for(int row=0; row<n; row++) {
        for(int col=0; col<m; col++) {
            if(grid[row][col]==1) {
                int node = row*m+col;
                for(int k=0; k<4; k++) {
                    int nrow = row + delrow[k];
                    int ncol = col + delcol[k];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m) {
                        int nnode = nrow*m + ncol;
                        if(grid[nrow][ncol]==1 && ds.findUPar(nnode)!=ds.findUPar(node)) {
                            ds.unionBySize(nnode,node);
                        }
                    }
                }
            }
        }
    }

    int maxSize = INT_MIN;
    for(int i=0; i<((m*n)+1); i++) {
        maxSize = max(ds.size[i],maxSize);
    }
    for(int row=0; row<n; row++) {
        for(int col=0; col<m; col++) {
            if(grid[row][col]==0) {
                int size = 1;
                set<int> st;
                for(int k=0; k<4; k++) {
                    int nrow = row + delrow[k];
                    int ncol = col + delcol[k];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m) {
                        if(grid[nrow][ncol]==1) {
                            int nnode = nrow*m+ncol;
                            st.insert(ds.findUPar(nnode));
                        }
                    }
                }
                for(auto it: st) {
                    size += ds.size[it];
                }
                maxSize = max(maxSize,size);
            }
        }
    }

    return maxSize;

    // TC -> O(N*M*4)
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
