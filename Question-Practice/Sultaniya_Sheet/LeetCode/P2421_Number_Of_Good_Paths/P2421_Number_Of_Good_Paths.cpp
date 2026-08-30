#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int find(vector<int>& parent, int node) {
        return (parent[node]==node) ? parent[node] : parent[node] = find(parent,parent[node]);
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<int> adjLS[n];
        for(auto &e: edges) {
            adjLS[e[0]].push_back(e[1]);
            adjLS[e[1]].push_back(e[0]);
        }
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        int good_paths = 0;
        map<int,vector<int>> mpp;
        for(int i=0; i<n; i++) {
            mpp[vals[i]].push_back(i);
        }
        for(auto [val,nodes]: mpp) {
            for(int u: nodes) {
                for(int v: adjLS[u]) {
                    if(vals[v]<=vals[u]) {
                        parent[find(parent,u)] = find(parent,v);
                    }
                }
            }
            unordered_map<int,int> root_count;
            for(int u:nodes) { // The u's have same values, so if they have the same parent, that means there is a valid path between them, thus put them under the same root.
                root_count[find(parent,u)]++;
            }
            for(auto [root,count]:root_count) {
                good_paths += (count*(count+1))/2; // nC2 + n (as single nodes are also valid paths)
            }
        }
        return good_paths;
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
