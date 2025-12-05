#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int findCheapestPrice(int n,vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int,int>> adjLS[n];
    for(auto it: flights) {
        adjLS[it[0]].push_back({it[1],it[2]});
    }

    queue<pair<int,pair<int,int>>> q; // Here we don't need a priority queue because we are using stops as the priority factor and not the cost, and since stops increases level-wise we see that priority queue will not be needed.

    vector<int> cost(n,1e9);
    cost[src] = 0; // stores the cheapest price from src to ith city
    
    // {stops,{node,price}}
    q.push({0,{src,0}});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int price = it.second.second;
        if(stops>k) continue;
        for(auto adj: adjLS[node]) {
            int adjNode = adj.first;
            int edgeW = adj.second;
            if(price+edgeW<cost[adjNode] && stops<=k) {
                cost[adjNode] = price + edgeW;
                q.push({stops+1,{{adjNode},cost[adjNode]}});
            }
        }
    }
    // We will complete the entire queue and not break it at any moment!!

    if(cost[dst]==1e9) return -1;
    return cost[dst];

    // TC -> O(E) and not O(ElogV) as we are using queue and not priority queue, thus TC -> O(E) -> O(flights.size())
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
