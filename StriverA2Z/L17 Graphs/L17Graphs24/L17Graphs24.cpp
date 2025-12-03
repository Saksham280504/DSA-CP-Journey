#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> findOrder(int n, vector<vector<int>>& grid) {
    int m = grid.size();
    vector<int> adjLS[n];
    for(int i=0; i<m; i++) {
        adjLS[grid[i][1]].push_back(grid[i][0]);
    }

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
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        cnt++;
        for(auto it: adjLS[node]) {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    if(cnt==n)return topo;
    topo.clear();
    return topo;

    // TC -> O(N+E) (bfs traversal)
    // SC -> O(2N) (indegree,topo) + O(N) (worst case for queue)
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
    vector<vector<int>> grid;

    for(int i=0; i<m; i++) {
        vector<int> arr(2);
        for(int j=0; j<2; j++) {
            cin >> arr[i];
        }
        grid.push_back(arr);
    }

    vector<int> ans = findOrder(n,grid);

    for(auto x: ans) cout << x << " ";
    cout << endl;
    return 0;
}
