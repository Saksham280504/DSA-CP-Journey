#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
const int LOG = 30;
vector<vector<int>> BinaryLifting;

void build(const vector<int>& teleporter) {
    int n = teleporter.size();
    BinaryLifting.resize(LOG,vector<int>(n));
    for(int j=0; j<n; j++) {
        BinaryLifting[0][j] = teleporter[j];
    }

    for(int i=1; i<LOG; i++) {
        for(int j=0; j<n; j++) {
            BinaryLifting[i][j] = BinaryLifting[i-1][BinaryLifting[i-1][j]];
        }
    }
}

int query(int start, int jumps) {
    int curr = start;
    for(int i=0; i<LOG; i++) {
        if(jumps&(1<<i)) {
            curr = BinaryLifting[i][curr];
        }
    }
    return curr;
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

    int n,q;
    cin >> n >> q;
    vector<int> teleporter(n);
    for(int i=0; i<n; i++) {
        cin >> teleporter[i];
        teleporter[i]--;
    }
    build(teleporter);
    while(q--) {
        int x,k;
        cin >> x >> k;
        x--;
        cout << query(x,k)+1 << endl;
    }

    return 0;
}
