#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adjLS[n];
        for(int i=0; i<m; i++) {
            adjLS[edges[i][0]-1].push_back({edges[i][1]-1,edges[i][2]});   
            adjLS[edges[i][1]-1].push_back({edges[i][0]-1,edges[i][2]}); // Undirected weighted graph
        }
        
        int src = 0;
        int destination = n-1;
        vector<int> dist(n,1e9);
        vector<int> parent(n);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        parent[src] = -1;
        pq.push({0,src});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto adj: adjLS[node]) {
                int edgeWeight = adj.second;
                int adjNode = adj.first;
                if(edgeWeight+dis<dist[adjNode]) {
                    parent[adjNode] = node;
                    dist[adjNode] = edgeWeight + dis;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        if(dist[destination]==1e9) {
            return {-1};
        }

        vector<int> ans;
        int pointer = destination;
        ans.push_back(pointer+1);
        while(pointer!=src) {
            ans.push_back(parent[pointer]+1);
            pointer = parent[pointer];
        }
        ans.push_back(dist[destination]);
        reverse(ans.begin(),ans.end());
        return ans;

        // TC -> O(ElogV) (for generation of dist array) + O(length of path for generating ans)
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

    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++) {
        vector<int> arr(3);
        for(int j=0; j<3; j++) {
            cin >> arr[j];
        }
        edges.push_back(arr);
    }

    vector<int> ans = shortestPath(n,m, edges);
    for(auto x: ans) cout << x << endl;

    return 0;
}
