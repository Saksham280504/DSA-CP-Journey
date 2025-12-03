#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> topoSort(int n, vector<int> adjLS[]) {
    vector<int> indegree(n,0);
    queue<int> q;

    for(int i=0; i<n; i++) {
        for(auto it: adjLS[i]) {
            indegree[it]++;
        }
    }
    
    for(int i=0; i<n; i++) {
        if(indegree[i]==0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        // Node is in your TopoSort, so please remove it from your indegree
        for(auto it: adjLS[node]) {
            indegree[it]--;
            if(indegree[it]==0) q.push(it); // We are just pushing those items into the queue which have their indegree=0 that means that 
        }
    }

    return topo;
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
    vector<int> adjLS[n];

    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adjLS[u].push_back(v);
    }

    vector<int> ans = topoSort(n,adjLS);

    for(auto x: ans) cout << x << " ";
    cout << endl;

    return 0;
}
