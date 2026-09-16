#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int n;
vector<int> subTree;
vector<vector<int>> adjLS;

void  dfs(int node) {
    for(int v: adjLS[node]) {
        dfs(v);
        subTree[node] += subTree[v];
    }
    subTree[node] += 1;
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
    subTree.assign(n+1,0);
    adjLS.resize(n+1);
    for(int i=2; i<=n; i++) {
        int parent;
        cin >> parent;
        adjLS[parent].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n; i++) cout << (subTree[i]-1) << " ";
    cout << endl;

    return 0;
}
