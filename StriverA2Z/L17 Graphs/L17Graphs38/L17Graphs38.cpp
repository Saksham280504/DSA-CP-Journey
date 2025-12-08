#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // 1. Formation of adjLS
    vector<pair<int,int>> adjLS[n];
    for(auto it: times) {
        int u = it[0]-1;
        int v = it[1]-1;
        int wt = it[2];
        adjLS[u].push_back({v,wt});
    }
    // 2. Formation of pq and dist array
    vector<int> dist(n,1e8); // store min time
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {time,node}
    int src = k-1;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()) {
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto adj: adjLS[node]) {
            int adjNode = adj.first;
            int edgW = adj.second;
            if(time+edgW < dist[adjNode]) {
                dist[adjNode] = time + edgW;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    int maxi = INT_MIN;
    for(int i=0; i<n; i++) {
        if(dist[i]==1e8) return -1;
        maxi = max(maxi,dist[i]);
    }
    return maxi;

    // TC -> O(ElogV) (dijkstra's traversal) + O(N) (for gettting min time)
    // SC -> O(N) (worst case for queue space) + O(N) (dist array)
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
