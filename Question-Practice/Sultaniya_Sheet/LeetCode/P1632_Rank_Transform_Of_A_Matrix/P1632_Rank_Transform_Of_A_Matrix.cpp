#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int find(vector<int>& parent, int i) { // Compression
        return (parent[i]==i) ? parent[i] : parent[i] = find(parent,parent[i]);
    }
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<int,vector<pair<int,int>>> mpp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                mpp[matrix[i][j]].push_back({i,j});
            }
        }
        // This groups all the cells in ascending order of the values they are holding

        vector<int> rank(m+n,0);
        vector<vector<int>> ans(m,vector<int>(n));
        for(auto [val,cells]: mpp) {
            vector<int> parent(m+n);
            iota(parent.begin(), parent.end(), 0);
            auto root = [&](int i) { // Lambda function
                return find(parent,i);
            };
            for(auto &cell: cells) { // Grouping of all cells under one connected component
                int i = cell.first, j = cell.second;
                parent[root(i)] = root(j+n);
            }
            vector<int> current_rank = rank;
            for(auto &cell: cells) {
                int i = cell.first, j = cell.second;
                int r = root(i);
                current_rank[r] = max({current_rank[r],rank[i],rank[j+n]});
            }
            for(auto &cell: cells) {
                int i = cell.first, j = cell.second;
                int r = root(i);
                ans[i][j] = rank[i] = rank[j+n] = current_rank[r]+1;
            }
        }
        return ans;
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
