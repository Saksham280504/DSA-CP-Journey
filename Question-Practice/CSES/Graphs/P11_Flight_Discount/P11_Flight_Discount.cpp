#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
typedef pair<int,ll> pill;
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
    vector<pill> adjLS[n+1];
    for(int i=0; i<m; i++) {
        int u,v;
        ll wt;
        cin >> u >> v >> wt;
        adjLS[u].push_back({v,wt});
    }
    vector<vector<ll>> dist(n+1,vector<ll>(2,LLONG_MAX));
    dist[1][0] = 0;
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> pq; // {currDist, {node, state}}
    pq.push({0,1,0}); 

    while(!pq.empty()) {
        auto [currDist, node, used] = pq.top();
        pq.pop();
        if(currDist>dist[node][used]) continue;
        if(!used) {
            for(auto adj: adjLS[node]) {
                int v = adj.first;
                ll wt = adj.second;
                if(dist[v][0]>dist[node][0]+wt) {
                    dist[v][0] = dist[node][0]+wt;
                    pq.push({dist[v][0],v,0});
                }
                if(dist[v][1] > dist[node][0]+wt/2) {
                    dist[v][1] = dist[node][0] + wt/2;
                    pq.push({dist[v][1],v,1});
                }
            }
        }
        else {
            for(auto adj: adjLS[node]) {
                int v = adj.first;
                ll wt = adj.second;
                if(dist[v][1]>dist[node][1]+wt) {
                    dist[v][1] = dist[node][1] + wt;
                    pq.push({dist[v][1],v,1});
                }
            }
        }
    }

    cout << dist[n][1] << endl;

    // TC -> O((N+M)*log(N))
    // SC -> O(max(N+M,2*N))
    return 0;
}
