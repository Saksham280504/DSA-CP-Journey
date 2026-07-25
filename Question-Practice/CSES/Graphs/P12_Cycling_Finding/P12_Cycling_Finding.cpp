#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long 
typedef tuple<int,int,ll> Edge;

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
    vector<ll> dist(n+1,0);
    vector<Edge> edges(m);

    for(int i=0; i<m; i++) {
        int u,v;
        ll wt;
        cin >> u >> v >> wt;
        edges[i] = {u,v,wt};
    }

    int x = -1;
    vector<int> relaxant(n+1,-1);
    for(int i=0; i<n; i++) {
        x = -1;
        for(auto [u,v,wt]: edges) {
            if(dist[v]>dist[u]+wt) {
                dist[v] = dist[u] + wt;
                relaxant[v] = u;
                x = v;
            }
        }
    }

    if(x==-1) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i=0; i<n; i++) {
        x = relaxant[x];
    }

    vector<int> cycle;
    for(int curr=x;; curr=relaxant[curr]) {
        cycle.push_back(curr);
        if(curr==x && cycle.size()>1) break;
    }
    reverse(cycle.begin(), cycle.end());
    cout << "YES" << endl;
    for(int x: cycle) cout << x << " ";
    cout << endl;

    return 0;
}
