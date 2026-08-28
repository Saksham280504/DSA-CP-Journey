#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// class Solution {
//     private:
// bool dfs(int node, int color, vector<int>& colors,vector<vector<int>>& grid) {
//     colors[node] = color;

//     for(auto it: grid[node]) {
//         if(colors[it]==-1) {
//             if(dfs(it,!color,colors,grid)==false) return false;
//         }
//         else if(colors[it]==color) return false;
//     }
//     return true;
// }
// public:
// bool isBipartite(vector<vector<int>>& grid) {
//     int n = grid.size();

//     vector<int> colors(n,-1);

//     for(int i=0; i<n; i++) {
//         if(colors[i]==-1) {
//             if(dfs(i,0,colors,grid)==false) return false;
//         }
//     }

//     return true;

//     // // Every graph which has a cycle with odd number of nodes will never be bipartite.
//     // // Other than that all the graphs are bipartite.
// }
// };

class Solution {
private:
    bool dfs(int u, int c, vector<int>& color, vector<vector<int>>& grid) {
        color[u] = c;
        for(int v: grid[u]) {
            if(color[v]==color[u]) return false;
            if(color[v]==0) {
                if(!dfs(v,-c,color,grid)) return false;
            }
        }
        return true;
    }
public:
    // BFS Approach
    // bool isBipartite(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     vector<int> color(n,0);
    //     for(int i=0; i<n; i++) {
    //         if(color[i]!=0) continue;
    //         queue<int> q;
    //         q.push(i);
    //         color[i]=1;
    //         while(!q.empty()) {
    //             int u = q.front();
    //             q.pop();
    //             for(int v: grid[u]) {
    //                 if(color[v]==color[u]) return false;
    //                 if(color[v]==0) {
    //                     color[v] = -color[u];
    //                     q.push(v);
    //                 }
    //             }
    //         }
    //     }
    //     return true;
    // }

    // DFS Approach
    bool isBipartite(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> color(n,0);
        for(int i=0; i<n; i++) {
            if(color[i]==0) {
                if(!dfs(i,1,color,grid)) return false;
            }
        }
        return true;
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
