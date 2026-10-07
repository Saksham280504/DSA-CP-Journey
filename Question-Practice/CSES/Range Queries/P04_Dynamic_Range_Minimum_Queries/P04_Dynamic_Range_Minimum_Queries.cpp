#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
ll INF = 1e18;

struct SegmentTree {
    int n;
    vector<ll> tree;
    public:
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4*n+1,INF);
    }
    
    void build_tree(vector<ll>& a, int node, int L, int R) {
        if(L==R) {
            tree[node] = a[L];
            return;
        }
        int mid = L + (R-L)/2;
        build_tree(a,2*node,L,mid);
        build_tree(a,2*node+1,mid+1,R);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }

    void update_tree(int node, int L, int R, int pos, ll val) {
        if(L==R) {
            tree[node] = val;
            return;
        }
        int mid = L + (R-L)/2;
        if(pos<=mid) {
            update_tree(2*node,L,mid,pos,val);
        }
        else update_tree(2*node+1,mid+1,R,pos,val);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }

    ll query_min(int node, int L, int R, int qL, int qR) {
        // Case - 1: No Overlap
        if(qL>R || qR<L) {
            return INF;
        }
        // Case - 2: [qL....[L...R]....qR] -> Fully within range
        if(qL<=L && R<=qR) {
            return tree[node];
        }
        // Case - 3: Partial Overlap [L....[qL...R]....qR] or [L....[qL...qR]....R]
        int mid = L + (R-L)/2;
        ll left_min = query_min(2*node,L,mid,qL,qR);
        ll right_min = query_min(2*node+1,mid+1,R,qL,qR);
        return min(left_min,right_min);
    }
    void build(vector<ll>& a) {
        build_tree(a,1,1,n);
    }
    void update(int pos, ll val) {
        update_tree(1,1,n,pos,val);
    }
    ll query(int qL, int qR) {
        return query_min(1,1,n,qL,qR);
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
    SegmentTree sg(n);
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    sg.build(a);

    while(q--) {
        int type;
        cin >> type;
        if(type==1) {
            int k;
            ll u;
            cin >> k >> u;
            sg.update(k,u);
        }
        else {
            int a,b;
            cin >> a >> b;
            cout << sg.query(a,b) << endl;
        }
    }

    return 0;
}
