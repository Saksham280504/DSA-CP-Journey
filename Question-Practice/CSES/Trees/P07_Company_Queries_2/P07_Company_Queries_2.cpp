#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int n,q;
int MAX_BIT = 20;
vector<vector<int>> BinaryLift;
vector<int> depth;

int find_lca(int u, int v) {
    if(depth[u]<depth[v]) swap(u,v); // We always want depth[u] >= depth[v]
    int diff = depth[u]-depth[v];
    for(int i=MAX_BIT-1; i>=0; i--) {// Make the depth of both u,v equal
        if(diff&(1<<i)) u = BinaryLift[u][i];
    }
    if(u==v) return u; // u,v belong to same branch
    for(int i=MAX_BIT-1; i>=0; i--) {
        if(BinaryLift[u][i]!=BinaryLift[v][i]) {
            u = BinaryLift[u][i];
            v = BinaryLift[v][i];
        }
    }
    return BinaryLift[u][0];
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
    cin >> n >> q;
    BinaryLift.assign(n+1,vector<int>(MAX_BIT,0));
    depth.assign(n+1,0);
    for(int i=2; i<=n; i++) {
        int boss;
        cin >> boss;
        BinaryLift[i][0] = boss;
        depth[i] = depth[boss]+1;
    }
    for(int j=1; j<MAX_BIT; j++) {
        for(int i=1; i<=n; i++) {
            BinaryLift[i][j] = BinaryLift[BinaryLift[i][j-1]][j-1];
        }
    }

    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << find_lca(a,b) << endl;
    }

    return 0;
}
