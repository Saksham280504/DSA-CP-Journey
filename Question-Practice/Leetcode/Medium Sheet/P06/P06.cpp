#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adjLS[n];
        for(auto e: edges) {
            int u = e[0], v = e[1], w = e[2];
            adjLS[u].push_back({v,w});
            adjLS[v].push_back({u,2*w});
        }

        // Doing this allowed us to convert the problem from a single-way directed graph with switches to a double-way directed graph, which makes the problem now much more easy to solve.

        vector<long long> dist(n,LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq; // This is min heap, therefore it will always remove the node with the smallest distance first allowing us to find the minimum path sum.
        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()) {
            auto [d,u] = pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto &[v,w]: adjLS[u]) {
                if(d+w>=dist[v])continue;
                dist[v] = d + w;
                pq.push({dist[v],v});
            }
        }

        return dist[n-1] == LLONG_MAX ? -1 : dist[n-1];
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
