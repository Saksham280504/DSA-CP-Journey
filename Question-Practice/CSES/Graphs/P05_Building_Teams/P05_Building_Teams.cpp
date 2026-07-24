#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> team;
vector<vector<int>> adjLS;

bool bfs(int start) {
    team[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto adj: adjLS[node]) {
            if(team[adj]==-1) {
                team[adj] = 3-team[node]; // 1->2 || 2->1
                q.push(adj);
            }
            else if(team[adj]==team[node]) {
                return false; // Odd cyclic graph is present -> can never be bipartite
            }
        }
    }
    return true;
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
    team.assign(n+1,-1); 
    adjLS.resize(n+1);

    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        if(team[i]==-1) {
            if(!bfs(i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(int i=1; i<=n; i++) cout << team[i] << " ";
    cout << endl;

    return 0;
}
