#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

struct ForestTrees {
    int n;
    vector<vector<int>> preSum;
    public:
    ForestTrees(int n) {
        this->n = n;
        preSum.assign(n+1,vector<int>(n+1,0)); // 0th row and 0th col edge-case handled
    }

    void build(vector<string>& grid) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int val = (grid[i-1][j-1]=='*' ? 1 : 0);
                preSum[i][j] = preSum[i][j-1] + preSum[i-1][j] - preSum[i-1][j-1] + val;
            }
        }
    }

    int query(int r1, int c1, int r2, int c2) {
        return preSum[r2][c2] - preSum[r1-1][c2] - preSum[r2][c1-1] + preSum[r1-1][c1-1];
    }
};

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
    cin >> n >> q;
    ForestTrees forest(n);

    vector<string> grid(n);
    for(int i=0; i<n; i++) {
        cin >> grid[i];
    }

    forest.build(grid);

    while(q--) {
        int y1,x1,y2,x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << forest.query(y1,x1,y2,x2) << endl;
    }

    return 0;
}
