#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool isCyclic(int n, vector<int> adjLS[]) {
    vector<int> indegree(n,0);

    for(int i=0; i<n; i++) {
        for(auto it: adjLS[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indegree[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it: adjLS[node]) {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    if(cnt==n) {
        return false;
    }
    return true;

    // TC -> O(N+E) (bfs traversal of directed graph)
    // SC -> O(N) (indegree) + O(N) (worst case for queue)
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

    // To detect a cycle in a directed graph using BFS, we applay Kahn's Algorithm topo sort logic. We know that Topo Sort is only applicable for DAG, so if the graph does have a cycle TopoSort will not work as the queue will get empty before it traverses the entire graph. This will therefore generate a topologically sorted array whose size is lesser than the number of nodes, thus telling that a cycle is present.

    int n,m;
    cin >> n >> m;
    vector<int> adjLS[n];

    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adjLS[u].push_back(v);
    }

    if(isCyclic(n,adjLS)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}
