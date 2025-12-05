#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int,int>> adjLS[n];
    for(auto it: roads) {
        adjLS[it[0]].push_back({it[1],it[2]});
        adjLS[it[1]].push_back({it[0],it[2]});
    }

    vector<int> ways(n,0);
    vector<long long> dist(n,1e18);

    // {dis,node}
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,0});
    dist[0] = 0;
    ways[0] = 1;
    long long mod = (1e9+7);
    
    while(!pq.empty()) {
        auto [dis,node] = pq.top();
        pq.pop();

        for(auto adj: adjLS[node]) {
            int adjNode = adj.first;
            long long edgW = adj.second;

            // this is the first time I am coming with this short distance
            if(dis + edgW < dist[adjNode]) {
                dist[adjNode] = dis + edgW;
                ways[adjNode] = ways[node];
                pq.push({dist[adjNode],adjNode});
            }

            // I have got this distance before
            else if(dis+edgW==dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node])%mod;
            }
        }
    }
    return ways[n-1];

    // TC ->O(ElogV) (dijkstra's traversal)
    // SC -> O(2N) (dist,ways) + O(Heap-size) -> O(2N) + O(N*N) (for the worst case)
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
