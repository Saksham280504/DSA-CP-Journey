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
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n,vector<ll>(n,LLONG_MAX));
    for(int i=0; i<n; i++) dist[i][i] = 0;

    for(int i=0; i<m; i++) {
        int u,v;
        ll wt;
        cin >> u >> v >> wt;
        u--; v--;
        dist[u][v] = min(dist[u][v],wt); // There can be multiple edges between any two cities.
        dist[v][u] = min(dist[v][u],wt); 
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    while(q--) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        cout << (dist[a][b]==LLONG_MAX? -1: dist[a][b]) << endl;
    }

    return 0;
}
