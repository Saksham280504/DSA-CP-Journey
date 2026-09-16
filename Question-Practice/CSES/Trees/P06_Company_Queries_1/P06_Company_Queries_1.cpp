#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n,q;
    int MAX_JUMP = 20;
    cin >> n >> q;
    vector<vector<int>> BinaryLift(n+1,vector<int>(MAX_JUMP,0));
    for(int i=2; i<=n; i++) {
        cin >> BinaryLift[i][0];
    }
    // Since the order of nodes in tree was topologically sorted, so we could just iteratively find out the Binary Jumps for each node
    for(int j=1; j<MAX_JUMP; j++) {
        for(int i=1; i<=n; i++) {
            BinaryLift[i][j] = BinaryLift[BinaryLift[i][j-1]][j-1];
        }
    }

    while(q--) {
        int node, k;
        cin >> node >> k;
        for(int bit=MAX_JUMP-1; bit>=0; bit--) {
            if(k&(1<<bit)) {
                node = BinaryLift[node][bit];
                if(node==0) break;
            }
        }
        cout << (node == 0 ? -1: node) << endl;
    }

    return 0;
}
