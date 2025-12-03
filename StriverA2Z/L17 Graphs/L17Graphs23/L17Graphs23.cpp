#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool canFinish(int n, vector<vector<int>>& prerequisites) {
    int m = prerequisites.size();
    vector<int> adjLS[n];

    for(int i=0; i<m; i++) {
        adjLS[prerequisites[i][1]].push_back(prerequisites[i][0]);
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
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it: adjLS[node]) {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    if(cnt==n) return true; // There is no cycle in the graph, thus all the courses can be covered
    return false;

    // TC -> O(N+E) (for BFS traversal of directed graph)
    // SC -> O(N) (indegree) + O(N) (worst case of queue)
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
    vector<vector<int>> prerequisites;

    for(int i=0; i<m; i++) {
        vector<int> arr(2);
        for(int j=0; j<2; j++) {
            cin >> arr[i];
        }
        prerequisites.push_back(arr);
    }

    // To cover all the courses, the topological sort must work. For the topo sort to work, the graph must be DAG.

    if(canFinish(n, prerequisites)) {
        cout << "true" << endl;
    }
    else cout << "false" << endl;
    return 0;
}
