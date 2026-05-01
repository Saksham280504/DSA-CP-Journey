#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// This is a classic Minimum Spanning Tree (MST) problem.
// Each point = node
// Cost between points = Manhattam Distance
// We need to connect all nodes with minimum possible cost -> Core intuition of MST
// For MST we either use Prim's Algorithm (Optimal) or Kruskal + DSU
// Prim's algorithm gives us an optimal solution because we don't store all the edges, whereas we compute distances on the fly.
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n,INT_MAX);
        vector<bool> vis(n,false);
        minDist[0] = 0;
        int cost = 0;

        for(int i=0; i<n; i++) {
            int u = -1;

            // 1. Find closest unvisited node
            for(int j=0; j<n; j++) {
                if(!vis[j] && (u==-1 || minDist[j]<minDist[u])) {
                    u = j;
                }
            }
            vis[u] = 1;
            cost += minDist[u];

            // 2. Update distances
            for(int j=0; j<n; j++) {
                if(!vis[j]) {
                    int dis = abs(points[j][0]-points[u][0]) + abs(points[j][1]-points[u][1]);
                    minDist[j] = min(minDist[j],dis);
                }
            }
        }

        return cost;
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
