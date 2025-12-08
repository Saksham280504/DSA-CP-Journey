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
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjointSet ds(n);
    map<string,int> mapMailNode;

    // to get the disjoint set and map of <mail,node>
    // O(N*M)
    for(int i=0; i<n; i++) {
        int m = accounts[i].size();
        for(int j=1; j<m; j++) {
            string mail = accounts[i][j];
            if(mapMailNode.find(mail)==mapMailNode.end()) {
                mapMailNode[mail] = i;
            }
            else {
                ds.unionByRank(i,mapMailNode[mail]);
            }
        }
    }

    // to generate list of array of mails
    // O(number of indepent mails) -> O(N*M) (worst case)
    vector<string> NodeMailList[n];
    for(auto it: mapMailNode) {
        string mail = it.first;
        int node = ds.findUPar(it.second);
        NodeMailList[node].push_back(mail);
    }

    // to generate ans
    // O(N +(N*M)log(N*M))
    vector<vector<string>> ans;
    for(int i=0; i<n; i++) {
        if(NodeMailList[i].size()==0) continue;
        sort(NodeMailList[i].begin(), NodeMailList[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it: NodeMailList[i]) {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }

    return ans;

    // TC -> O((N*M)(log(N*M))
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
