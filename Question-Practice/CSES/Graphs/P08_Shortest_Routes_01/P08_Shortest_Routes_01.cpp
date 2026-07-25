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
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adjLS[n+1];
    for(int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adjLS[a].push_back({b,c});
    }
    vector<ll> dist(n+1,__LONG_LONG_MAX__);
    dist[1] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq; // {dist,node}
    pq.push({0LL,1});

    while(!pq.empty()) {
        auto [distance, node] = pq.top();
        pq.pop();
        if(distance>dist[node]) continue;
        for(auto [adj,edgW]: adjLS[node]) {
            ll currDist = edgW+distance;
            if(currDist<dist[adj]) {
                dist[adj] = currDist;
                pq.push({dist[adj],adj});
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    // TC -> O((N+M)*(log(N)))
    // SC -> O(N+M)

    return 0;
}
