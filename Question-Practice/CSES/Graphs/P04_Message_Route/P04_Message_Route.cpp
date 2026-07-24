#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

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
    vector<int> adjLS[n+1];
    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }
    vector<bool> vis(n+1,false);
    vector<int> parent(n+1,-1);
    queue<int> q;
    vis[1] = true;
    q.push(1);
    bool found = false;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int adj: adjLS[node]) {
            if(!vis[adj]) {
                vis[adj] = true;
                q.push(adj);
                parent[adj] = node;
                if(adj==n) {
                    found = true;
                    break;
                }
            }
        }
    }

    if(!found) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int current = n;
    vector<int> path;
    while(current!=-1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for(int comp: path) cout << comp << " ";
    cout << endl;

    return 0;
}
