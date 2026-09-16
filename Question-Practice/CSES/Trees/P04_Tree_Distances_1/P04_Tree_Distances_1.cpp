#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int n;
vector<vector<int>> adjLS;
vector<int> maxd1, maxd2,c;

// First we try to explore the options where we believe the answer lies within the subtree of a node
void dfs1(int u, int p) {
    for(int v: adjLS[u]) {
        if(v==p) continue;
        dfs1(v,u);
        if(maxd1[v]+1>maxd1[u]) {
            maxd2[u] = maxd1[u];
            maxd1[u] = maxd1[v]+1;
            c[u] = v;
        }
        else maxd2[u] = max(maxd2[u],maxd1[v]+1);
    }
}

// Now we are trying to explore the opportunities where the answer may lie outside the subtree of a node
void dfs2(int u, int p) {
    for(int v: adjLS[u]) {
        if(v==p) continue;
        if(c[u]==v) {
            if(maxd2[u]+1>maxd1[v]) {
                maxd2[v] = maxd1[v];
                maxd1[v] = maxd2[u]+1;
                c[v]=u;
            }
            else maxd2[v] = max(maxd2[v],maxd2[u]+1);
        }
        else {
            maxd2[v] = maxd1[v];
            maxd1[v] = maxd1[u]+1;
            c[v]=u;
        }
        dfs2(v,u);
    }
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

    // Brute-Force Approach -> Run dfs for each node to find the largest distant node.
    // TC -> N*O(N) -> O(N^2) -> TLE

    // Rerooting DP -> Either the answer lies in the subtree of the node, or it lies on the outside of the subtree of the node.
    cin >> n;
    adjLS.resize(n+1); // adjacency List
    maxd1.assign(n+1,0); // Tracks the maximum distance of every node to any other node
    maxd2.assign(n+1,0); // Tracks the 2nd maximum distance of every node to any other node
    c.resize(n+1); // Tracks the neighbour from which the maximum distance path comes

    for(int i=0; i<(n-1); i++) {
        int a,b;
        cin >> a >> b;
        adjLS[a].push_back(b);
        adjLS[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0);

    for(int i=1; i<=n; i++) cout << maxd1[i] << " ";
    cout << endl;

    return 0;
}
