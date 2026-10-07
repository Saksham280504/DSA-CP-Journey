#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int MAX_LOG = 20;

struct BinaryLifting {
    private:
    vector<vector<int>> bl;
    public:
    BinaryLifting(int n, vector<int>& parent) {
        bl.assign(MAX_LOG,vector<int>(n+1,0));
        bl[0][0] = 0;
        bl[0][1] = 0;
        for(int i=2; i<=n; i++) bl[0][i] = parent[i];
        for(int k=1; k<MAX_LOG; k++) {
            for(int i=1; i<=n; i++) {
                bl[k][i] = bl[k-1][bl[k-1][i]];
            }
        }
    }

    int get_kth_ancestor(int u, int k) {
        for(int i=0; i<MAX_LOG; i++) {
            if(k&(1<<i)) u = bl[i][u];
            if(u==0) return -1;
        }
        return (u==0 ? -1 : u);
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
    vector<int> parent(n+1);
    for(int i=2; i<=n; i++) {
        cin >> parent[i];
    }

    BinaryLifting bs(n,parent);

    while(q--) {
        int x,k;
        cin >> x >> k;
        cout << bs.get_kth_ancestor(x,k) << endl;
    }

    return 0;
}
