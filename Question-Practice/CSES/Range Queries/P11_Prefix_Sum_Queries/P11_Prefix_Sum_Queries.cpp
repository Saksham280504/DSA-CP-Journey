#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct Node {
    ll sum; // Total sum of the segment
    ll pref; // maximum prefix sum within the segment (>=0)
    Node() {
        sum = 0;
        pref = 0;
    }
    Node(ll sum, ll pref) {
        this->sum = sum;
        this->pref = pref;
    }
};

Node merge(Node& left, Node& right) {
    Node res;
    res.sum = left.sum + right.sum;
    res.pref = max(left.pref,left.sum+right.pref);
    return res;
}

struct SegmentTree {
    int n;
    vector<Node> tree;
    public:
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4*n+1);
    }
    void build_tree(vector<ll>& a, int node, int L, int R) {
        if(L==R) {
            tree[node] = Node(a[L],max(0LL,a[L]));
            return;
        }
        int mid = L + (R-L)/2;
        build_tree(a,2*node,L,mid);
        build_tree(a,2*node+1,mid+1,R);
        tree[node] = merge(tree[2*node],tree[2*node+1]);
    }
    void update_tree(int node, int L, int R, int pos, ll val) {
        if(L==R) {
            tree[node] = Node(val,max(0LL,val));
            return;
        }
        int mid = L + (R-L)/2;
        if(pos<=mid) update_tree(2*node,L,mid,pos,val);
        else update_tree(2*node+1,mid+1,R,pos,val);
        tree[node] = merge(tree[2*node],tree[2*node+1]);
    }
    Node query_max_pref(int node, int L, int R, int qL, int qR) {
        // case - 1: No overlap
        if(qL>R || qR<L) return Node(0LL,0LL);
        // case - 2: Fully Contained
        if(qL<=L && R<=qR) return tree[node];
        // case - 3: Otherwise
        int mid = L + (R-L)/2;
        Node left = query_max_pref(2*node,L,mid,qL,qR);
        Node right = query_max_pref(2*node+1,mid+1,R,qL,qR);
        return merge(left,right);
    }
    void build(vector<ll>& a) {
        build_tree(a,1,1,n);
    }
    void update(int pos, ll val) {
        update_tree(1,1,n,pos,val);
    }
    ll query(int qL, int qR) {
        return query_max_pref(1,1,n,qL,qR).pref;
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
    SegmentTree seg(n);
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    seg.build(a);

    while(q--) {
        int type;
        cin >> type;
        if(type==1) {
            int k;
            ll val;
            cin >> k >> val;
            seg.update(k,val);
        }
        else {
            int qL,qR;
            cin >> qL >> qR;
            cout << seg.query(qL,qR) << endl;
        }
    }

    return 0;
}
