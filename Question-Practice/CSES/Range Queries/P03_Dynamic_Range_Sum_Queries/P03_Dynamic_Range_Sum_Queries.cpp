#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct FenwickTree {
    int n;
    vector<ll> tree;
    public:
    FenwickTree(vector<ll>& a) {
        n = a.size()-1;
        tree.assign(n+1,0);
        for(int i=1; i<=n; i++) {
            tree[i] += a[i];
            int parent = i + (i & (-i));
            if(parent<=n) tree[parent] += tree[i];
        }
        // Now your tree is ready where tree[i] -> sum of all the elements of the window ending at index i, having size = smallest set bit of index i
    }

    void add(int i, ll delta) {
        for(int j=i; j<=n; j += (j & (-j))) {
            tree[j] += delta;
        }
    }

    ll preSum(int i) {
        ll sum = 0;
        for(int j=i; j>0; j -= (j & (-j))) {
            sum += tree[j];
        }
        return sum;
    }

    ll query(int l, int r) {
        if(l>r) return 0;
        return preSum(r)-preSum(l-1);
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
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    FenwickTree ft(a);
    while(q--) {
        int type;
        cin >> type;
        if(type==1) {
            int k;
            ll u;
            cin >> k >> u;
            ll delta = u - a[k];
            a[k] = u;
            ft.add(k,delta);
        }
        else {
            int a,b;
            cin >> a >> b;
            cout << ft.query(a,b) << endl;
        }
    }

    return 0;
}
