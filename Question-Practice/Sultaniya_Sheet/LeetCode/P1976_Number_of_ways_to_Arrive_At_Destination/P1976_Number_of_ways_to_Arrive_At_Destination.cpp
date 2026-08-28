#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

// class Solution {
// public:
// int countPaths(int n, vector<vector<int>>& roads) {

//     // 1. Create Adjacency List
//     vector<pair<int,int>> adjLS[n];
//     for(auto road: roads) {
//         adjLS[road[0]].push_back({road[1],road[2]});
//         adjLS[road[1]].push_back({road[0],road[2]});
//     }
    
//     // 2. Create dist, ways
//     vector<long long> dist(n,1e18); // Stores the minimum distance to reach any node from 0
//     vector<int> ways(n,0); // Stores the number of ways to reach node from 0 with minimum distance
    
//     // 3. Create priority queue -> {dis,node}
//     priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<>> pq;
//     pq.push({0,0});
//     dist[0] = 0;
//     ways[0] = 1;
//     int mod = 1e9+7;

//     // Calculation of distance + ways
//     while(!pq.empty()) {
//         long long dis = pq.top().first;
//         int node = pq.top().second;
//         pq.pop();
//         for(auto adj: adjLS[node]) {
//             int adjNode = adj.first;
//             int edgW = adj.second;
//             if(dis + edgW < dist[adjNode]) {
//                 dist[adjNode] = dis + edgW;
//                 ways[adjNode] = ways[node];
//                 pq.push({dist[adjNode],adjNode});
//             }
//             else if(dis + edgW == dist[adjNode]) {
//                 ways[adjNode] = (ways[adjNode]+ways[node])%mod;
//             }
//         }
//     }

//     return ways[n-1];

//     // TC -> O(ElogV) (djikstra's algorithm)
//     // SC -> O(2N) (dist,ways) + O(Heap-size) -> O(2N) + O(N*N) (worst-case)
// }
// };

class Solution {
public:
int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, ll>> adjLS[n];
    for(auto road: roads) {
        adjLS[road[0]].push_back({road[1],(ll)road[2]});
        adjLS[road[1]].push_back({road[0],(ll)road[2]});
    }

    vector<ll> dist(n,1e18); // dist[i] -> minimum distance needed to reach node i
    vector<int> ways(n,0); // ways[i] -> number of ways to reach node i with dist[i]
    int mod = 1e9+7;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq; // {dist,node}
    pq.push({0LL,0});
    dist[0]= 0LL;
    ways[0] = 1;
    while(!pq.empty()) {
        auto [dis, node] = pq.top();
        pq.pop();
        if(dist[node]<dis) continue;
        for(auto [adjNode, edgW]: adjLS[node]) {
            if(dis + edgW < dist[adjNode]) {
                dist[adjNode] = dis + edgW;
                ways[adjNode] = ways[node];
                pq.push({dist[adjNode],adjNode});
            }
            else if(dis + edgW == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode]+ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;

    // TC -> O(ElogV) (djikstra's algorithm)
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
