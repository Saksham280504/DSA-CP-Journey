#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long 
ll NINF = -1e18;

struct SegmentTree {
    int n;
    vector<ll> tree;
    public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4*n+1,NINF);
    }
    void build_tree(vector<ll>& a, int node, int L, int R) {
        if(L==R) {
            tree[node] = a[L];
            return;
        }
        int mid = L + (R-L)/2;
        build_tree(a,2*node,L,mid);
        build_tree(a,2*node+1,mid+1,R);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
    ll allocate(int node, int L, int R, ll r) {
        if(L==R) {
            tree[node] -= r;
            return L;
        }
        int allocate_idx;
        int mid = L + (R-L)/2;
        if(r<=tree[2*node]) {
            allocate_idx = allocate(2*node,L,mid,r);
        }
        else {
            allocate_idx = allocate(2*node+1,mid+1,R,r);
        }
        tree[node] = max(tree[2*node],tree[2*node+1]);
        return allocate_idx;
    }

    void build(vector<ll>& a) {
        build_tree(a,1,1,n);
    }
    ll query(ll r) {
        if(tree[1]<r) return 0;
        return allocate(1,1,n,r);
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
    int n,m;
    cin >> n >> m;
    SegmentTree sg(n);
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    sg.build(a);

    while(m--) {
        ll r;
        cin >> r;
        cout << sg.query(r) << " ";
    }
    cout << endl;

    return 0;
}
