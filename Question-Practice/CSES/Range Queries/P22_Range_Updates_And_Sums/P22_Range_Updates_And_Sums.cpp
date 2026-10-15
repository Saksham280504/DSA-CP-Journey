#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct LazySegmentTree {
    private:
    int n;
    vector<ll> tree;
    vector<bool> has_set;
    vector<ll> set_val;
    vector<ll> add_val;
    public:
    LazySegmentTree(int n) {
        this->n = n;
        tree.assign(4*n+1,0);
        has_set.assign(4*n+1,false);
        set_val.assign(4*n+1,0);
        add_val.assign(4*n+1,0);
    }
    // Core Lazy Segment Tree Functions -> apply_set, apply_add, push_down
    void apply_set(int node, int L, int R, ll val) {
        tree[node] = val*(R-L+1);
        has_set[node] = true;
        set_val[node] = val;
        add_val[node] = 0;
    }
    void apply_add(int node, int L, int R, ll val) {
        tree[node] += val*(R-L+1);
        if(has_set[node]) set_val[node] += val;
        else add_val[node] += val;
    }
    void push_down(int node, int L, int R) {
        int mid = L + (R-L)/2;
        if(has_set[node]) {
            apply_set(2*node,L,mid,set_val[node]);
            apply_set(2*node+1,mid+1,R,set_val[node]);
            has_set[node] = false;
        }
        if(add_val[node]) {
            apply_add(2*node,L,mid,add_val[node]);
            apply_add(2*node+1,mid+1,R,add_val[node]);
            add_val[node] = 0;
        }
    }
    // Build functions
    void build(vector<ll>& a, int node, int L, int R) {
        if(L==R) {
            tree[node] = a[L];
            return;
        }
        int mid = L + (R-L)/2;
        build(a,2*node,L,mid);
        build(a,2*node+1,mid+1,R);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    void build(vector<ll>& a) {
        build(a,1,1,n);
    };
    // Range add functions
    void range_add(int node, int L, int R, int qL, int qR, ll val) {
        // Case-1: No overlap [qL...qR] [L....R]
        if(qR<L || qL>R) return;
        // Case-2: Full overlap [qL...[L...R]...qR]
        if(qL<=L && R<=qR) {
            apply_add(node,L,R,val);
            return;
        }
        // Case-3: Otherwise (Partial Overlap) // [qL...[L...qR]...R] or [L....[qL.....R]....R]
        push_down(node,L,R);
        int mid = L + (R-L)/2;
        range_add(2*node,L,mid,qL,qR,val);
        range_add(2*node+1,mid+1,R,qL,qR,val);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
    void range_add(int qL, int qR, ll val) {
        range_add(1,1,n,qL,qR,val);
    };
    // Range set functions
    void range_set(int node, int L, int R, int qL, int qR, ll val) {
        if(qL>R || qR<L) return;
        if(qL<= L && R<=qR) {
            apply_set(node,L,R,val);
            return;
        }
        push_down(node,L,R);
        int mid = L + (R-L)/2;
        range_set(2*node,L,mid,qL,qR,val);
        range_set(2*node+1,mid+1,R,qL,qR,val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    void range_set(int qL, int qR, ll val) {
        range_set(1,1,n,qL,qR,val);
    };
    // Range sum functions
    ll range_sum(int node, int L, int R, int qL, int qR) {
        if(qR<L || qL>R) return 0;
        if(qL<=L && R<=qR) return tree[node];
        push_down(node,L,R);
        int mid = L + (R-L)/2;
        ll left_sum = range_sum(2*node,L,mid,qL,qR);
        ll right_sum = range_sum(2*node+1,mid+1,R,qL,qR);
        return left_sum + right_sum;
    }
    ll range_sum(int qL, int qR) {
        return range_sum(1,1,n,qL,qR);
    };
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
    LazySegmentTree lst(n);
    lst.build(a);
    while(q--) {
        int type;
        cin >> type;
        if(type==1) {
            int a,b;
            ll x;
            cin >> a >> b >> x;
            lst.range_add(a,b,x);
        }
        else if(type==2) {
            int a,b;
            ll x;
            cin >> a >> b >> x;
            lst.range_set(a,b,x);
        }
        else {
            int a,b;
            cin >> a >> b;
            cout << lst.range_sum(a,b) << endl;
        }
    }

    return 0;
}
