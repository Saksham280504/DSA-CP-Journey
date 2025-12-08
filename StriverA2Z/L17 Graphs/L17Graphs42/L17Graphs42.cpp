#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
class DisjointSet {
    // 1. Find ultimate parent of (u,v) => (pu,pv)
    // 2. Find rank of (pu,pv)
    // 3. Connect smaller rank to larger rank always.
    // When we get the ultimate parent of any node, we apply path compression due to which the tree size remains very small

    // TC (union) -> O(4*alpha) -> O(const)
    // TC (find_parent)) -> O(4*alpha) -> O(const)
    // This TC is for both unionByRank and unionBySize

    vector<int> rank, size, parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0); // Initially everyone are at the same level
        size.resize(n+1,1);
        parent.resize(n+1); // Initially the parent of everynode is itself
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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // Disjoint set (V.V.V.V Imp)

    // Need: BFS/DFS traversal took linear TC, whereas Disjoint set takes constant time.

    // Functionality: 1) Find Parent 2) Union (rank,size)

    // Initially we assume that all the nodes are single.
    // Then we connect two nodes, this is done by union. As we join any two nodes, the graph changes. Disjoint set allows us to check for components in constant time complexity at any point of time.

    // So in short whenever we are asked to check whether two nodes belong to the same component or not at any given time, we can answer that question in constant time Complexity using disjoint sets.

    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // check if 3 and 7 belong to the same component or not
    if(ds.findUPar(3)==ds.findUPar(7)) cout << "Same" << endl;
    else cout << "Not Same" << endl;

    ds.unionByRank(3,7);
    // check if 3 and 7 belong to the same component or not
    if(ds.findUPar(3)==ds.findUPar(7)) cout << "Same" << endl;
    else cout << "Not Same" << endl;

    // Q. Why do we connect from smaller to larger?
    // There are basically two reasons for this:-

    // 1. By attaching smaller to larger, we keep the tree size as smaller as possible.
    // 2. Secondly, we try to keep the time taken to find the ultimate parents minimal.

    // V.V.V. imp point of observation:- Any time we see dynamic connections taking place, that's where we use DisjointSet data structure.

    return 0;
}
