#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool dfs(int node, int color, vector<int>& colors,vector<int> adjLS[]) {
    colors[node] = color;

    for(auto it: adjLS[node]) {
        if(colors[it]==-1) {
            if(color==0) {
                if(dfs(it,1,colors,adjLS)==false) return false;
            }
            else if(dfs(it,0,colors,adjLS)==false) return false;
        }
        else if(colors[it]==color) return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> adjLS[n];

    for(int i=0; i<n; i++) {
        int m = grid[i].size();
        for(int j=0; j<m; j++) {
            adjLS[i].push_back(grid[i][j]);
        }
    }

    vector<int> colors(n,-1);

    for(int i=0; i<n; i++) {
        if(colors[i]==-1) {
            if(dfs(i,0,colors,adjLS)==false) return false;
        }
    }

    return true;

    // // Every graph which has a cycle with odd number of nodes will never be bipartite.
    // // Other than that all the graphs are bipartite.
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
