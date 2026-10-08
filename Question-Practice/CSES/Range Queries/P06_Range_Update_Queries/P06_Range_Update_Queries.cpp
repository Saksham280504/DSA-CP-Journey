#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct FenwickTree {
    int n;
    vector<ll> tree;
    FenwickTree(int n) {
        this->n = n;
        tree.assign(n+1,0);
    }
    void update(int i, ll u) {
        for(int j=i; j<=n; j += (j & (-j))) {
            tree[j] += u;
        }
    }

    ll preSum(int i) {
        ll sum = 0;
        for(int j=i; j>0; j -= (j & (-j))) {
            sum += tree[j];
        }
        return sum;
    }

    ll query(int k) {
        return preSum(k);
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
    FenwickTree ft(n);
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    while(q--) {
        int type;
        cin >> type; 
        if(type==1) {
            int a,b;
            ll u;
            cin >> a >> b >> u;
            ft.update(a,u);
            ft.update(b+1,-u);
        }
        else {
            int k;
            cin >> k;
            cout << ft.query(k) + a[k] << endl;
        }
    }

    return 0;
}
