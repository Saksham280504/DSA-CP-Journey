#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

const int MAX = 2e5+2;
vector<int> children[MAX];
vector<int> subtree(MAX,0);

void dfs(int node) {
    for(auto child: children[node]) {
        dfs(child);
        subtree[node] += subtree[child];
    }
    subtree[node] += 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Subordinates of i stand for the number of employees under i => subtree[i]-1 (itself)

    int n;
    cin >> n;
    for(int i=2; i<=n; i++) {
        int p;
        cin >> p;
        children[p].push_back(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++) {
        cout << (subtree[i]-1) << " ";
    }
    cout << endl;

    return 0;
}
