#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,ll>> adjLS[n+1];
    for(int i=0; i<m; i++) {
        int u,v;
        ll wt;
        cin >> u >> v >> wt;
        adjLS[u].push_back({v,wt});
    }
    vector<ll> dist[n+1];
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0,1});
    while(!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();
        if(dist[node].size()>=k) continue;
        dist[node].push_back(currDist);
        for(auto adj: adjLS[node]) {
            pq.push({adj.second+currDist,adj.first});
        }
    }

    for(ll x: dist[n]) cout << x << " ";
    cout << endl;

    return 0;
}
