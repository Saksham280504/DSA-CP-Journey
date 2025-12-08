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
vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){
    vector<int> ans;
    int cnt = 0;
    DisjointSet ds(n*m);
    vector<vector<int>> vis(n,vector<int>(m,0));

    // O(Num of operations*4)
    for(auto it: A) {
        int row = it[0];
        int col = it[1];
        if(vis[row][col]) {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        int node = row*m+col;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            int nnode = nrow*m + ncol;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m) {
                if(vis[nrow][ncol] && ds.findUPar(nnode)!=ds.findUPar(node)) {
                    cnt--;
                    ds.unionByRank(nnode,node);
                }
            }
        }
        ans.push_back(cnt);
    }

    return ans;

    // TC -> O(Num of operations*4)
    // SC -> O(N*M) (visited array) + O(2*N*M) (parent,rank)
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
