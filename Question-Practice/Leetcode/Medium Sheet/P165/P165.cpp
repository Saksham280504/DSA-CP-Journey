#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n<=2) {
            vector<int> res;
            for(int i=0; i<n; i++) res.push_back(i);
            return res;
        }
        vector<vector<int>> adjLS(n);
        vector<int> degree(n,0);
        for(auto &edge: edges) {
            int u = edge[0], v = edge[1];
            adjLS[u].push_back(v);
            adjLS[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> leaves;
        for(int i=0; i<n; i++) {
            if(degree[i]==1) leaves.push(i);
        }
        int remaining_nodes = n;
        while(remaining_nodes>2) {
            int numOfLeaves = leaves.size();
            remaining_nodes -= numOfLeaves;
            while(numOfLeaves--) {
                int leaf = leaves.front();
                leaves.pop();
                for(int v: adjLS[leaf]) {
                    if(--degree[v]==1) leaves.push(v);
                }
            }
        }
        vector<int> res;
        while(!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }
        return res;
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
