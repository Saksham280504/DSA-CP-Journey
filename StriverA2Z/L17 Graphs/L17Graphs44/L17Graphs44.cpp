#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
class DisjointSet {
    vector<int> rank,size,parent;
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
int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);
    int extraConnections = 0;
    for(auto it: connections) {
        int u = it[0];
        int v = it[1];
        if(ds.findUPar(u)!=ds.findUPar(v)) {
            ds.unionBySize(u,v);
        }
        else {
            extraConnections++;
        }
    }

    int nc = 0;
    for(int i=0; i<n; i++) {
        if(ds.findUPar(i)==i) nc++;
    }

    if((nc-1)<=extraConnections) return nc-1;
    return -1;

    // TC -> O(E*4*alpha) + O(N) -> O(E) + O(N)
    // SC -> O(2N) (size and parent arrray)
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
