#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

struct FenwickTree {
    int n;
    vector<vector<int>> tree;
    FenwickTree(int n) {
        this->n = n;
        tree.assign(n+1,vector<int>(n+1,0));
    }
    void add(int r, int c, int delta) {
        for(int i=r; i<=n; i += (i & (-i))) {
            for(int j=c; j<=n; j += (j & (-j))) {
                tree[i][j] += delta;
            }
        }
    }
    int preSum(int r, int c) {
        int sum = 0;
        for(int i=r; i>0; i -= (i & (-i))) {
            for(int j=c; j>0; j -= (j & (-j))) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    int query_sub_rect(int y1, int x1, int y2, int x2) {
        return preSum(y2,x2) - preSum(y1-1,x2) - preSum(y2,x1-1) + preSum(y1-1,x1-1);
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
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];

    FenwickTree ft(n);
    vector<vector<int>> state(n+1,vector<int>(n+1,0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int delta = grid[i-1][j-1]=='*' ? 1 : 0;
            if(delta>0) ft.add(i,j,delta);
            state[i][j] = delta;
        }
    }

    while(q--) {
        int type;
        cin >> type;
        if(type==1) {
            int y,x;
            cin >> y >> x;
            int delta = state[y][x]==1? -1: 1;
            state[y][x] ^= 1;
            ft.add(y,x,delta);
        }
        else {
            int y1,x1,y2,x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << ft.query_sub_rect(y1,x1,y2,x2) << endl;
        }
    }

    return 0;
}
