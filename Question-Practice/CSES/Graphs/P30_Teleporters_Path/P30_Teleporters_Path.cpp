#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<vector<pair<int,int>>> adjLS;
vector<int> indeg, outdeg;
vector<bool> seen;
vector<int> path;

void dfs(int u) {
    while(!adjLS[u].empty()) {
        auto edge = adjLS[u].back();
        adjLS[u].pop_back();
        if(seen[edge.second]) continue;
        seen[edge.second] = true;
        dfs(edge.first);
    }
    path.push_back(u);
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
    adjLS.resize(n+1);
    indeg.assign(n+1,0);
    outdeg.assign(n+1,0);
    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back({b,i});
        outdeg[a]++;
        indeg[b]++;
    }
    if(outdeg[1]-indeg[1]!=1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } 
    if(indeg[n]-outdeg[n]!=1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } 
    for(int i=2; i<n; i++) {
        if(outdeg[i]!=indeg[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;   
        }
    }

    seen.assign(m,false);
    path.clear();
    dfs(1);
    if(path.size()!=m+1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int i=path.size()-1; i>=0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
