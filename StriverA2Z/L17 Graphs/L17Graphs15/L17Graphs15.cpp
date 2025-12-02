#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void bfs(int node,vector<int>& vis, vector<int> adjLS[]) {
  queue<int> q;
  vis[node] = 1;
  q.push(node);
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    for(auto it: adjLS[node]) {
      if(!vis[it]) {
        vis[it] = 1;
        q.push(it);
      }
    }
  }
}
int findNumberOfComponent(int n,int m, vector<vector<int>> &edges) {
      vector<int> adjLS[n];

      for(int i=0; i<m; i++) {
        adjLS[edges[i][0]].push_back(edges[i][1]);
        adjLS[edges[i][1]].push_back(edges[i][0]);
      }

      vector<int> vis(n,0);
      int cnt = 0;
      for(int i=0; i<n; i++) {
        if(!vis[i]) {
          cnt++;
          bfs(i,vis,adjLS);
        }
      }
      return cnt;  
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

    // This is the module number 2 of the problem on BFS/DFS section, video is not given for this problem but the question is simple so I solved it. I have verified it with ChatGPT

    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges;

    for(int i=0; i<m; i++) {
        vector<int> arr(2);
        for(int j=0; j<2; j++) {
            cin >> arr[j];
        }
        edges.push_back(arr);
    }

    int cnt = findNumberOfComponent(n,m,edges);
    cout << cnt << endl;


    return 0;
}
