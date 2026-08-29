#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int startX = start[0], startY = start[1], targetX = target[0], targetY = target[1];
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // {cost, road_idx}
        int n = specialRoads.size();
        vector<int> dist(n,INT_MAX);
        for(int i=0; i<n; i++) {
            int cost = abs(startX-specialRoads[i][0]) + abs(startY-specialRoads[i][1]) + specialRoads[i][4]; // We are considering the cost of reaching specialRoads[i][2] and specialRoads[i][3] from startX,startY.
            pq.push({cost,i});
        }
        int ans = abs(startX-targetX) + abs(startY-targetY);
        while(!pq.empty()) {
            auto [dis, road_idx] = pq.top();
            pq.pop();
            if(dis>dist[road_idx]) continue;
            int ux = specialRoads[road_idx][2], uy = specialRoads[road_idx][3];
            ans = min(ans,dis+abs(ux-targetX)+abs(uy-targetY));
            for(int v=0; v<n; v++) {
                int distV = dis + abs(ux-specialRoads[v][0]) + abs(uy-specialRoads[v][1]) + specialRoads[v][4];
                if(distV<dist[v]) {
                    dist[v] = distV;
                    pq.push({distV,v});
                }
            }
        }
        return ans;
    }

    // Intuition: Instead of traversing through an infinite grid, we will create our own graph with nodes as start, target and special roads nodes. We will use classic djikstra's algo here as now it is simple cheapest route path algorithm in non-negative weighted graph
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
