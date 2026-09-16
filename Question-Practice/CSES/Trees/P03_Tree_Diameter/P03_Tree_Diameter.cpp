#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Youtube Channel -> Yash Poonia
int n;
vector<vector<int>> adjLS;

// Intuitive Approach
pair<int,int> dfs(int node, int parent, int dist) {
    pair<int,int> res = {dist,node};
    for(int nxt: adjLS[node]) {
        if(nxt==parent) continue;
        res = max(res,dfs(nxt,node,dist+1));
    }
    return res;
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
    cin >> n;
    adjLS.resize(n+1);
    for(int i=0; i<(n-1); i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }

    // Brute Force Approach -> Maintain maxDia variable (initialized as INT_MIN), appply DFS/BFS for every node and find the node present at the greatest distance from it, and update maxDia accordingly.
    // TC -> n*O(n) -> O(n^2) -> TLE

    // Better Approach -> We know that for maximum diameter, it will always be between two leaf nodes. So find the leaf node which is at the greatest distance from 1, then from that node, find the leaf node which is at the greatest distance from it, that will be our Tree Diameter.
    // TC -> O(2*N)
    auto far1 = dfs(1,0,0);
    auto far2 = dfs(far1.second,0,0);
    cout << far2.first << endl;

    // Optimal Approach -> We will use Dynamic Programming.
    // TC -> O(N)

    return 0;
}
